#ifndef _TThread_H_
#define _TThread_H_
class TThread {
private:
    int t;
    int priority;
public:
    TThread();
    ~TThread();
    void setTime(int t);
    void setPriority(int priority);
};

#endif