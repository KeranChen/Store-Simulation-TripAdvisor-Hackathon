#include <iostream>
#include <exception>
#include <string>

//#include "Parser.h"
#include "Order.h"
#include "Orderqueue.h"
#include "Nozama.h"
#include "Parser.h"





/**************************************Constructor*****************************/
Nozama::Nozama(string &filename, string &method, int capacity) {
	shelves = new Orderqueue();
	fileParser = new Parser(filename);
	clock = new Time();
	fetcher = new Fetch();
	PM = new PackerManager(method, capacity);
	statistitian = new Statistitian();
	
	

	
}
/*******************************Destructor**********************************/
Nozama::~Nozama() {
	delete shelves;
	delete fileParser;
	delete clock;
	delete fetcher;
	delete PM;
	delete statistitian;
	
}	

/*
run 
input: nothing
output: void
start the whole simulation process
*/
void Nozama::run(){
	
	load();

	while (true) {
		checkFetch();
		checkPack();
		clock->addTime();
		if(checkTerminate()) {
			break;
		}
	}
	statistitian->report();
	

	return;
}	


/*
load
input:string filename
output: void
parse in all the orders from files and put them into shelves (Orderqueue)

*/

void Nozama::load(){
	
	//Order NewOrder = fileParser->read_order();

	while(!fileParser->is_done()) {
		
	    Order newOrder = fileParser->read_order();
		shelves->push(newOrder);
		
	}
	Order newOrder = fileParser->read_last_order();
	shelves->push(newOrder);
	//if (shelves->count() > 1)
    /*
	Order newOrder = fileParser->read_order();
	shelves->push(newOrder);

	*/
	shelves->print();
	

	return;
}



/*
check whether we need to load a new order on to fetcher
input: nothing
output: void
*/

void Nozama::checkFetch(){
	fetcher->processTop(); 
	
	if (!shelves->isEmpty()) {
		Order candiOrder = shelves->peek();
		if (candiOrder.arrival_timestamp <= clock->getTime()) {
		//if the candidate order has arrived
			shelves->poll();
			fetcher->load(candiOrder);
		}
	}
	
}

/*
check wehter we need to load a new order to packerManager
input: nothing
output: void

*/
void Nozama::checkPack() {
	PM->processAllTop();
	//PM->checkUnload();
	unloadToStatistian(clock->getTime());
	if (!fetcher->isEmpty()) {
		Order candiOrder = fetcher->peek();
	//PM->print();
		if (candiOrder.fetch_time_left >= candiOrder.fetch_duration ) {
		// poll the candiOrder from fetcher
		// let PM to distribute it to right Packer
			Order newOrder = fetcher->unload();
			PM->processOrder(newOrder);
			
		}
    }
	
}

/*
check whether we should unload any order from packers
and give them to statistitian 
input: nothing
output: void
*/
void Nozama::unloadToStatistian(int curTime) {
	statistitian->process(PM->checkUnload(), curTime);
}


/*
check wether we should terminate the whole simulation
check wheter shelves is empty, check fecther is empty,
and check whether packers are all empty
input: nothing
output: boolean
*/

bool Nozama::checkTerminate() {
	if (shelves->isEmpty() && fetcher->isEmpty() && \
		PM->packerEmpty()){
		return true;
	} else {
		return false;
	}
}



















