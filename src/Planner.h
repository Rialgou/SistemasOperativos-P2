#ifndef _Planner_H_
#define _Planner_H_
#include "Runqueue.h"
#include <mutex>
#include <thread>

class Planner {
private:
  Runqueue active;
  Runqueue expired;
  std::mutex activeM;
  std::mutex expiredM;
  int createTime(int a, int b);

public:
  Planner(int n, int a, int b);
  ~Planner();
  void execProccess();
  TThread getActiveProccess(int priority);
  bool activeEmpty();
  bool expiredEmpty();
  void printActive();
};

#endif
