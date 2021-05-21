#ifndef _TIRED_H_
#define _TIRED_H_

#include "system.h"

class Tired
{
    public:
        Tired(Thread *s, int w);
        ~Tired(){};
        Thread* get_thread();
        int get_time();
    private:
        Thread *sleepy;
        int wakeAt;
};

#endif
