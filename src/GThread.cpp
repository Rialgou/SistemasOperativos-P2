#include "GThread.h"
#include <iostream>
#include <random>
#include <vector>

using namespace std;

GThread::GThread() {
}
GThread::~GThread() {
    delete this;
}