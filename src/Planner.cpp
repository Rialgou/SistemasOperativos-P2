#include "Planner.h"
#include "TThread.h"
#include <chrono>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <thread>
#include <time.h>
#include <unistd.h>

using namespace std;

Planner::Planner(int n, int a, int b) {
  // se inicializa el planner pasandole la cantidad de procesos (n) y los
  // intervalos de tiempo en los que se encontrara el tiempo de ejecución de los
  // procesos se crean n TThreads
  srand(time(NULL));
  int t;
  int priority;
  TThread aux(a, b);
  for (int i = 0; i < n; i++) {
    active.pushT(aux.getPriority(), aux);
    priority = random() % 10;
    aux.setPriority(priority);
    t = createTime(a, b);
    aux.setTime(t);
  }
}
Planner::~Planner() {}
void Planner::execProccess() {
  // obtener proceso
  int p = 0;
  do {
    if (active.isPEmpy(p)) {
      p++;
      continue;
    }

    activeM.lock();
    TThread aux = active.getT(p);
    activeM.unlock();

    // dejarle eejcutar programa un quantum
    this_thread::sleep_for(chrono::milliseconds(200));
    // disminuir tiempo de ejecucion
    aux.setTime(aux.getTime() - 200);
    // poner dentro de runqueue expired
    expiredM.lock();
    expired.pushT(p, aux);
    expiredM.unlock();

  } while (p < 10);
  cout << "print expired" << endl;
  expiredM.lock();
  expired.printQueue();
  expiredM.unlock();
}
TThread Planner::getActiveProccess(int priority) {
  return active.getT(priority);
}
bool Planner::activeEmpty() { return active.isEmpty(); }
bool Planner::expiredEmpty() { return expired.isEmpty(); }
void Planner::printActive() {
  // imprime la runqueue activa
  // active.printQueue();
}
int Planner::createTime(int a, int b) {
  // crea un nuevo tiempo respetando los intervalos dados
  return rand() % b + a;
}
