#include <iostream>
#include <vector>
#include <random>
#include "TThread.h"

using namespace std;

TThread::TThread(int priority,int a,int b){
    srand(time(NULL));
    this->a =a;
    this->b =b;
    this->t = rand() % b + a;
    this->priority = priority;
}
TThread::~TThread(){
    
}
void TThread::setTime(int dif){
    this->t =dif; 
}
void TThread::setPriority(int priority){
    this->priority = priority;
}
int TThread::getTime(){
    return t;
}
int TThread::getPriority(){
    return priority;
}
