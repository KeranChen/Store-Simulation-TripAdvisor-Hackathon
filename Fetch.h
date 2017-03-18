#ifndef FETCH_H
#define FETCH_H

#include <string>
#include <iostream>

#include "Order.h"
#include "Orderqueue.h"

using namespace std;

class Fetch {
public:
    Fetch();
    ~Fetch();
    bool isEmpty();
    void load(Order newOrder);
    Order unload();
    void print();
    Order peek();
    void processTop();


private:
    Orderqueue *fetchqueue;
    


};
#endif