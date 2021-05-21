#include "ipt.h"
#include "machine.h"

extern int hand;

HashTable::HashTable(){
    for (int i = 0; i < NumPhysPages; ++i){
        // set valid flag to false
        hashes[i].valid = FALSE;
    }
    //init the clock hand
    //hand = 0;//MAYBE set init to zero?
}

void HashTable::Update(int frame, int vpn, int pid) {
    hashes[frame].virtualPage = vpn;
    hashes[frame].physicalPage = frame; 
    hashes[frame].valid = TRUE;
    hashes[frame].use = TRUE;//Need to use for clock somehow
    hashes[frame].dirty = TRUE;
    hashes[frame].readOnly = FALSE;

    pids[frame] = pid; //Store the PID
}

int HashTable::Find(int vpn, int pid) {
    int frame = hand;//vpn%NumPhysPages;

    while (hashes[frame].valid != TRUE or hashes[frame].virtualPage != vpn or pids[frame] != pid){
        ++frame%=NumPhysPages;
        if(frame == hand)
        {
            return -1;
        }
    }
 
    return frame;
}

//MAYBE TODO
//Need to rotate through the stuff and change use bits to dirty
//Need to stay in place on a non-replacement use
//Need to swap out stuff at spot
/*void HashTable::Clock()
{
    //iterate through something
    
    //place if empty

    //else if dirty, replace

    //else if need to replace but clean, toggle bit
    
    //else use and don't move hand
}*/
