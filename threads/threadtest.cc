// threadtest.cc 
//	Simple test case for the threads assignment.
//
//	Create two threads, and have them context switch
//	back and forth between themselves by calling Thread::Yield, 
//	to illustratethe inner workings of the thread system.
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "system.h"
#include "synch.h"
#include "alarm.h"
#include "comm.h"
// testnum is set in main.cc
int testnum = 1;

//----------------------------------------------------------------------
// SimpleThread
// 	Loop 5 times, yielding the CPU to another ready thread 
//	each iteration.
//
//	"which" is simply a number identifying the thread, for debugging
//	purposes.
//----------------------------------------------------------------------

    void
SimpleThread(int which)
{
    int num;

    for (num = 0; num < 5; num++) {
        printf("*** thread %d looped %d times\n", which, num);
        currentThread->Yield();
    }
}

int num = 0;
Lock simple("simple lock");
    void
SimpleLock(int which)
{
    while(num < 60)
    {
        ASSERT(num <= 60);
        printf("*** thread %d increment %d\n", which, num);
        currentThread->Yield();
        simple.Acquire();
        num++;
        simple.Release();
    }
}
    void
SimpleLock2(int which)
{
    while(num < 60)
    {
        ASSERT(num <= 60);
        printf("*** thread %d increment %d\n", which, num);
        currentThread->Yield();
        simple.Release();
        num++;
        simple.Release();
    }
}

int CVnum = 0;
Lock simpleCV("CV simple lock");
Condition simpleCond("CV simple condition variable");
    void
CVSimpleLock(int which)
{
    while(CVnum < 60)
    {
        ASSERT(CVnum <= 60);
        printf("*** thread %d increment %d\n", which, CVnum);
        currentThread->Yield();
        simpleCV.Acquire();
        simpleCond.Wait(&simpleCV);//wait
        CVnum++;
        // simpleCV.Release();
        simpleCond.Broadcast(&simpleCV); //broadcast
    }
}

void CVSimpleLock2(int which){
    simpleCV.Acquire();
    simpleCond.Broadcast(&simpleCV);
}



int awake = 1;
    void
spin(int thread)
{
    while(awake == 1)
    {
        currentThread->Yield();
        //    fprintf(stderr,"%d\n", stats->totalTicks);
    }
}

int lucid = 3;
    void
spin_lucid(int thread)
{
    while(lucid > 0)
    {
        currentThread->Yield();
        //fprintf(stderr,"%d\n", stats->totalTicks);
    }
    printf("Loop done\n");
}


Alarm tokei;
    void
rem_cycle(int thread)
{
    switch(thread){
        case 0:
            tokei.GoToSleepFor(30000000);
            break;
        case 1:
            tokei.GoToSleepFor(40000000);
            break;
        case 2:
            tokei.GoToSleepFor(50000000);
            tokei.GoToSleepFor(50000000);
            break;
        case 3:
            tokei.GoToSleepFor(60000000);
            tokei.GoToSleepFor(60000000);
            tokei.GoToSleepFor(60000000);
            break;
        default:
            tokei.GoToSleepFor(20000000);
            break;
    }
    printf("%d\n", lucid);
    lucid--;
}

//----------------------------------------------------------------------
// ThreadTest1
// 	Set up a ping-pong between two threads, by forking a thread 
//	to call SimpleThread, and then calling SimpleThread ourselves.
//----------------------------------------------------------------------

    void
ThreadTest1()
{
    DEBUG('t', "Entering ThreadTest1");

    Thread *t = new Thread("forked thread");

    t->Fork(SimpleThread, 1);
    SimpleThread(0);
}


    void
ThreadTest2 ()
{
    DEBUG('t', "Entering ThreadTest2");

    Thread *t = new Thread("two thread lock test");
    t->Fork(SimpleLock, 1);
    SimpleLock(0);
}
    void
ThreadTest7 ()
{
    DEBUG('t', "Entering ThreadTest2");

    Thread *t = new Thread("two thread lock test");
    t->Fork(SimpleLock, 1);
    SimpleLock2(0);
}

    void
