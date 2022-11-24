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
int createTime(int a,int b);

public:
    Planner(int n,int a,int b);
    ~Planner();
    void printActive();
};

#endif