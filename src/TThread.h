#ifndef _TThread_H_
#define _TThread_H_
class TThread {
private:
    int a,b;
    int t;
    int priority;
public:
    TThread(int t,int a,int b);
    ~TThread();
    void newTime(int dif);
    void setPriority(int priority);
};

#endif