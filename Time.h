/*
time.h
Written by :Kaiyun Chen
Date: Feb 20,2017
This header file defines a time class, which is the object that represents
time

*/

#ifndef TIME_H
#define TIME_H


using namespace std;

class Time {
public:
    /*default constructor for time
    start time at 0*/
    Time();
    /*destructor for time class*/
    ~Time();
    /*return what time is now*/
    int getTime();
    /*increment time by 1 unit*/
    void addTime();


private:
    /*represnt time unit*/
    int timeUnit;

    /*represent current time*/
    int curTime;
};

#endif