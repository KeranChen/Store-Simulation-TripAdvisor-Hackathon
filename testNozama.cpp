#include <iostream>
#include <string>

#include <sstream>
#include <stdexcept>


#include "Nozama.h"
#include "Orderqueue.h"
#include "Order.h"

using namespace std;
using std::string;
using std::stringstream;
using std::runtime_error;

void test(string &filename, string &method, int capacity);
int string2int(std::string s);



int main(int argc, char *argv[]) {
	
	std::string filename(argv[1]);
    std::string method(argv[3]);
    std::string stringCapacity(argv[2]);
    int capacity = string2int( stringCapacity );
	test(filename, method, capacity);
	
    return argc;

}

void test(string &filename, string &method, int capacity) {
	
	Nozama store(filename, method, capacity);
	
    store.run();

}	
int string2int(std::string s) {
        stringstream ss(s);
        int result;

        ss >> result;
        if (ss.fail())
                throw(runtime_error("string2int: non-numeric value: " + s));

        return result;
}

