#ifndef _Planner_H_
#define _Planner_H_
#include <thread>
#include <mutex>
#include "Runqueue.h"

class Planner {
private:
Runqueue active;
Runqueue expired;
std::mutex activeM;
std::mutex expiredM;
int createTime(int a,int b);

public:
    Planner(int n,int a,int b);
    ~Planner();
    void execProccess();
    TThread getActiveProccess();
    bool activeEmpty();
    bool expiredEmpty();
    void printActive();
};

#endif