#ifndef _TThread_H_
#define _TThread_H_
class TThread {
private:
    int a,b;
    int t;
    int priority;
public:
    TThread(int a,int b);
    ~TThread();
    void setTime(int t);
    void newTime(int dif);
    void setPriority(int priority);
    int getTime();
    int getPriority();
};

#endif