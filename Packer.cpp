#include <iostream>
#include "Order.h"
#include "Orderqueue.h"
#include "Packer.h"

using namespace std;

/*******************************Constructor****************************/

Packer::Packer() {
    packqueue = new Orderqueue();
    totalTime = 0;

}

Packer::~Packer() {
    delete packqueue;
}

/*
load new Order to Packer
input: Order new Order
output: void
*/

void Packer::load(Order newOrder) {
    packqueue->push(newOrder);
    totalTime += newOrder.pack_duration;
}

/*
unload the top order from the packqueue
input: nothing
output: void
*/

void Packer::unload() {
    packqueue->poll();

}

/*
check whether this packer is empty or not
input: nothing
output: boolean
*/

bool Packer::isEmpty() {
    return packqueue->isEmpty();
}

/*
process the top order on packqueue
input: nothing
output: void
increse the pack time left on the top order
and also decrease the total Time of this packer
*/
void Packer::processTop() {
    if (!isEmpty()) {
        Order *topOrder = packqueue->peekRef();
        topOrder->pack_time_left += 1;
        totalTime -= 1;
        return;
    }
}

/*
get the total time left for this packer
input: nothing
output: int the total Time

*/

int Packer::getTotal() {
    return totalTime;
}

/*
unload the topOrder
intput: nothing
output: void
*/
Order Packer::checkUnload() {
    Order topOrder = packqueue->peek();
    unload();
    return topOrder;
        
    

}

/*
print the orderqueue of this packer
input: nothing
output: void
*/
void Packer::print(){
    packqueue->print();
}

/*
check whether we can unload the topOrder
input: nothing
output: boolean
*/
bool Packer::canUnload(){
    if (!isEmpty()) {
        Order *topOrder = packqueue->peekRef();
        if (topOrder->pack_time_left >= topOrder->pack_duration) {
            return true;
        }
    }
    return false;
}












