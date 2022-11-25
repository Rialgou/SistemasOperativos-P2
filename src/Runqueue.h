#ifndef _Runqueue_H_
#define _Runqueue_H_

#include "TThread.h"
#include <queue>
class Runqueue {
private:
  std::vector<std::queue<TThread>> rq;

public:
  Runqueue();
  ~Runqueue();
  TThread getT(int priority);
  void pushT(int i, TThread v);
  bool isEmpty();
  bool isPEmpy(int p);
  void printQueue();
};

#endif
