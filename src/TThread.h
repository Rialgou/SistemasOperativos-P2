#ifndef _TThread_H_
#define _TThread_H_

class TThread {
private:
  int a, b;
  int t;
  int priority;
  int id;

public:
  TThread(int a, int b,int id);
  ~TThread();
  void setTime(int t);
  void setPriority(int priority);
  void setId(int id);
  int getTime();
  int getPriority();
  int getId();
};

#endif
