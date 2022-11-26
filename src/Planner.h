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
  std::mutex eCount;
  int eThreads;
  int eTCount;
  int createTime(int a, int b);

public:
  Planner(int n,int m, int a, int b);
  ~Planner();
  void execProccess();
  void printActive();
};

#endif
