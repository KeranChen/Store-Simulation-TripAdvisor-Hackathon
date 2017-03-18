#include <iostream>
#include "Order.h"
#include "Orderqueue.h"
#include "Fetch.h"

using namespace std;

/*********************Constructor***************************/

Fetch::Fetch(){
    fetchqueue = new Orderqueue();
}

Fetch::~Fetch(){
    delete fetchqueue;
}

/*
Check to see whether fetcher is empty
input: nothing
output: boolean
*/

bool Fetch::isEmpty() {
    return fetchqueue->isEmpty();
}

/*
print out all the orders in the fetcher so far
input: nothing
output: void
*/

void Fetch::print(){
    std::cout << "*******************In Fetcher ***********************\n ";
    fetchqueue->print();
    std::cout << "*****************************************************\n";
}

/*
load new Order onto fetcher
input: Order newOrder
output: void
*/

void Fetch::load(Order newOrder) {
   
    fetchqueue->push(newOrder);


}

/*
unload the top Order out
poll the top order from the fetchqueue, and return the topOrder
input: nothing
output: Order the top Order on the Queue
*/

Order Fetch::unload() {
    Order outOrder = fetchqueue->peek();
    fetchqueue->poll();
    return outOrder;
}

/*
peek the top Order on the fetchqueue
without polling it from fetchqueue
input: nothing
output: Order the top Order
*/

Order Fetch::peek(){
    return fetchqueue->peek();
}

/*
process the top order 
input: nothing
output: void
if fetcher not empty
just decrease the fetch_time_left of the top order
*/

void Fetch::processTop() {
    if (!isEmpty()) {
        Order *topOrder = fetchqueue->peekRef();
        topOrder->fetch_time_left += 1;
        return;
    }
}
























