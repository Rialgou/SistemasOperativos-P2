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
void EGMonitor::pickT(){
    pthread_mutex_lock(&mutex);
    waitingE++;
    while(takeShouldWait()){
        pthread_cond_wait(&takeT,&mutex);
    }
    waitingE--;
    activeE++;
    pthread_mutex_unlock(&mutex);
}
void EGMonitor::finishedPick(){
    pthread_mutex_lock(&mutex);
    activeE--;
    pthread_mutex_unlock(&mutex);
}
void EGMonitor::takeShouldWait(){
    return(activeG > 0 || waitingG > 0)
}