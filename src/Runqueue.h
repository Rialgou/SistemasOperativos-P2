#ifndef _Runqueue_H_
#define _Runqueue_H_
#include <queue>
#include "TThread.h"
class Runqueue{
private:
    std::vector<std::queue<TThread>> rq;
public:
    Runqueue();
    ~Runqueue();
    TThread getT(int i);
    void pushT(int i,TThread v);
    bool isEmpty();
    void printQueue();
};

#endif