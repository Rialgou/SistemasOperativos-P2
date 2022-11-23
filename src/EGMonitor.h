#ifdef _EGMonitor_H_
#define _EGMonitor_H_
#include <pthread.h>

class EGMonitor {
private:

    pthread_mutex_t mutex;
    pthread_cond_t takeT;
    pthread_cond_t placeT;
    int activeE;
    int waitingE;

public:
    EGMonitor();
    ~EGMonitor();
    
};

#endif