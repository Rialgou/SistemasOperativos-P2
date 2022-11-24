#ifndef _EGMonitor_H_
#define _EGMonitor_H_
#include <pthread.h>

class EGMonitor {
private:

    pthread_mutex_t mutex;
    pthread_cond_t takeT;
    pthread_cond_t placeT;
    pthread_cond_t createT;
    int activeE;
    int waitingE;
    int activeG;
    int waitingG;
    bool takeShouldWait();
    bool leftShouldWait();
    bool createShouldWait();

public:
    EGMonitor();
    ~EGMonitor();
};

#endif