#include "machine.h"

class HashTable {
    
    public:
    TranslationEntry hashes[NumPhysPages];
    // array of process IDs of NumPhysPages
    int pids[NumPhysPages];

    HashTable();
        
    void Update(int frame, int vpn, int pid);
    // store PID

    int Find(int vpn, int pid);
    // Find PID

    //Clock hand FIXME moving to exception.cc
    //int hand;

    //Clock function?MAYBE 
    //void Clock(/*TODO*/);
    //NOT HERE^
    //Probs not a funct either...
};
