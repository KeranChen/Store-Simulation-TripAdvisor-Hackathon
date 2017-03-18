#include <iostream>
#include <string>
#include "Order.h"
#include "PackerManager.h"
#include "Packer.h"
#include "string2int.h"

using namespace std;

int main(int argc, char *argv[]) {
    std::cout << "test PackerManager\n";
    std::string method(argv[1]);
    int capacity = string2int(argv[2]);
    PackerManager PM(method, capacity);
    return argc;
    
}