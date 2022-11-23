#ifdef _Runqueue_H_
#define _Runqueue_H_
#include <vector>
#include <stack>

class Runqueue{
private:
    vector<stack> rq;
public:
    Runqueue();
    ~Runqueue();
    int getT(int i);
    void pushT(int i);
    bool isEmpty();
};

#endif