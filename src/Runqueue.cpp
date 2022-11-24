#include <iostream>
#include <vector>
#include "Runqueue.h"

using namespace std;

Runqueue::Runqueue(){
    rq.resize(10);
}
Runqueue::~Runqueue(){
    rq.clear();
}
TThread Runqueue::getT(int i){
    TThread aux = rq[i].front();
    rq[i].pop();
    return aux;
}
void Runqueue::pushT(int i, TThread v){
    rq[i].push(v);
}
bool Runqueue::isEmpty(){
    for(int i=0;i<rq.size();i++){
        if(!rq[i].empty()) return false;
    }
    return true;
}
void Runqueue::printQueue(){
    /*for(int i=0;i<rq.size();i++){
        cout <<"cola"<<i;
        while(!rq[i].empty()){
            cout<<" -> "<<rq[i].front();
            rq[i].pop();
        }
        cout<<endl;
    }*/
}