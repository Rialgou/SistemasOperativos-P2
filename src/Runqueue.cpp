#include "Runqueue.h"
#include <iostream>
#include <vector>

using namespace std;

Runqueue::Runqueue() {
  // se limita el tamaño de la runqueue a 10 filas según su nivel de prioridad
  rq.resize(10);
}
Runqueue::~Runqueue() {
  // se vacia la runqueue
  rq.clear();
}
TThread Runqueue::getT(int priority) {
  // se guarda el elemento que esta al frente de la cola, se saca de la cola y
  // se retorna
  TThread aux = rq[priority].front();
  rq[priority].pop();
  return aux;
}
void Runqueue::pushT(int i, TThread v) {
  // se ingresa el proceso
  rq[i].push(v);
}
bool Runqueue::isEmpty() {
  // verifica en cada nivel si queda algún proceso
  for (int i = 0; i < rq.size(); i++) {
    if (!rq[i].empty())
      return false;
  }
  return true;
}

bool Runqueue::isPEmpty(int p) {
  // verifica si el nivel de prioridad actual tiene algun proceso 
  return rq.at(p).empty(); 
}
void Runqueue::printQueue() {
  // imprime la runqueue
  for (int i = 0; i < rq.size(); i++) {
    cout << "tiempos cola" << i;
    while (!rq[i].empty()) {
      cout << " -> " << rq[i].front().getId();
      rq[i].pop();
    }
    cout << endl;
  }
}
