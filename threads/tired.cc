#include "tired.h"

Tired::Tired(Thread *s, int w)
{
    sleepy = s;
    wakeAt = w;
}

Thread* Tired::get_thread()
{
    return sleepy;
}

int Tired::get_time()
{
    return wakeAt;
}
