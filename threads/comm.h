#ifndef COMM_H
#define COMM_H

#include "thread.h"
#include "synch.h"
#include "system.h"
#include <vector>

void Send(int port, int msg);

void Receive(int port, int* msg);


#endif 




