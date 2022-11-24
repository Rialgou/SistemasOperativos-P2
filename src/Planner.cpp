#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include "Planner.h"

Planner::Planner(int n,int a,int b){
    srand(time(NULL));
    int t;
    int priority = random()%10;
    TThread aux(priority,a,b);
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
void Planner::printActive(){
    active.printQueue();
}
int Planner::createTime(int a,int b){
    return rand() % b + a;
}
