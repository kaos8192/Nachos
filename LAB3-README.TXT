OMIS (our Other Mask is Input Sanitation) NachOS Documentation
Lab 3 -- Building a User Space System

Group Members:
    Chad Wilson
    Joshua Obernesser
    Geir Anderson

Member work:
Chad Wilson:
    »LAB2 Fixes 
        synch.cc
            - Added owner = NULL; to Lock::Release()
            - Changed 'semaphore' to initialize with 0 instead of 1
            - Added assert to check that currentThread is owner of the lock
    
        thread.cc
            - Moved 'threadToBeDestroyed = currentThread;' after the rendezvous
    
    »LAB3 (with help from Dr. Marmorstein)
        Create (userprog/syscall.cc, userprog/exception.cc, test/create.c, test/Makefile)
            - Wrote Create and the test create.c
        Open (userprog/syscall.cc, userprog/exception.cc, test/open.c, test/Makefile)
            - Wrote Open and the test open.c
        Close/Closef (userprog/syscall.cc, userprog/exception.cc, test/open.c, test/Makefile)
            - Wrote Close (Written as CloseF, because the name conflicted with
          another function call in a different file).
        Read (syscall.cc, test/Makefile, test/read.c)
            - Wrote Read
        Write (syscall.cc, test/Makefile, test/open.c)
            - Wrote Write
        Exec (syscall.cc, test/Makefile, test/exec.c)
            - Wrote Exec
        AddrSpace Class (addrspace.cc, addrspace.h)
            - Additions to the AddrSpace class 
            - Memory stuff in constructor
        Exit (syscall.cc, test/Makefile, test/ej_parent.c, test/ej_child.c)
            - Wrote Exit
        Join (syscall.cc, test/Makefile, test/ej_parent.c, test/ej_child.c)
            - Wrote Join
        Exec with Args (syscall.h, syscall.cc, test/Makefile, test/argtests, test/argtest_child.c)
            - Test doesnt work...





Joshua Obernesser:

	Lab3 (syscall.cc, addrspace.h,addrspace.cc, exception.cc)
	addrspace.h,addrspace.cc Implimented constructor for Fork
	Exception.cc	Modified exception.cc for calls
	»Lab3 (syscall.cc)
		- Implimented system call yield. 



Geir Anderson:
    »Lab2 Fixes:
        -synch.cc: Lock->isHeldByCurrentThread();
            *Added DEBUG statments for more verbose testing.
        -threadtest.cc:
            *Added ThreadTest7, uses -q 11
            *Added SimpleLock2, for ThreadTest7
                ◆Tests improper signalling
            TODO:Add additional test to ensure all Lock cases are handled correctly.

    »Lab3 Additions:
        -SynchConsole class (Makefile.common, threads/system.cc, threads/system.h, userprog/synchconsole.cc, userprog/synchconsole.h, userprog/exception.cc w/ help from Dr. Marmorstein)
            *Added the initial structure for the SynchConsole.
            *Added cread, cwrite, crav, cwav, constructor, destructor, and if statements to exception.cc.
            *Added to Makefile.common

        -SynchConsole test (test/console.c, test/Makefile)
            *TODO

        -cat & cp(test/cat.c, test/cp.c, test/Makefile)
            *Created the files in test/.
            *Began cat, neither file is complete


    »Misc:
        *Edited out some bugs.