ThreadTest3 ()
{

    DEBUG('t', "Entering ThreadTest3");

    Thread *a = new Thread("thread 1");
    Thread *b = new Thread("thread 2");
    Thread *c = new Thread("thread 3");
    Thread *d = new Thread("thread 4");
    Thread *e = new Thread("thread 5");
    Thread *f = new Thread("thread 6");
    Thread *g = new Thread("thread 7");
    Thread *h = new Thread("thread 8");
    Thread *i = new Thread("thread 9");
    Thread *j = new Thread("thread 10");
    Thread *k = new Thread("thread 11");
    Thread *l = new Thread("thread 12");
    Thread *m = new Thread("thread 13");
    Thread *n = new Thread("thread 14");
    Thread *o = new Thread("thread 15");
    Thread *p = new Thread("thread 16");
    Thread *q = new Thread("thread 17");
    Thread *r = new Thread("thread 18");
    Thread *s = new Thread("thread 19");
    a->Fork(SimpleLock,0);
    b->Fork(SimpleLock,1);
    c->Fork(SimpleLock,2);
    d->Fork(SimpleLock,3);
    e->Fork(SimpleLock,4);
    f->Fork(SimpleLock,5);
    g->Fork(SimpleLock,6);
    h->Fork(SimpleLock,7);
    i->Fork(SimpleLock,8);
    j->Fork(SimpleLock,9);
    k->Fork(SimpleLock,10);
    l->Fork(SimpleLock,11);
    m->Fork(SimpleLock,12);
    n->Fork(SimpleLock,13);
    o->Fork(SimpleLock,14);
    p->Fork(SimpleLock,15);
    q->Fork(SimpleLock,16);
    r->Fork(SimpleLock,17);
    s->Fork(SimpleLock,18);
    SimpleLock(19);
}

Semaphore *joinTestSemaphore = new Semaphore("JoinTestSemaphore",0);
void joinTestParent(int which) {
    printf("Hi, my name is Parent (#%d)\n", which);
    printf("(#%d) I am waiting on the child to count to ten!\n", which);
    // wait on child?
    joinTestSemaphore->P();
    printf("(#%d) Yay! He can count!\n", which);
}
void joinTestChild(int which) {
    printf("Hi, my name is Child (#%d)\n", which);
    for (int i = 1; i <= 10; ++i){
        printf("(#%d) fizzbuzz %d\n", which, i);
    }
    // singnal parent?
    joinTestSemaphore->V();

}


void ThreadTest5(){
    // make some joinable threads?
    Thread *q = new Thread("thread 1", true); // make a thread
    q->Fork(joinTestChild, 1); // fork a child 
    joinTestParent(0); // run the parent code
    printf("Are ya joining, son? ...son? ...SOONNNNN??\n"); // this should print
    q->Join(currentThread); //join the threads? Profit? 
    printf("Im dead papa! X.X (If you see this, something has gone terribly wrong)\n"); 
    // ^^^^ if this prints, something has gone terribly wrong
    // the dead have come back to haunt us

}

    void
AlarmTest1()
{
    Thread *forked = new Thread("Forked");
    forked -> Fork(spin, 0);
    Alarm alrm;
    printf("Sleeping!\n");
    alrm.GoToSleepFor(30000000);
    printf("Woke Up!\n");
    awake = 0;
}

    void
AlarmTest2()
{
    //Alarm alrm;

    Thread *a = new Thread("Thread Alpha");
    Thread *b = new Thread("Thread Beta");
    Thread *c = new Thread("Thread Gamma");
    a -> Fork(rem_cycle, 1);
    b -> Fork(rem_cycle, 2);
    c -> Fork(rem_cycle, 3);
    spin_lucid(0);
}

int gerald = -10;
Condition cond = Condition("CV1");
Lock aLock = Lock("lock");
void ConditionTest1Thread2(int which){
    while(gerald < 0){
        ++gerald;
        printf("Inc. gerald and he is now %d\n", gerald);
    }
    printf("gerald is done, signal lock\n");
    cond.Signal(&aLock);
}
void ConditionTest1Thread1(int which){
    printf("waiting on lock\n");
    aLock.Acquire();
    cond.Wait(&aLock);
    printf("got the lock yee yee\n");
    // increase gerald
    gerald += 10;
    printf("gerald is now %d\n", gerald);

}

void ConditionTest1(){
    // thread trying to add a number to another number
    // but it needs another number to be greater than 0 to do it

    // in thread1:
    Thread *thread1 = new Thread("CVthread1");
    thread1->Fork(ConditionTest1Thread1, 0);
    ConditionTest1Thread2(1);
    // gerald increments until 0
    // in thread2:
    // grerald needs to be 0 in order to increment

}

