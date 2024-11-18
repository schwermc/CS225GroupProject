#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

class Time {
private:
	time_t startTime, endTime;
	long totalTimeInSeconds;
	int hour, minute, second;
public:
	Time();
	void finishTime();
	friend ostream& operator<<(ostream&, const Time&);
};

#endif