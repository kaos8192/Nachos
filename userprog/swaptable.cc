#include "swaptable.h"
#include "machine.h"

SwapTable::SwapTable(){
    for (int i = 0; i < NumPhysPages; ++i){
        // set valid flag to false
        hashes[i].valid = FALSE;
    }
}

void SwapTable::Update(int block, int vpn, int pid) {
    hashes[block].virtualPage = vpn;
    hashes[block].physicalPage = block; 
    hashes[block].valid = TRUE;
    hashes[block].use = TRUE;
    hashes[block].dirty = TRUE;
    hashes[block].readOnly = FALSE;

    pids[block] = pid; 
}

int SwapTable::Find(int vpn, int pid) {
    int block= vpn%NumPhysPages;

    if (hashes[block].valid == TRUE and hashes[block].virtualPage == vpn and pids[block] == pid){
        return block;
    }
 
    return -1;
}
