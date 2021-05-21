// synch.cc 
//	Routines for synchronizing threads.  Three kinds of
//	synchronization routines are defined here: semaphores, locks 
//   	and condition variables (the implementation of the last two
//	are left to the reader).
//
// Any implementation of a synchronization routine needs some
// primitive atomic operation.  We assume Nachos is running on
// a uniprocessor, and thus atomicity can be provided by
// turning off interrupts.  While interrupts are disabled, no
// context switch can occur, and thus the current thread is guaranteed
// to hold the CPU throughout, until interrupts are reenabled.
//
// Because some of these routines might be called with interrupts
// already disabled (Semaphore::V for one), instead of turning
// on interrupts at the end of the atomic operation, we always simply
// re-set the interrupt state back to its original value (whether
// that be disabled or enabled).
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "synch.h"
#include "system.h"

//----------------------------------------------------------------------
// Semaphore::Semaphore
// 	Initialize a semaphore, so that it can be used for synchronization.
//
//	"debugName" is an arbitrary name, useful for debugging.
//	"initialValue" is the initial value of the semaphore.
//----------------------------------------------------------------------

Semaphore::Semaphore(const char* debugName, int initialValue)
{
    name = const_cast<char *>(debugName);
    value = initialValue;
    queue = new List;
}

//----------------------------------------------------------------------
// Semaphore::Semaphore
// 	De-allocate semaphore, when no longer needed.  Assume no one
//	is still waiting on the semaphore!
//----------------------------------------------------------------------

Semaphore::~Semaphore()
{
    delete queue;
}

//----------------------------------------------------------------------
// Semaphore::P
// 	Wait until semaphore value > 0, then decrement.  Checking the
//	value and decrementing must be done atomically, so we
//	need to disable interrupts before checking the value.
//
//	Note that Thread::Sleep assumes that interrupts are disabled
//	when it is called.
//----------------------------------------------------------------------

    void
Semaphore::P()
{
    IntStatus oldLevel = interrupt->SetLevel(IntOff);	// disable interrupts

    while (value == 0) { 			// semaphore not available
        queue->Append((void *)currentThread);	// so go to sleep
        currentThread->Sleep();
    } 
    value--; 					// semaphore available, 
    // consume its value

    (void) interrupt->SetLevel(oldLevel);	// re-enable interrupts
}

//----------------------------------------------------------------------
// Semaphore::V
// 	Increment semaphore value, waking up a waiter if necessary.
//	As with P(), this operation must be atomic, so we need to disable
//	interrupts.  Scheduler::ReadyToRun() assumes that threads
//	are disabled when it is called.
//----------------------------------------------------------------------

    void
Semaphore::V()
{
    Thread *thread;
    IntStatus oldLevel = interrupt->SetLevel(IntOff);

    thread = (Thread *)queue->Remove();
    if (thread != NULL)	   // make thread ready, consuming the V immediately
        scheduler->ReadyToRun(thread);
    value++;
    (void) interrupt->SetLevel(oldLevel);
}

//-------------------------------------------------------------------------

// Dummy functions -- so we can compile our later assignments 
// Note -- without a correct implementation of Condition::Wait(), 
// the test case in the network assignment won't work!

//------------------------------Locks-----------------------
Lock::Lock(const char* debugName)
{
    name = const_cast<char *>(debugName);
    //Need semaphores to do the hard atomicity stuff
    //XXX Weren't there things to expand semaphores debugName?
    semaphore = new Semaphore(debugName, 1);
}
Lock::~Lock()
{
    delete semaphore;    
}

//----------------Lock Methods---------------------

// Atomically wait until the lock is free,
// then set it to busy. Equivalent to Sem.::P(),
// with the semapmore value of 0 equal to busy,
// and value of 1 equal to free.
void Lock::Acquire()
{
    DEBUG('t', "Lock Acquired\n");
    semaphore->P();
    owner = currentThread;
}

// Atomically set the lock to be free, waking up a thread
// waiting for the lock, if any. Equivalent to Sem.::V(),
// with the semamphore value of 0 equal to busy, and value
// of 1 equal to free.
void Lock::Release()
{
    ASSERT(isHeldByCurrentThread());
    //moved owner nullification above V
    // set lock owner to nullptr
    owner = NULL;
    semaphore->V();
    DEBUG('t', "Lock Released\n");
}

//Check the currentThread pointer and compare with owner pointer
bool Lock::isHeldByCurrentThread()
{
    if(currentThread == owner)
    {
        DEBUG('t', "Owner: %s\n",currentThread->getName());
        return true;
    }
    else
    {
        DEBUG('t', "Not Owner: %s\n",currentThread->getName());
        return false;
    }
}
//------------------------------------------------------

//-------------------Condition Variables----------------

Condition::Condition(const char* debugName)
{
    name = const_cast<char *>(debugName);
    //NachOS is assumed to be FIFO, use a queue thingy
    semaphore = new Semaphore(debugName, 0); // changed from 1 to 0
    mutex = new Semaphore(debugName,1);
    count = 0;
}
Condition::~Condition()
{
    delete semaphore;
    delete mutex;
}

//----------- Condition Variable Functions ------------------------
//Needs to release the lock, passing CPU to the next process
//While putting the lock thread to sleep
//Then when signaled the lock thread to re-acquire the lock
//This MUST ALL happen atomically.
//~~~~~~~~~~~~~~~
//Use waitQueue and ~maybe~ semaphores
//~~~~~~~~~~~~~~~
//release the lock, gives up the CPU until signalled then re-aquire the lock
void Condition::Wait(Lock* conditionLock)
{
    // check if currentThread is the owner of the Lock with assert
    ASSERT(conditionLock->isHeldByCurrentThread());

    //Comment out when trying to test and when this works.
    // ASSERT(FALSE);
    //DEBUG('c',"%s -- Trying to release lock\n", currentThread->getName());
    conditionLock->Release();
    DEBUG('c',"%s -- released lock", currentThread->getName());
    DEBUG('c',"%s -- Waiting on semaphore \n", semaphore->getName());
    mutex->P();
    ++count;
    mutex->V();
    semaphore->P();
    DEBUG('c',"%s -- Got semaphore ", semaphore->getName());
    DEBUG('c',"%s -- Trying to acquire lock\n", currentThread->getName());
    conditionLock->Acquire();
    DEBUG('c',"%s -- acquired lock\n", currentThread->getName());
}

//Wake up a thread in waitQueue if it is waiting for the condition var
void Condition::Signal(Lock* conditionLock)
{
    DEBUG('c',"%s -- trying to acquire lock\n", currentThread->getName());
    conditionLock->Acquire();
    DEBUG('c',"%s -- acquired lock\n", currentThread->getName());
    DEBUG('c',"%s -- Signalling semaphore \n", semaphore->getName());
    semaphore->V();
    mutex->P();
    --count;
    mutex->V();
    DEBUG('c',"%s -- Singalled semaphore \n", semaphore->getName());
    DEBUG('c',"%s -- Trying to release lock\n", currentThread->getName());
    conditionLock->Release();
    DEBUG('c',"%s -- release lock\n", currentThread->getName());

}

//Use the Signal function to wake up all threads currently in waitQueue
void Condition::Broadcast(Lock* conditionLock)
{
    // call V in a loop until the semaphore value is?
    for(int i = count; i > 0; --i){
        mutex->P();
        --count;
        mutex->V();
        semaphore->V();
    }


}
