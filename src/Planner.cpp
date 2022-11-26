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
  TThread aux(a, b,0);
  for (int i = 0; i < n; i++) {
    active.pushT(aux.getPriority(), aux);
    priority = 0;
    aux.setId(i+1);
    aux.setPriority(priority);
    t = createTime(a, b);
    aux.setTime(t);
  }
}
Planner::~Planner() {}
void Planner::execProccess() {
  // obtener proceso de la runqueue activa
  int p = 0;
  do {
    if (active.isPEmpty(p)) {
      p++;
      continue;
    }

    activeM.lock();
    TThread aux = active.getT(p);
    activeM.unlock();
    // ejecutar programa por un quantum
    this_thread::sleep_for(chrono::milliseconds(200));
    // disminuir tiempo de ejecucion
    aux.setTime(aux.getTime() - 200);
    // si tiempo de ejecución nuevo < 0 se elimina el proceso 
    if(aux.getTime()>0){
      aux.setPriority(p+1);
      cout<<"trabajando en proceso n°"<<aux.getId()<<endl;
      expiredM.lock();
      expired.pushT(p+1, aux);
      expiredM.unlock();
    }
    // poner dentro de runqueue expired
  } while (p < 10);
  // obtener proceso de la runqueue expirada
  p = 0;
  do {
    if (expired.isPEmpty(p)) {
      p++;
      continue;
    }

    expiredM.lock();
    TThread aux = expired.getT(p);
    expiredM.unlock();
    // si tiempo de ejecución nuevo < 0 se elimina el proceso 
    activeM.lock();
    active.pushT(p, aux);
    activeM.unlock();
    // poner dentro de runqueue expired
  } while (p < 10);
  cout<<"print expired"<<endl;
  expiredM.lock();
  expired.printQueue();
  expiredM.unlock();
  cout<<"print active"<<endl;
  activeM.lock();
  active.printQueue();
  activeM.unlock();
}
void Planner::printActive() {
  // imprime la runqueue activa
  // active.printQueue();
}
int Planner::createTime(int a, int b) {
  // crea un nuevo tiempo respetando los intervalos dados
  return rand() % b + a;
}
