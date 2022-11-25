#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include "Planner.h"

Planner::Planner(int n,int a,int b){
    //se inicializa el planner pasandole la cantidad de procesos (n) y los intervalos 
    //de tiempo en los que se encontrara el tiempo de ejecución de los procesos
    //se crean n TThreads
    srand(time(NULL));
    int t;
    int priority;
    TThread aux(a,b);
    for(int i=0;i<n;i++){
        active.pushT(aux.getPriority(),aux);
        priority = random()%10;
        aux.setPriority(priority);
        t = createTime(a,b);
        aux.setTime(t);
    }
}
Planner::~Planner(){

}
TThread Planner::getActiveProccess(){
    return active.getT();
}
bool Planner::activeEmpty(){
    return active.isEmpty();
}
bool Planner::expiredEmpty(){
    return expired.isEmpty();
}
void Planner::printActive(){
    //imprime la runqueue activa
    active.printQueue();
}
int Planner::createTime(int a,int b){
    //crea un nuevo tiempo respetando los intervalos dados
    return rand() % b + a;
}
