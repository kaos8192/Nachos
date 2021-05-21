// exception.cc 
//	Entry point into the Nachos kernel from user programs.
//	There are two kinds of things that can cause control to
//	transfer back to here from user code:
//
//	syscall -- The user code explicitly requests to call a procedure
//	in the Nachos kernel.  Right now, the only function we support is
//	"Halt".
//
//	exceptions -- The user code does something that the CPU can't handle.
//	For instance, accessing memory that doesn't exist, arithmetic errors,
//	etc.  
//
//	Interrupts (which can also cause control to transfer from user
//	code into the Nachos kernel) are handled elsewhere.
//
// For now, this only handles the Halt() system call.
// Everything else core dumps.
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "system.h"
#include "syscall.h"
#include "synchconsole.h"
#include "machine.h"
#include "ipt.h"
#include "swaptable.h"
#include "bitmap.h"

//----------------------------------------------------------------------
// ExceptionHandler
// 	Entry point into the Nachos kernel.  Called when a user program
//	is executing, and either does a syscall, or generates an addressing
//	or arithmetic exception.
//
// 	For system calls, the following is the calling convention:
//
// 	system call code -- r2
//		arg1 -- r4
//		arg2 -- r5
//		arg3 -- r6
//		arg4 -- r7
//
//	The result of the system call, if any, must be put back into r2. 
//
// And don't forget to increment the pc before returning. (Or else you'll
// loop making the same system call forever!
//
//	"which" is the kind of exception.  The list of possible exceptions 
//	are in machine.h.
//----------------------------------------------------------------------
/*TODO Clock
 * [✓] an int hand
 * [] a hand that works
 *      [] hand moves
 *      [] hand doesn't move on use
 *      [] uses the dirty/use bit correctly
 */

static int entry = 0;

//Clock hand, init to zero MAYBE?
int hand = 0;

HashTable ipt;
SwapTable swaptable;


void ExitF(int);
void CloseF(int);

    void
