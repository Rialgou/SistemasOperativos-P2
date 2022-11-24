#include <iostream>
#include <vector>
#include "Runqueue.h"

using namespace std;

Runqueue::Runqueue(){
    //se limita el tamaño de la runqueue a 10 filas según su nivel de prioridad
    rq.resize(10);
}
Runqueue::~Runqueue(){
    //se vacia la runqueue
    rq.clear();
}
TThread Runqueue::getT(int i){
    //se guarda el elemento que esta al frente de la cola, se saca de la cola y se retorna 
    TThread aux = rq[i].front();
    rq[i].pop();
    return aux;
}
void Runqueue::pushT(int i, TThread v){
    //se ingresa el proceso
    rq[i].push(v);
}
bool Runqueue::isEmpty(){
    //verifica en cada nivel si queda algún proceso
    for(int i=0;i<rq.size();i++){
        if(!rq[i].empty()) return false;
    }
    return true;
}
void Runqueue::printQueue(){
    //imprime la runqueue
    for(int i=0;i<rq.size();i++){
        cout <<"tiempos cola"<<i;
        while(!rq[i].empty()){
            cout<<" -> "<<rq[i].front().getTime();
            rq[i].pop();
        }
        cout<<endl;
    }
}