int ahh = 100;//port
int bhh = 2;//message
int chh = 0; // pointer
int dhh = 4;
void sendtest(){
    Send(ahh,bhh);


}
void sendtest2(){
    Send(ahh,dhh);
}

void receivetest(int purplefloorg){
    Receive(ahh,&chh);
    printf(" Here is chh %d \n",chh);  


}



void commtest1(){
    Thread *thread1 = new Thread("Sender");
    thread1->Fork(receivetest,1); 
    sendtest(); 
}


void commtest2(){
    Thread *thread1 = new Thread("Sender");
    thread1->Fork(receivetest,1);
    sendtest();
    Thread *thread2 = new Thread("Sender2");
    thread2->Fork(receivetest,1);
    sendtest2();
}
/*   Ran out of time to create the looping test, as I think this would not work
     void sendloop(){
     primaris = 0;
     secundus = 0;
     while(primaris < 256){
     ++primaris;
     ++secundus;
     Send(primaris,Secundus);
     }
     }

     void receiveloop(int redfloorg){
     primaris = 0;
     secundus = 0;
     while(primaris < 256){
     ++primaris;
     ++secundus;
     Receive(primaris,Secundus);
     }

     void commtest3(){
     Thread *thread1 = new Thread("Sender");
     thread1->Fork(receiveloop,1);
     sendloop();

     }

*/

    void
ConditionTest2()
{

    DEBUG('t', "Entering ConditionTest2");

    Thread *a = new Thread("thread CV 1");
    Thread *b = new Thread("thread CV 2");
    Thread *c = new Thread("thread CV 3");
    Thread *d = new Thread("thread CV 4");
    Thread *e = new Thread("thread CV 5");
    Thread *f = new Thread("thread CV 6");
    Thread *g = new Thread("thread CV 7");
    Thread *h = new Thread("thread CV 8");
    Thread *i = new Thread("thread CV 9");
    Thread *j = new Thread("thread CV 10");
    Thread *k = new Thread("thread CV 11");
    Thread *l = new Thread("thread CV 12");
    Thread *m = new Thread("thread CV 13");
    Thread *n = new Thread("thread CV 14");
    Thread *o = new Thread("thread CV 15");
    Thread *p = new Thread("thread CV 16");
    Thread *q = new Thread("thread CV 17");
    Thread *r = new Thread("thread CV 18");
    Thread *s = new Thread("thread CV 19");
    a->Fork(CVSimpleLock,0);
    b->Fork(CVSimpleLock,1);
    c->Fork(CVSimpleLock,2);
    d->Fork(CVSimpleLock,3);
    e->Fork(CVSimpleLock,4);
    f->Fork(CVSimpleLock,5);
    g->Fork(CVSimpleLock,6);
    h->Fork(CVSimpleLock,7);
    i->Fork(CVSimpleLock,8);
    j->Fork(CVSimpleLock,9);
    k->Fork(CVSimpleLock,10);
    l->Fork(CVSimpleLock,11);
    m->Fork(CVSimpleLock,12);
    n->Fork(CVSimpleLock,13);
    o->Fork(CVSimpleLock,14);
    p->Fork(CVSimpleLock,15);
    q->Fork(CVSimpleLock,16);
    r->Fork(CVSimpleLock,17);
    s->Fork(CVSimpleLock,18);
    simpleCV.Acquire();
    CVSimpleLock2(19);
}




//----------------------------------------------------------------------
// ThreadTest
// 	Invoke a test routine.
//----------------------------------------------------------------------

    void
ThreadTest()
{
    switch (testnum) {
        case 1:
            ThreadTest1();
            break;
        case 2:
            ThreadTest2();
            break;
        case 3:
            ThreadTest3 ();
            break;
        case 4:
            AlarmTest1();
            break;
        case 5:
            ThreadTest5();
            break;
        case 6:
            ConditionTest1();
            break;
        case 7:
            ConditionTest2();
            break;
        case 8:
            AlarmTest2();
            break;
        case 9:
            commtest1();
            break;
        case 10:
            commtest2();
            break;
        case 11:
            ThreadTest7();
            break;
        default:
            printf("No test specified.\n");
            break;
    }
}

