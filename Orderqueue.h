/*
OrderQueue.h
Written by :Kaiyun Chen
Date: Feb 22,2017
This header file defines an OrderQueue class, which is the object that 
represent the Queue stucture that stores order.
We can push order into OrderQueue, and poll order from OrderQueue

*/

#ifndef ORDERQUEUE_H
#define ORDERQUEUE_H
#include "Order.h"


using namespace std;

class Orderqueue {
public:
    /*default constructor initialize an empty OrderQueue*/
    Orderqueue();
    /*destructor*/
    ~Orderqueue();
    /*check if the queue is empty*/
    bool isEmpty();
    /*add a new order*/
    void push(Order newOrder);

    /*peek the next order, without poll it out*/
    Order peek();
    /*poll the last order out of OrderQueue, delete it*/
    void poll();

    /*count the number of item on orderqueue*/
    int count();

    /*print the orders in the Queue*/
    void print();

    /*peek the next order, just get its reference*/
    Order *peekRef();

private:
    struct OrderNode
    {
     Order order;
     OrderNode *next;
     OrderNode *prev;   
    };

    //the first orderNode in Queue
    OrderNode *headOrder;
    //the last orderNode in Queue
    OrderNode *tailOrder;
    //keep track the number of order in Queue
    int orderCount;
    //construct a new orderNode, from a given order
    OrderNode *newOrderNode(Order newOrder);
    //delete the head orderNode
    void deleteHead();



};

#endif