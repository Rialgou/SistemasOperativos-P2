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
  int a,b;
  int eTCount;
  int createTime(int a, int b);

public:
  Planner(int n, int a, int b);
  ~Planner();
  void execProccess(int m);
  void genProccess(int m);
};

#endif
