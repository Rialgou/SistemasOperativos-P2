#include "TThread.h"
#include <iostream>
#include <random>
#include <vector>

using namespace std;

TThread::TThread(int a, int b) {
  // se inicializa el proceso con su prioridad y tiempo de ejecución
  // se le pasan los intervalos a,b
  srand(time(NULL));
  this->a = a;
  this->b = b;
  this->t = rand() % b + a;
  this->priority = 0;
}
TThread::~TThread() {}
void TThread::setTime(int t) {
  // cambia el tiempo
  this->t = t;
}
void TThread::newTime(int dif) {
  // servira para ver la diferencia de tiempo en base al quantum
  this->t -= dif;
}
void TThread::setPriority(int priority) {
  // sete prioridad
  this->priority = priority;
}
int TThread::getTime() {
  // retorna tiempo
  return t;
}
int TThread::getPriority() {
  // retorna prioridad
  return priority;
}
