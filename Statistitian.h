#ifndef STATISTITIAN_H
#define STATISTITIAN_H

#include <iostream>
#include "Order.h"
#include "Orderqueue.h"
using namespace std;

class Statistitian {
public:
    Statistitian();
    ~Statistitian();
    void process(Orderqueue unloadqueue, int curTime);
    void report();

private:
    int min;
    int max;
    int mean;
    int totalTime;
    int orderCount;
    Orderqueue *records;
    void makeRecord(Order newOrder, int curTime);
};
#endif

