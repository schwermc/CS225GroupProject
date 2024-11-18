#include <iostream>
#include "Time.h"

Time::Time() {
	time(&startTime);
	hour = 0;
	minute = 0;
	second = 0;
}

void Time::finishTime() {
	time(&endTime);
	totalTimeInSeconds = difftime(endTime, startTime);

	if (totalTimeInSeconds >= 3600) {
		hour = totalTimeInSeconds / 3600;
		totalTimeInSeconds -= hour * 3600;
	}

	if (totalTimeInSeconds >= 60) {
		minute = totalTimeInSeconds / 60;
		totalTimeInSeconds -= minute * 60;
	}

	if (totalTimeInSeconds >= 0) {
		second = totalTimeInSeconds;
		totalTimeInSeconds -= second;
	}
}

ostream& operator<<(ostream &os, const Time &t) {
	os << "Game session was " << setfill('0') << setw(2) << t.hour << ":" << setfill('0') << setw(2) << t.minute << ":" << setfill('0') << setw(2)
	   << t.second << " long." << endl;
	return os;
}