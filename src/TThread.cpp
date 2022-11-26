#include "TThread.h"
#include <iostream>
#include <random>
#include <vector>

using namespace std;

TThread::TThread(int a, int b,int id) {
  // se inicializa el proceso con su prioridad y tiempo de ejecución
  // se le pasan los intervalos a,b
  srand(time(NULL));
  this->a = a;
  this->b = b;
  this->t = a + rand() % ((b+1)- a);
  this->priority = 0;
  this->id = id;
  
}
TThread::~TThread() {}
void TThread::setTime(int t) {
  // cambia el tiempo
  this->t = t;
}
void TThread::setPriority(int priority) {
  // sete prioridad
  if(priority >=9){
    this->priority =9;
  }
  else{
    this->priority = priority;
  }
  
}
void TThread::setId(int id){
  this->id = id;
}
int TThread::getTime() {
  // retorna tiempo
  return t;
}
int TThread::getPriority() {
  // retorna prioridad
  return priority;
}
int TThread::getId(){
  // retorna la id del proceso
  return id;
}
