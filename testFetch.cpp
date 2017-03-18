#include <iostream>
#include "Order.h"
#include "Fetch.h"
#include "Orderqueue.h"

using namespace std;

int main() {
    std::cout << "test fetcher\n";
    Fetch fetcher;
    fetcher.print();
}