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

Planner::Planner(int n,int m, int a, int b) {
  // se inicializa el planner pasandole la cantidad de procesos (n) y los
  // intervalos de tiempo en los que se encontrara el tiempo de ejecución de los
  // procesos se crean n TThreads
  srand(time(NULL));
  int t;
  int priority;
  this -> eThreads = m;
  this -> eTCount = 0;
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
  // se inicializa prioridad en 0 
  // ejecutar hasta que se quiera parar el proceso
  while(1){
    if(expired.isEmpty() && active.isEmpty()){
      cout<<"ambas runqueues estan vacias"<<endl;
    }
    int p = 0;
    // obtener proceso de la runqueue activa
    if(expired.isEmpty()){
      cout<<"runqueue expirada esta vacia"<<endl;
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
          expiredM.lock();
          cout<<"trabajando en proceso n°"<<aux.getId()<<" de active queue, prioridad: "<<aux.getPriority()-1 <<endl;
          expired.pushT(p+1, aux);
          expiredM.unlock();
        }
        // poner dentro de runqueue expired
      } while (p < 10);
    }
    // comprobar que todas las hebras pasaron por la runqueue activa
    eCount.lock();
    eTCount++;
    cout<<"m++: "<<eTCount<<endl;
    eCount.unlock();
    while(1){
      if(eTCount == eThreads) break;  
    }
    p=0;
    // obtener proceso de la runqueue expirada
    if(active.isEmpty()){
      cout<<"runqueue activa esta vacia"<<endl;
      do {
        if (expired.isPEmpty(p)) {
          p++;
          continue;
        }
        expiredM.lock();
        TThread aux = expired.getT(p);
        expiredM.unlock();
        // ejecutar programa por un quantum
        this_thread::sleep_for(chrono::milliseconds(200));
        // disminuir tiempo de ejecucion
        aux.setTime(aux.getTime() - 200);
        // si tiempo de ejecución nuevo < 0 se elimina el proceso 
        if(aux.getTime()>0){
          aux.setPriority(p+1);
          activeM.lock();
          cout<<"trabajando en proceso n°"<<aux.getId()<<" de expired queue, prioridad: "<<aux.getPriority()-1 <<endl;
          active.pushT(p+1, aux);
          activeM.unlock();
        }
        // poner dentro de runqueue expired
      } while (p < 10);
    }
    // comprobar que todas las hebras pasaron por la runqueue expirada
    eCount.lock();
    eTCount--;
    cout<<"m--: "<<eTCount<<endl;
    eCount.unlock();
    while(1){
      if(eTCount==0) break;
    }
  }
}
void Planner::printActive() {
  // imprime la runqueue activa
  // active.printQueue();
}
int Planner::createTime(int a, int b) {
  // crea un nuevo tiempo respetando los intervalos dados
  return rand() % b + a;
}
