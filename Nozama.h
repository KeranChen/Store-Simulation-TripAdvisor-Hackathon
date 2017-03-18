/*
Nozama.h
Written by :Kaiyun Chen
Date: Feb 20,2017
This header file defines a Nozama class, which is the object that 
represent the whole simulation process.
it can preprocess the data, complete retriving  and packing the 
items from units, using 2 methods, and has a global clock, that keep
track of the timestamp

*/

#ifndef NOZAMA_H
#define NOZAMA_H

#include <string>

#include "Orderqueue.h"
#include "Parser.h"
#include "Time.h"
#include "Fetch.h"
#include "PackerManager.h"
#include "Statistitian.h"




using namespace std;

class Nozama {
public:
	Nozama(string &filename, string &method, int capacity);
	~Nozama();
	void run();

private:
	Orderqueue *shelves;
	Parser *fileParser;
	Time *clock;
    Fetch *fetcher;
    PackerManager *PM;
    Statistitian *statistitian;

	void load();
    void checkFetch();
    void checkPack();
    bool checkTerminate();
    void unloadToStatistian(int curTime);
    int string2int(std::string s);
    


};
#endif	