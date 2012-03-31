#include <iostream>
#include <ctime>
#include <string>
#include <stdio.h>
#include "count.h"

using namespace std; 

 int countUp(string stopCount) { // This method has a bug... Need to stop the upcount after 
				 // the stopCount has been reached.  It never quits up counting
	time_t rawtime;
	struct tm * currentTime;
	string blue;
	string hours_seconds;
	string prev_hours_seconds = " ";
	
	while(1){
	time ( & rawtime);
	currentTime = localtime(&rawtime);
	blue = asctime(currentTime);
	hours_seconds  = blue.substr(11,8);
	if(hours_seconds != prev_hours_seconds && prev_hours_seconds!=stopCount){
		prev_hours_seconds = hours_seconds;
		cout << hours_seconds << endl;
	
	}
	}

//cout <<  "The time to count to is now " << stopCount << endl;
return 0;
}

int stopWatch(int waitSeconds){
	//int seconds;
	clock_t endwait;
	endwait = clock()+waitSeconds*CLOCKS_PER_SEC;
	int value = -1;
	while(clock() < endwait){
	 	if(clock()/CLOCKS_PER_SEC !=value){
			value = clock()/CLOCKS_PER_SEC;
			cout << clock()/CLOCKS_PER_SEC << endl;
		}
	}
	return 0;
}
