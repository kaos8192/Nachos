#include "alarm.h"

//Thread can call this to go to sleep for a defined amount of time
void Alarm::GoToSleepFor(int howLong)
{
    // Stop interrupt
    IntStatus oldLevel = interrupt->SetLevel(IntOff);
    
    //Calculate times and bind some alarm stuff
    int x = howLong + stats->totalTicks;
    Tired *doze = new Tired(currentThread, x);

    //Push and sleep
    alarms.push_back(doze);
    currentThread->Sleep();
    
    // Interrupts on
    (void) interrupt->SetLevel(oldLevel);
}