ExceptionHandler(ExceptionType which)
{
    // read registers and cast inside if statements
    int type = machine->ReadRegister(2);

    // probably need different types OR do them inside the if...
    int arg1 = machine->ReadRegister(4); // reg4
    int arg2 = machine->ReadRegister(5); // reg5
    int arg3 = machine->ReadRegister(6); // reg6
    int arg4 = machine->ReadRegister(7); // reg7; not actually used for Lab 3
    

    if ((which == SyscallException) && (type == SC_Halt)) {
        DEBUG('a', "Shutdown, initiated by user program.\n");
        interrupt->Halt();
    }
    else if ((which == SyscallException) && (type == SC_Exit)) {
        ExitF(arg1);
    }
    else if ((which == SyscallException) && (type == SC_Exec)) {
        int execr = Exec((char*) arg1);
        machine->WriteRegister(2, execr);
    }
    else if ((which == SyscallException) && (type == SC_Join)) {
        int joiner = Join(arg1);
        machine->WriteRegister(2, joiner);
    }
    else if ((which == SyscallException) && (type == SC_Create)) {
        DEBUG('a', "Create, initiated by the user program.\n");
        Create((char*) arg1);
    }
    else if ((which == SyscallException) && (type == SC_Open)) {
        DEBUG('a', "Open, initiated by user program.\n");
        int fd = Open((char*) arg1);

        machine->WriteRegister(2, fd);
    }
    else if ((which == SyscallException) && (type == SC_Read)) {
        DEBUG('a', "Read, initiated by user program.\n");

        if((OpenFileId) arg3 == 0)
        {
            synConsole->cread((char*) arg1, (int) arg2);
        }
        else
        {
            int size = Read((char*) arg1, (int) arg2, (OpenFileId) arg3);
            machine->WriteRegister(2, size);
        }

    }
    else if ((which == SyscallException) && (type == SC_Write)) {
        DEBUG('a', "Write, initiated by user program.\n");
        if((OpenFileId) arg3 == 1)
        {
            synConsole->cwrite((char*) arg1, (int) arg2);
        }
        else
        {
            Write((char*) arg1, (int) arg2, (OpenFileId) arg3);
        }
    }
    else if ((which == SyscallException) && (type == SC_Close)) {
        DEBUG('a', "Close, initiated by user program.\n");
        CloseF((OpenFileId) arg1);

    }
    else if ((which == SyscallException) && (type == SC_Fork)) {

    }
    else if ((which == SyscallException) && (type == SC_Yield)) {
    DEBUG('a', "Yield called by user program. \n");
    }
    else if ((which == SyscallException) && (type == SC_AddArgument)) {
        AddArgument((char*)arg1);

    }
    else if ((which == SyscallException) && (type == SC_FetchArgument)) {
        FetchArgument((char*) arg1);
    }
    else if ((which == SyscallException) && (type == SC_MEMSTATS)) {
        // call memstats
        Memstats();
    }
    else if (which == PageFaultException) {
        
        // read from BadVAddReg
        int address = machine->ReadRegister(BadVAddrReg); 
        int pageNum = address/PageSize; 
        int frame = pageNum%NumPhysPages;
        //  find pid

        int pt = ipt.Find(pageNum, currentThread->pid);

        if (pt > 0) {
            // increment hits
            statsMutex->P();
            ++page_hits;
            statsMutex->V();
        } else {
            // increment faults
            statsMutex->P();
            ++page_faults;
            statsMutex->V();
        }

        // check if page containing the data is in the page table
        if (ipt.Find(pageNum, currentThread->pid) > 0) {
            // don't overwrite this-- do nothing!
        
        }
        else { 
            // if frame has something to swap out
            // check valid bits of items in the ipt
            while(ipt.hashes[hand].valid == TRUE and ipt.hashes[hand].use == TRUE)
            {
                ipt.hashes[hand].use = FALSE;
                ++hand%=NumPhysPages;
            }

            frame = hand;
            if (ipt.hashes[frame].valid == TRUE and ipt.hashes[frame].dirty == TRUE) {
                int pid_to_replace = ipt.pids[frame];
                int page_to_replace = ipt.hashes[frame].virtualPage;
                int block = swaptable.Find(page_to_replace, pid_to_replace);

                if (block >= 0){
                    // write to swapfile
                    swap->WriteAt(&machine->mainMemory[frame*PageSize], PageSize, block*PageSize);
                    
                } else { // put into freelist
                    // use mutex to protect swaplist
                    bitmapMutex->P();
                    block = swaplist->Find();
                    bitmapMutex->V();

                    ASSERT(block >= 0);
                    swap->WriteAt(&machine->mainMemory[frame*PageSize], PageSize, block*PageSize);
                    swaptable.hashes[block].virtualPage = pageNum;
                    swaptable.hashes[block].physicalPage = block;
                    swaptable.hashes[block].valid = TRUE;
                    swaptable.hashes[block].use = TRUE;
                    swaptable.hashes[block].dirty = TRUE;
                    swaptable.hashes[block].readOnly = FALSE;

                    swaptable.pids[block] = currentThread->pid;

                }

            }

            int paddr = frame*PageSize;
            if (swaptable.Find(pageNum, currentThread->pid) > 0) { 
            // check if in swap
            // kick something out of main memory,
            // read from swap,
            // move into place we emptied

            }
            else if (address >= currentThread->space->noffH.code.virtualAddr and address < (currentThread->space->noffH.code.virtualAddr + currentThread->space->noffH.code.size)) {
                currentThread->space->program->ReadAt(&machine->mainMemory[paddr], PageSize, currentThread->space->noffH.code.inFileAddr + pageNum*PageSize);
            } else if (address >= currentThread->space->noffH.initData.virtualAddr and address < (currentThread->space->noffH.initData.virtualAddr + currentThread->space->noffH.initData.size)) {
                currentThread->space->program->ReadAt(&machine->mainMemory[paddr], PageSize, currentThread->space->noffH.code.inFileAddr + pageNum*PageSize);
    
            } else if (address >= currentThread->space->noffH.uninitData.virtualAddr and address < (currentThread->space->noffH.uninitData.virtualAddr + currentThread->space->noffH.uninitData.size)) {
                bzero(&machine->mainMemory[paddr], PageSize);
    
            } else { // zero everything out
                bzero(&machine->mainMemory[paddr], PageSize);

            }
        }
        // update inverted page table
        ipt.Update(frame, pageNum, currentThread->pid);


        // update TLB 
        machine->tlb[entry].virtualPage = pageNum;
        machine->tlb[entry].physicalPage = frame;
        machine->tlb[entry].valid = TRUE;
        machine->tlb[entry].use = TRUE;
        machine->tlb[entry].dirty = TRUE;
        machine->tlb[entry].readOnly = FALSE;
        

        ++entry;
        entry %= TLBSize;
	
	/*	
            while(ipt.hashes[hand].valid == TRUE and ipt.hashes[hand].use == TRUE)
            {
                ipt.hashes[hand].use = FALSE;
                ++hand%=NumPhysPages;
            }

            frame = hand;
		// 
	int pageNumPre = 0;
	if(pageNum%2==0){
	  pageNumPre = pageNum+1; 
	  
	  ipt.Update(frame, pageNumPre, currentThread->pid);

	  machine->tlb[entry].virtualPage = pageNumPre;	  
          machine->tlb[entry].physicalPage = frame;
          machine->tlb[entry].valid = TRUE;
          machine->tlb[entry].use = TRUE;
          machine->tlb[entry].dirty = TRUE;
          machine->tlb[entry].readOnly = FALSE;
          
	  ++entry;
          entry %= TLBSize;
	}

	if(pageNum%2==1){
	  pageNumPre = pageNum-1; 
	  
	  ipt.Update(frame, pageNumPre, currentThread->pid);

	  machine->tlb[entry].virtualPage = pageNumPre;	  
          machine->tlb[entry].physicalPage = frame;
          machine->tlb[entry].valid = TRUE;
          machine->tlb[entry].use = TRUE;
          machine->tlb[entry].dirty = TRUE;
          machine->tlb[entry].readOnly = FALSE;
          
	  ++entry;
          entry %= TLBSize;
	}	

*/  //Prefetching attempt
    }

    else {
        printf("Unexpected user mode exception %d %d\n", which, type);
        ASSERT(FALSE);
    }
    
    int pc = machine->ReadRegister(PCReg);
    if (which == SyscallException ){
        pc += 4;
    }

    machine->WriteRegister(PCReg, pc);
}
