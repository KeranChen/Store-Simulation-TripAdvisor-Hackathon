#ifndef PACKER_H
#define PACKER_H

#include <string>
#include <iostream>

#include "Order.h"
#include "Orderqueue.h"

using namespace std;

class Packer {
public:
    Packer();
    ~Packer();
    void load(Order newOrder);
    void unload();
    void processTop();
    bool isEmpty();
    int getTotal();
    Order checkUnload();
    void print();
    bool canUnload();
private:
    Orderqueue *packqueue;
    int totalTime;
    

};
#endif