#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include "EGMonitor.h"

EGMonitor::EGMonitor(){
    activeE = 0;
    waitingE = 0;
    activeG = 0;
    waitingG = 0;
}
