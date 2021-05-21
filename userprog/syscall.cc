#include "../filesys/filesys.h"
#include "../filesys/openfile.h"
#include "../machine/machine.h"
#include "../threads/system.h"
#include "../threads/thread.h"
#include "syscall.h"
#include "string.h"
#include "../userprog/synchconsole.h"

// for use with exec (with args)

void AddArgument(char* argument) {
    // memory stuff? (split into child function?)
    char argname[256];
    for (int i = 0; i < 256; ++i){
        int temp;
        // machine->ReadMem((int)argument+ i, 1, &temp); // int addr, int size, int* value

        bool result = machine->ReadMem((int)argument + i, 1, &temp); // int addr, int size, int* value
        if (not result){
            result = machine->ReadMem((int)argument + i, 1, &temp); // int addr, int size, int* value
        }
        ASSERT(result);

        argname[i] = (char) temp; 
        if (temp == 0)
            break;
    }

    // add argument to vector
    arglist.push_back(argname); //arglist is global in system.h

}


void FetchArgument(char* argument){
    // fetch from vector 
    char argname[256];
    // argname = arglist[arglist.size()-1];
    strncpy(arglist[arglist.size()-1], argname, 256);
    arglist.pop_back();

    for (int i = 0; i < 256; ++i){
        int temp;
        temp = (char) argname[i]; 
        argname[i] = (char) temp; 
        // machine->WriteMem((int)argument+i, 1, temp); // int addr, int size, int* value

        bool result = machine->WriteMem((int)argument + i, 1, temp); // int addr, int size, int* value
        if (not result){
            result = machine->WriteMem((int)argument + i, 1, temp); // int addr, int size, int* value
        }
        ASSERT(result);

        if (temp == 0)
            break;
    }
}



// System Calls (as listed from syscall.h)
void Create (char *name) { // THIS IS FINISHED DON'T CHANGE IT 
    // create a char array of large size
    char filename[256];
    // loop to size:
    for (int i = 0; i < 256; ++i){
        //      call machine->readmem  to get a character from "program memory"
        //      put character into array
        //      stop looping if 0 (null temrinator)
        int temp;
        bool result = machine->ReadMem((int)name + i, 1, &temp); // int addr, int size, int* value
        if (not result){
            result = machine->ReadMem((int)name + i, 1, &temp); // int addr, int size, int* value
        }
        ASSERT(result);

        filename[i] = (char) temp; 
        if (temp == 0)
            break;
    }

    // call fs->create
    fileSystem->Create(filename, 1000);

}

/* Open the Nachos file "name", and return an "OpenFileId" that can 
 * be used to read and write to the file. */
OpenFileId Open(char *name) {
    // weird nachos memory stuff
    char filename[256];
    for (int i = 0; i < 256; ++i){
        int temp;

        bool result = machine->ReadMem((int)name + i, 1, &temp); // int addr, int size, int* value
        if (not result){
            result = machine->ReadMem((int)name + i, 1, &temp); // int addr, int size, int* value
        }
        ASSERT(result);

        filename[i] = (char) temp; 
        if (temp == 0)
            break;
    }

    OpenFile* rv = fileSystem->Open(filename);
    // find open spot in currentThread->space->fileTable and add it there
    for (int i = 2; i < 256; ++i){ // start at 2 so we save 0 and 1 for cin and cout
        if (currentThread->space->fileTable[i] == NULL){ // if space is empty, set it to the space
            currentThread->space->fileTable[i] = rv;     // add to array in that spot
            return i;                                    // return space that the item was put into
        }
    }

    return -1; //something went wrong (couldn't put it int the array?)
}

/* Close the file, we're done reading and writing to it. */
// the name is slightly different, but thats ok-- it will still work!
void CloseF(OpenFileId id) {
    // find OpenFile at space id from the fileTable
    // check NULL before deleting? XXX
    // delete it
    delete currentThread->space->fileTable[id];

    // set space to NULL to reuse
    currentThread->space->fileTable[id] = NULL;
}

/* Write "size" bytes from "buffer" to the open file. */
void Write(char *buffer, int size, OpenFileId id) {
    if (id == 0){ // console input
        // undefined behavior, but DO NOT crash;
        // do nothing?

    } else if (id == 1){ // console outout

    } else if (id > 1){
        OpenFile* file = currentThread->space->fileTable[id];
        // protection if NULL?
        if (file != NULL) {
            // weird nachos memory stuff
            char data[256];
            for (int i = 0; i < size; ++i){
                int temp;
                // machine->ReadMem((int)buffer + i, 1, &temp); // int addr, int size, int* value

                bool result = machine->ReadMem((int)buffer + i, 1, &temp); // int addr, int size, int* value
                if (not result){
                    result = machine->ReadMem((int)buffer + i, 1, &temp); // int addr, int size, int* value
                }
                ASSERT(result);

                data[i] = (char) temp; 
            }
            file->Write(data, size);
        } else {
            ASSERT(false);
            // passed ID was null... crash?
        }
    } else { // id was negative? crash?
        ASSERT(false);

    }
}

