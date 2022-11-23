#ifndef _Runqueue_H_
#define _Runqueue_H_
#include <vector>
#include <stack>

class Runqueue{
private:
    std::vector<std::stack<int>> rq;
public:
    Runqueue();
    ~Runqueue();
    int getT(int i);
    void pushT(int i,int v);
    bool isEmpty();
    void printQueue();
};

#endif