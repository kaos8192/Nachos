#include "synchconsole.h"


static void crav(int why)
{
    synConsole->readcond->Broadcast(synConsole->read_mutex);
}

static void cwav(int why)
{
    synConsole->writecond->Broadcast(synConsole->write_mutex);
}

SynchConsole::SynchConsole()
{
    read_mutex = new Lock("console read");
    write_mutex = new Lock("console write");
    readcond = new Condition("console ready read");
    writecond = new Condition("console ready write");
    sconsole = new Console(NULL, NULL, crav, cwav, 0);
}

SynchConsole::~SynchConsole()
{
    delete readcond;
    delete writecond;
    delete read_mutex;
    delete write_mutex;
    delete sconsole;
}

void SynchConsole::cread(char* buffer, int size)
{
    char ch;

    read_mutex->Acquire();
    for(int i = 0; i < size; ++i)
    {
        readcond->Wait(read_mutex);
        ch = sconsole->GetChar();
        buffer[i] = ch;
        if(ch == '\n')
            break;
    }
    read_mutex->Release();
}

void SynchConsole::cwrite(char* buffer, int size)
{
    write_mutex->Acquire();
    for(int i = 0; i < size; ++i)
    {
        sconsole->PutChar(buffer[i]);
        writecond->Wait(write_mutex);
        if(buffer[i] == '\n')
            break;
    }
    write_mutex->Release();
}
