#include "machine.h"

class SwapTable{
    
    public:
    TranslationEntry hashes[4*NumPhysPages];
    // array of process IDs of NumPhysPages XXX
    int pids[4*NumPhysPages];

    SwapTable();
        
    void Update(int block, int vpn, int pid);
    // store PID

    int Find(int vpn, int pid);
    // Find PID

};
