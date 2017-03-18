#include <iostream>
#include <climits>
#include "Order.h"
#include "Statistitian.h"
#include "Orderqueue.h"


using namespace std;

/**************************Constructor****************************/
Statistitian::Statistitian(){
    min = INT_MAX;
    max = INT_MIN;
    mean = 0;
    totalTime = 0;
    orderCount = 0;
    records = new Orderqueue();
}

Statistitian::~Statistitian() {
    delete records;
}

/*
process the unloadqueue, and update all the statistics
input: reference for the unloadqueue, the current time
output: void
*/

void Statistitian::process(Orderqueue unloadqueue, int curTime) {
    while (!unloadqueue.isEmpty()) {
        makeRecord(unloadqueue.peek(), curTime);
        unloadqueue.poll();
    }

}

/*
process every single unloaded order
input: order, int current time
ouput: void
*/

void Statistitian::makeRecord(Order newOrder, int curTime) {
   
    newOrder.leave_timestamp = curTime;
    int elapsedTime = newOrder.leave_timestamp - newOrder.arrival_timestamp;
    if(elapsedTime < min) {
        min = elapsedTime;
    }
    if (elapsedTime > max) {
        max = elapsedTime;
    }
    totalTime += elapsedTime;
    orderCount += 1;
    records->push(newOrder);


}

/*
print the result the clint wants
summarize the whole simulation, provides the statistics
input: nothing
output: void
*/
void Statistitian::report(){
    while(!records->isEmpty()) {
        Order curOrder = records->peek();
        records->poll();
        std::cout << "<Order("
                  << curOrder.id 
                  << ") arrival_timestamp = "
                  << curOrder.arrival_timestamp
                  << " fetch_duration = "
                  << curOrder.fetch_duration
                  << " pack_duration = "
                  << curOrder.pack_duration
                  << " total_time = "
                  << curOrder.leave_timestamp - curOrder.arrival_timestamp
                  << ">\n";
    }
    std::cout << "min elapsed time "
              << min
              << " minutes\n";
    std::cout << "max elapsed time "
              << max
              << " minutes\n";
    std::cout << "mean elapsed time "
              << totalTime / orderCount
              << " minutes\n";
    std::cout << orderCount
              << " orders processed\n";

}

/*
check whether the order is Null
input: Order newOrder
output: boolean

*/














