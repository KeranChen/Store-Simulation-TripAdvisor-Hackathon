/*
OrderQueue.cpp

Implementation for OrderQueue class
Use double LinkedList

*/

#include <iostream>
#include <algorithm>
#include "Orderqueue.h"
#include "Order.h"
using namespace std;

/*******************Constructor*************/
/*
default constructor
input: nothing

*/
Orderqueue::Orderqueue() {
    headOrder = NULL;
    tailOrder = NULL;
    orderCount = 0;

}

/*destructor
destroys/deletes/recycles the
      heap-allocated data in the current list*/
Orderqueue::~Orderqueue() {
    while (not isEmpty()) {
        deleteHead();
    }

}

/*  determine whether OrderQueue is empty
takes no parameters and returns a
      boolean value that is true if this specific instance of the
      OrderQueue class is empty and false otherwise*/ 
bool Orderqueue::isEmpty() {
    if (orderCount == 0) {
        return true;
    } else {
        return false;
    }
}


/*
delete the first element
intput: no input
output : void
assumption: this OrderQueue is not null
delete the first node*/
void Orderqueue::deleteHead() {
    Orderqueue::OrderNode *tmp = headOrder;
    headOrder = headOrder->next;
    
    delete tmp;
    orderCount--;
}

/*create a new OrderNode
 Input: int id, int arrival, int fetch, int pack time
 Output : a OrderNode pointer
 it creates a new OrderNode with respective order infomation 
 nex = NULL, prev = NULL*/
Orderqueue::OrderNode *Orderqueue::newOrderNode(Order newOrder) {
    OrderNode *newNode = new Orderqueue::OrderNode();
    newNode->order = newOrder;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

/*push : add a new orderNode to the front
takes id, arrival, fetch and pack time as input and has
      a void return type.  It inserts the given new element in front
      of the existing elements of the list*/ 
void Orderqueue::push(Order newOrder) {
    Orderqueue::OrderNode *newNode = newOrderNode(newOrder);
    if (isEmpty()) {
        headOrder = newNode;
        tailOrder = newNode;
    } else {
        newNode->next = headOrder;
        headOrder->prev = newNode;
        headOrder = newNode;
    }
    orderCount++;
}

/*pop from end
takes no parameters and has a
      void return type.  It removes the last element from the
      list.  If the list is empty it should throw an C++ "runtime_error" 
      exception initialized with the string "list_is_empty"
*/
void Orderqueue::poll() {
    if (isEmpty()) {
        throw runtime_error("OrderQueue_is_empty");
    }
    if (orderCount == 1) {
        deleteHead();
        
        return;
    }
    Orderqueue::OrderNode *tmp = tailOrder;
    tailOrder = tailOrder->prev;
    
    tailOrder->next = NULL; //this is important
    
    delete tmp;
    orderCount--;

}

/*peek from end

takes no parameters and will retern an order
it return the order in the last orderNode, without polling it out
from OrderQueue*/

Order Orderqueue::peek() {
    if (isEmpty()) {
        throw runtime_error("OrderQueue_is_empty");
    }
    return tailOrder->order;


}


/*
print order queue
input: notthing
output: void

*/
void Orderqueue::print() {
    std::cout << "[OrderQueue of size ";
    std::cout << orderCount;
    std::cout << " <<\n";
    Orderqueue::OrderNode *cur = headOrder;
    while(cur != NULL) {
      std::cout << "[ id: ";
      std::cout << cur->order.id;
      std::cout << " arrival time: ";
      std::cout << cur->order.arrival_timestamp; 
      std::cout << " fetch duration: ";
      std::cout << cur->order.fetch_duration;
      std::cout << " pack duration: ";
      std::cout << cur->order.pack_duration;  
      
      std::cout << " fetch left: ";
      std::cout << cur->order.fetch_time_left;
      std::cout << " pack left: ";
      std::cout << cur->order.pack_time_left;
      
      std::cout << " ] \n";

      cur = cur->next;
    }
    std::cout << ">>]\n";
}

/*
count the number of order on the orderqueue

input: nothing
output: int the count

*/

int Orderqueue::count(){

    return orderCount;
}

Order *Orderqueue::peekRef() {
  return &(tailOrder->order);
}



