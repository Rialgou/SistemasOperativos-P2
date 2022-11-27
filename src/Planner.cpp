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
  int t;
  int priority;
  this->a=a;
  this->b=b;
  this -> eTCount = 0;
  TThread aux(a, b,0);
  for (int i = 0; i < n; i++) {
    active.pushT(aux.getPriority(), aux);
    priority = random() % 10 ;
    aux.setId(i+1);
    aux.setPriority(priority);
    t = createTime(a, b);
    aux.setTime(t);
  }
}
Planner::~Planner() {
}
void Planner::execProccess(int m) {
  // se ejecuta el proceso 
  while(1){
    // se inicializa la prioridad con 0 
    int p = 0;
    // obtener proceso de la runqueue activa
      // se busca un nivel donde se encuentre algun proceso
    do {
      activeM.lock();
      if (active.isPEmpty(p)) {
        p++;
        activeM.unlock();
        continue;
      }
      //se obtiene ese proceso 
      TThread aux = active.getT(p);
      activeM.unlock();
      // se ejecuta el proceso por un quantum
      // disminuir tiempo de ejecucion
      // si tiempo de ejecución nuevo es mayor que 0 se baja la prioridad y se ingresa a la runqueue 
      // expirada 
      if(aux.getTime() - 200 > 0){
        this_thread::sleep_for(chrono::milliseconds(200));
        aux.setTime(aux.getTime() - 200);
        aux.setPriority(p+1);
        expiredM.lock();
        cout<<"trabajando en proceso n°"<<aux.getId()<<" de active queue, nueva prioridad: "<<aux.getPriority()<<" tiempo restante: "<<aux.getTime() <<endl;
        expired.pushT(p+1, aux);
        expiredM.unlock();
      }else {
        this_thread::sleep_for(chrono::milliseconds(aux.getTime()));
        expiredM.lock();
        cout<<"proceso n°"<<aux.getId()<<" se ha completado con exito! sacado de active queue "<<endl;
        expiredM.unlock();
      }
    } while (p < 10);
    // se suma al contador de hebras que pasaron por la runqueue activa
    eCount.lock();
    eTCount ++;
    //cout<<"m++: "<<eTCount<<endl;
    eCount.unlock();
    // las hebras esperan hasta que todas terminen de pasar por la runqueue activa
  
    while(1){
      
      if(eTCount == m){
        this_thread::sleep_for(chrono::milliseconds(200));
        break; 
      }  
    }
    // se re inicializa la prioridad a 0
    p=0;
    // obtener proceso de la runqueue expirada
      // se busca en los niveles de la runqueue expirada hasta encontrar un proceso, por orden de prioridad
    do {
      expiredM.lock();
      if (expired.isPEmpty(p)) {
        p++;
        expiredM.unlock();
        continue;
      }
      // se saca el proceso de la runqueue
      TThread aux = expired.getT(p);
      expiredM.unlock();
      // se ejecuta el proceso por un quantum
      // disminuir tiempo de ejecucion
      // si tiempo de ejecución nuevo > 0 se le baja la prioridad al proceso y se ingresa en la runqueue activa 
      if(aux.getTime()- 200 > 0){
        this_thread::sleep_for(chrono::milliseconds(200));
        aux.setTime(aux.getTime() - 200);
        aux.setPriority(p+1);
        activeM.lock();
        cout<<"trabajando en proceso n°"<<aux.getId()<<" de expired queue, prioridad nueva: "<<aux.getPriority()<<" tiempo restante: "<<aux.getTime() <<endl;
        active.pushT(p+1, aux);
        activeM.unlock();
      }else{
        this_thread::sleep_for(chrono::milliseconds(aux.getTime()));
        expiredM.lock();
        cout<<"proceso n°"<<aux.getId()<<" se ha completado con exito! sacado de expired queue "<<endl;
        expiredM.unlock();      
      }
    } while (p < 10);
    // se tiene registro de que procesos pasaron por la runqueue expirada
    eCount.lock();
    eTCount--;
    //cout<<"m--: "<<eTCount<<endl;
    eCount.unlock();
    // los procesos esperan hasta que todos hayan pasado por la runqueue expirada
    while(1){
      if(eTCount == 0){
        this_thread::sleep_for(chrono::milliseconds(200));
        break;
      } 
    }
  }
}
int Planner::createTime(int a, int b) {
  // crea un nuevo tiempo respetando los intervalos dados
  return rand() % b + a;
}
void Planner::genProccess(int n){
  // proceso que utilizara la hebra G para crear procesos cada 5 segundos de manera
  // se creara una cantidad de procesos aleatorios entre 1 y 10 y se pushean a la runqueue activa
  int cantProccess;
  int cont =n;
  while(1){
    cantProccess = random() % 10 + 1;
    this_thread::sleep_for(chrono::seconds(5));
    activeM.lock();
    for(int i=0;i<cantProccess;i++){
        cont++;
        cout<<"creando proceso n°"<<cont<<endl;
        TThread aux(a,b,cont);
        active.pushT(aux.getPriority(),aux);
    }
    activeM.unlock(); 
  }
}