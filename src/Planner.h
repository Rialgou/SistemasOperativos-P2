#ifndef _Planner_H_
#define _Planner_H_
#include <pthread.h>
#include "Runqueue.h"

class Planner {
private:
Runqueue active;
Runqueue expired;
pthread_mutex_t activeM;
pthread_mutex_t expiredM;

public:
    Planner(int n);
    ~Planner();
};

#endif