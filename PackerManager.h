#ifndef PACKERMANAGER_H
#define PACKERMANAGER_H

#include <string>
#include <iostream>

#include "Order.h"
#include "Orderqueue.h"
#include "Packer.h"

using namespace std;

class PackerManager {
public:
    PackerManager(string &method, int capacity);
    ~PackerManager();
    void processOrder(Order newOrder);
    void processAllTop();
    bool packerEmpty();
    Orderqueue checkUnload();
    void print();


private:
    Packer *packerarray;
    string packerMethod;
    int packerCapacity;
    int prevPackerId;
    int roundRobin();
    int shortestTime();


};
#endif