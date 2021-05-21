// system.h 
//	All global variables used in Nachos are defined here.
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#ifndef SYSTEM_H
#define SYSTEM_H

#include "copyright.h"
#include "utility.h"
#include "thread.h"
#include "scheduler.h"
#include "interrupt.h"
#include "stats.h"
#include "timer.h"
#include "tired.h"
#include "alarm.h"
#include <vector>
#include "synch.h"

// Initialization and cleanup routines
extern void Initialize(int argc, char **argv); 	// Initialization,
						// called before anything else
extern void Cleanup();				// Cleanup, called when
						// Nachos is done.

//Declare for compilation purposes
class Tired;
class BitMap;
class SynchConsole;
class OpenFile;

struct ProcessTableEntry{
    Thread* thread = NULL;
    int exitStatus = 0;
};

extern Thread *currentThread;			// the thread holding the CPU
extern Thread *threadToBeDestroyed;  		// the thread that just finished
extern Scheduler *scheduler;			// the ready list
extern Interrupt *interrupt;			// interrupt status
extern Statistics *stats;			// performance metrics
extern Timer *timer;				// the hardware alarm clock
extern std::vector<Tired*> alarms;

extern int page_hits;
extern int page_faults;
extern Semaphore* statsMutex;
extern Semaphore* bitmapMutex;
extern BitMap *swaplist;

extern OpenFile* swap;

#ifdef USER_PROGRAM
#include "machine.h"
extern BitMap* freelist;
extern SynchConsole *synConsole;
extern Machine* machine;	// user program memory and registers
extern std::vector<ProcessTableEntry> processtable;
extern std::vector<char*> arglist;

#endif

#ifdef FILESYS_NEEDED 		// FILESYS or FILESYS_STUB 
#include "filesys.h"
extern FileSystem  *fileSystem;
#endif

#ifdef FILESYS
#include "synchdisk.h"
//#include "openfile.h"
extern SynchDisk   *synchDisk;
//extern OpenFile* openfile;
#endif

#ifdef NETWORK
#include "post.h"
extern PostOffice* postOffice;
#endif

#endif // SYSTEM_H