/* Read "size" bytes from the open file into "buffer".  
 * Return the number of bytes actually read -- if the open file isn't
 * long enough, or if it is an I/O device, and there aren't enough 
 * characters to read, return whatever is available (for I/O devices, 
 * you should always wait until you can return at least one character). */
int Read(char *buffer, int size, OpenFileId id) {
    int readsize = 0;
    if (id == 0){ // console input 

    } else if (id == 1){ // conolse output
        // undefined behavior, but DO NOT crash;
        // do nothing?

    } else if (id > 1){

    } else if (id > 1){
        OpenFile* file = currentThread->space->fileTable[id];
        // protection if NULL?
        if (file != NULL) {
            // weird nachos memory stuff
            char data[256];
            readsize = file->Read(data, size);
            for (int i = 0; i < readsize; ++i){
                int temp = data[i]; 
                // machine->WriteMem((int)buffer + i, 1, temp); // int addr, int size, int* value

                bool result = machine->WriteMem((int)buffer + i, 1, temp); // int addr, int size, int* value
                if (not result){
                    result = machine->WriteMem((int)buffer + i, 1, temp); // int addr, int size, int* value
                }
                ASSERT(result);

            }
        } else {
            ASSERT(false);
            // passed ID was null... crash?
        }
    } else { // id was negative, crash?
        ASSERT(false);
    }
    return readsize;
}

// not defined in syscall.h, but needed for exec to fork
void ExecHelper(int id) {
    // essentially, set up the stack
    currentThread->space->InitRegisters();		// set the initial register values
    currentThread->space->RestoreState();		// load page table register

    machine->Run();

}

/* Run the executable, stored in the Nachos file "name", and return the 
 * address space identifier */
SpaceId Exec(char *name) {
    int rv = -1;

    // weird nachos memory stuff
    char execname[256];
    for (int i = 0; i < 256; ++i){
        int temp;
        // machine->ReadMem((int)name + i, 1, &temp); // int addr, int size, int* value

        bool result = machine->ReadMem((int)name + i, 1, &temp); // int addr, int size, int* value
        if (not result){
            result = machine->ReadMem((int)name + i, 1, &temp); // int addr, int size, int* value
        }
        ASSERT(result);

        execname[i] = (char) temp; 
        if (temp == 0)
            break;
    }
    // based on code from progtest.cc
    OpenFile *executable =  fileSystem->Open(execname);
    AddrSpace *space;

    if (executable == NULL ) { // invalid name? should porbably have an error print
        return rv;
    }       

    space = new AddrSpace(executable);
    Thread* child = new Thread("childThread", true);

    // add something into child->pid before fork XXX
    child->pid = processtable.size();

    processtable.push_back({child,0});

    child->space = space;

    // delete executable; // clean up memory

    // store child->pid as a local variable XXX
    rv = child->pid;

    // set child into local variable
    rv = child->pid;


    child->Fork(ExecHelper, 1); // Fork takes one parameter?
    currentThread->Yield();

    // eventually have some kind of table for the threads like we did for the file table
    return rv;

}


/* This user program is done (status = 0 means exited normally). */
// the name is slightly different, but thats ok-- it will still work!
void ExitF(int status) {
    // set the current thread's status to the status int.
    // store exit status in process table
    int pid = currentThread->pid;
    processtable[pid].exitStatus = status;

    // processtable.push_back(currentThread);
    currentThread->Finish();
}	


/* Only return once the the user program "id" has finished.  
 * Return the exit status.
 */
int Join(SpaceId id) {
    Thread* thread;
    int rv;
    // look up the process id in the process table to obtain a pointer
    // for (int i = 0; i < processtable.size(); ++i){
    //     if (processtable[i]->exitStatus == id){
    thread = processtable[id].thread; 
    // save thread.exitstatus into rv
    // rv = thread->exitStatus;
    //     }
    // }
    // use thread::join to wait until that thread has finished
    currentThread->Join(thread);
    rv = processtable[id].exitStatus;
    // return the exit status of the joined thread
    return rv;

}

/*
void Fork(void(*func) () ) {
}
*/

void Yield() {
    currentThread->Yield();	

}

// print the hit rate to the screen
void Memstats() {

    char temp[256];
    snprintf(temp, 256, "%d/%d", page_hits, page_faults);

    synConsole->cwrite(temp, sizeof(temp));
}

