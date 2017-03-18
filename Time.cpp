#include <iostream>
#include <exception>
#include <string>
#include "time.h"

using namespace std;

/**************************Constructor****************************/
Time::Time() {

	timeUnit = 1;
	curTime = 0;
}
/*************************Destructor*****************************/
Time::~Time() {


}

/*
get what cur time is
input: nothing
output: int
*/
int Time::getTime() {

	return curTime;

}

/*
add time
input: nothing
output: void
increment time by 1 time unit
*/

void Time::addTime(){
	curTime += timeUnit;
}