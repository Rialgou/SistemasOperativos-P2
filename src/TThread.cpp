#include <iostream>
#include <vector>
#include "TThread.h"

using namespace std;

TThread::TThread(int t,int priority){
    this->t = t;
    this->priority = priority;
}
void TThread::setTime(int t){
    this->t = t;
}
void TThread::setPriority(int priority){
    this->priority = priority;
}
