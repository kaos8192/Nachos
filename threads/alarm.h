#ifndef _ALARM_H_
#define _ALARM_H_

#include "timer.h"
#include "system.h"
#include "tired.h"

class Alarm
{
    public:
        Alarm(){};
        ~Alarm(){};
        void GoToSleepFor(int howLong);
};

#endif
