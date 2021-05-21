#ifndef _SYNCHCONSOLE_H_
#define _SYNCHCONSOLE_H_
#include "synch.h"
#include "console.h"
#include "syscall.h"
#include "system.h"


class SynchConsole
{
    //TODO
    public:
        SynchConsole(/*TODO*/);
        ~SynchConsole();
        void cread(char* buffer, int size);
        void cwrite(char* buffer, int size);

        Lock* read_mutex;
        Lock* write_mutex;
        Condition* readcond;
        Condition* writecond;
    
    private:
        Console* sconsole;
};
#endif
