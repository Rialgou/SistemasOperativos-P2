#include <iostream>
#include <vector>
#include "Runqueue.h"

using namespace std;

Runqueue::Runqueue(){

}
int Runqueue::getT(int i){
    int aux = rq[i].top();
    rq[i].pop();
    return aux;
}
void Runqueue::pushT(int i, int v){
    rq[i].push(v);
}
bool Runqueue::isEmpty(){
    for(int i=0;i<rq.size();i++){
        if(!rq[i].empty()) return false;
    }
    return true;
}
void Runqueue::printQueue(){
    for(int i=0;i<rq.size();i++){
        cout <<"cola"<<i;
        while(!rq[i].empty()){
            cout<<" -> "<<rq[i].top();
            rq[i].pop();
        }
        cout<<endl;
    }
}