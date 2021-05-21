#include "comm.h"

class ports{
  public: 
 	int tag;
 	int message;
	Semaphore *Messagesent = new Semaphore("aDonesemaphore",0);
      	Semaphore *Messagereceived = new Semaphore("oneDonesemaphore",0);	
        Lock portlock = Lock("portlock");
 
// Mutex

// Each object has 2 semaphores and its own lock. So that send and receive are able to use signals for rendezvouses. 

};

std::vector<ports> harbor(256);

void Send (int port, int msg){
DEBUG('c',"Starting Send \n ");
// port locks, sends message, then waits for a receive signal from another thread, uses condition variable to give up the lock. Wake up threads unti you wake the one up that matches the port. Put others to sleep, repeat. 
 DEBUG('c'," Finished send waiting \n");
  harbor[port].portlock.Acquire();
  DEBUG('c',"Acquired Lock \n");
  //critical section
  harbor[port].message = msg;
  DEBUG('c',"Inserted value %d \n", msg);
  harbor[port].Messagesent->V();
 harbor[port].portlock.Release();
  DEBUG('c',"Released send lock \n");
   harbor[port].Messagereceived->P();
  DEBUG('c',"Send jobs done \n");

}

void  Receive(int port, int* msg){
 DEBUG('c',"Starting Receive \n");

  DEBUG('c',"Receive finished waiting \n");
 harbor[port].Messagesent->P();
 harbor[port].portlock.Acquire(); 
 //critical section
 *msg = harbor[port].message;

  harbor[port].Messagereceived->V();         
  DEBUG('c',"Received message %d \n",*msg);
  harbor[port].portlock.Release();

  DEBUG('c',"Received jobs done \n");
  
}
