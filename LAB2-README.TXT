OMIS (our Other Mask is Input Sanitation) NachOS Documentation
Lab 2 -- Building a Thread System

Group Members:
    Chad Wilson
    Joshua Obernesser
    Geir Anderson

Member work:
Chad Wilson:
    Thread::Join (thread.cc, thread.h, threadtest.cc)
    - I wrote the implementation of Thread::Join. To do this, I
      first added a boolean value "joinable" to the Thread class 
      and a parameter "joinablle" to the constructor. Joinable is
      false by default. I also added two semaphores, sig and rend,
      to the class.
    - Join itself is waiting for the child's sig semaphore to signal
      that it is done. Then, the child's rend semaphore signals.
    - The rend and sig semaphores are deleted in the thread destructor.
    - In Thread::Finish, before the thread sleeps, I check if it is
      joinable. If it is, then it waits for its own sig semaphore to
      be signalled, and then its rend semaphore signals.
    - Join is tested in ThreadTest5.

    Condition Variables (synch.cc, synch.h, threadtest.cc)
    - I wrote the majority of the Condtion Variable code, however
      was helped by Josh with Condition::Signal and by Geir with 
      testing and debugging.
    - I added two semaphores to the Condition class: semaphore and
      mutex. Semaphore signals and waits, while mutex exists to
      protect the added count variable.
    - Condition::Wait Releases the lock, signals its semaphore, adds
      one to count, and acquires the lock.
    - Condition::Signal Acquires the lock, waits on its semaphore,
      removes one from count, and release the lock.
    - Condition::Broadcast loops through -count- times, each time 
      removing one from count and signalling the semaphore.
    - Conditions are tested in threadtest.cc with ConditionTest1 and
      ConditionTest2. Test1 tests a simple condtion and test2 tests
      broadcast.



Joshua Obernesser:
	Thread::comm(comm.h, comm.cc) 
        - I wrote comm.h and comm.cc. I implimented the two global functions Send and Receive. 
       	  I did this by creating a port class which contained integers to identify it, 
	  two semaphores, and a lock. I also created a global vector of port objects.
        - I implimented Send and receive to avoid race conditions and deadlocks(with help from Dr.Marmorstein).
	- I implimented tests to ensure they were not deadlocking or encountered race conditions. Test 1 ensures that proper communication is achieved, test 2 ensures that cross contamination does not occur by running multiple instances of Send and Receive on the same ports. 

	Condition Variables (synch.cc, synch,h, threadtest.cc)
        - I helped Chad and Geir with the implimentation of Conditon Variables
	- Heavily assisted with the implimentation of tests for Condition Variables. Including the use of incrementing integers for the inital test.
	
	


Geir Anderson:
Lock Acquire, Release, & isHeldByCurrentThread (synch.cc, synch.h, threadtest.cc):
    -I wrote the Acquire, Release, & isHeldByCurrentThread methods for the Lock.
    -Wrote the SimpleLock, ThreadTest2, and ThreadTest3 to test locks in threadtest.cc.
    -Improved SimpleLock in threadtest.cc.

Alarm w/ help from Dr. Marmorstein (Makefile.common, alarm.h, alarm.cc, 
                                    tired.h, tired.cc, system.h,
                                    system.cc, threadtest.cc):
    -Implemented the Alarm class and methods in alarm.h and alarm.cc.
        *Constructor, destructor, and GoToSleepFor.
    -Implemented a global vector using the Tired class in system.h and system.cc.
    -Implemented the Tired class in tired.h and tired.cc.
        *Tired is used to keep track of a pairing of thread pointers and a tick number.
    -Implemented an expansion to the TimerInterruptHandler and a helper function.
        *This allows the timer interrupt to process the queued sleeping threads of the alarm(s);
    -To use the alarm test cases -rs must be used when running NachOS.
        *This activates the internal timer system.
            →42, 64, 126, and 128 were used in testing.
    -Implemented the spin, spin_lucid, rem_cycle, AlarmTest1, and AlarmTest2 in threadtest.cc
    (Also wrote to this document. Hello! ツ)

--------------------OLD DOCUMENTATION--------------------
TODO fix up this text to be more specific
I have written the current implementation for Lock in synch.cc. 
I made a SimpleLock function and ThreadTest2 in threadtest.cc. 
I fixed SimpleLock and ThreadTest3 in threadtest.cc. 
I created the alarm.cc and alarm.h files for Task 4 in threads. 
I'm working on files using the alarmy branch.
---------------------------------------------------------
