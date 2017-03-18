#include <iostream>
#include <string>
#include <climits>
#include "Order.h"

#include "Packer.h"
#include "PackerManager.h"
#include "Orderqueue.h"
#include "string2int.h"

using namespace std;

/**************************************Constructor***********************/
PackerManager::PackerManager(string &method, int capacity) {
    packerCapacity = capacity;
    if (method == "ROUND_ROBIN") {
        packerMethod = "Round Robin";
    } else {
        packerMethod = "Shortest Time";
    }
    packerarray = new Packer[packerCapacity];
    prevPackerId = -1;

}

PackerManager::~PackerManager() {
    delete[] packerarray;
}

/*
process new Order
input: Order new Order
output: void
get the new Order and distribute it to the right Packer
*/

void PackerManager::processOrder(Order newOrder) {
    int nextPackerId;
    if (packerMethod == "Round Robin") {
        nextPackerId = roundRobin();
    } else {
        nextPackerId = shortestTime();
    }
    packerarray[nextPackerId].load(newOrder);
    prevPackerId = nextPackerId;
}

/*
RoundRobin method to distribute newOrder
input: Order new Order
output: int  the index of the next packer that should take the newOrder
*/

int PackerManager::roundRobin() {
    if (prevPackerId == -1) {
        return 0;
    } else if (prevPackerId < packerCapacity - 1) {
        return prevPackerId + 1;
    } else if (prevPackerId == packerCapacity - 1) {
        return 0;
    } else {
        return -1;
    }
}


/*
ShortestTime method to distribute newOrder
input: Order new Order
output: int  the index of the next packer that should take the newOrder
*/

int PackerManager::shortestTime() {
    int min = INT_MAX;
    int candiId;
    int candiMin;
    for (int i = 0; i < packerCapacity; i++) {
        candiMin = packerarray[i].getTotal();
        if (candiMin == 0) {
            return i;
        } else if (candiMin < min) {
            min = candiMin;
            candiId = i;
        }
    }
    return candiId;

}

/*
Process the top Orders in All packers
input: nothing
output: void
*/

void PackerManager::processAllTop() {
    for (int i = 0; i < packerCapacity; i++) {
        //packerarray[i].print();
        packerarray[i].processTop();
    }
}

/*
check to see if all the packers are empty
input: nothing
output: void
if not all are empty return false
if all are empty return true
*/
bool PackerManager::packerEmpty() {
    for (int i = 0; i < packerCapacity; i++) {
        if (! packerarray[i].isEmpty()) {
            return false;
        } 
    }
    return true;
}


/*
check whether we should unload any orders from any packers
and unload them
input: nothing
output: the orderqueue of all the unloaded order of this round
*/

Orderqueue PackerManager::checkUnload() {
    Orderqueue unloadqueue;
    for (int i = 0; i < packerCapacity; i++) {
        if (packerarray[i].canUnload()) {
            Order candiOrder = packerarray[i].checkUnload();
            unloadqueue.push(candiOrder);
        }
    }
    return unloadqueue;
}

/*
print the orderqueue in every packer
input: nothing
output: void
*/

void PackerManager::print() {
    std::cout << "***********************  Packers ***********************\n";
    for (int i = 0; i < packerCapacity; i++) {
        packerarray[i].print();
    }
    std::cout << "*******************************************************\n";
}

