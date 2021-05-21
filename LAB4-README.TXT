OMIS (our Other Mask is Input Sanitation) NachOS Documentation
Lab 4 -- Virtual Memory in NachOS

Group Members:
    Chad Wilson
    Joshua Obernesser
    Geir Anderson

Member work:
Chad Wilson:
    Edited Files:
        userprog/
            exception.cc
        threads/
            system.{cc,h}
        userprog/
            ipt.{cc,h}
            swaptable.{cc,h}
            syscall.{cc,h}
        test/
            test.s

    Tasks:
        Swapfile
        Bitmap
        Inverted Page Table 
        Statistics



Joshua Obernesser:
	Fixes:
	    Fixed Close
	Task1:
	    Updated create data size
	Task2: 
       	Attempted to impliment  prefetching to exception.cc Caused conflicts with clock. Attempted to make it work but ran out of time code is commented out but present.


Geir Anderson:
    Fixes:
        Fixed SynchConsole's read and write to try preventing deadlock
        Fixed Synch to fix Lock and Conditions
    Task1:
        Began adding OpenFile global variable
    CLOCK:
        Implemented a clock system for the IPT in exception.cc and somewhat in ipt.cc/h
        
