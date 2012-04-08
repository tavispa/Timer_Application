#include <iostream>
#include <ctime>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "count.h"

using namespace std;

int main(){
	
	string timeStop;
	string numberOfTimer;	
	cout << "What type of timer do you need?" << endl;
	cout << "---------------------------------------" << endl;
	cout << endl;
	

	cout << "Press 1 for a timer to count up from the present time" << endl;
	cout << "Press 2 for a timer to count for specified amount of time" << endl;


        cin >> numberOfTimer;

	int timerNumber = atoi(numberOfTimer.c_str());
 
 	if(timerNumber == 1){  // This timer is buggy. Never stops upcounting time
	  	cout << "How many seconds do you want to count?" << endl;
		cin >> timeStop;
		
		countUp(timeStop);
	}
	if(timerNumber == 2){
		cout << "How long do you want to wait" << endl;
		cin >> timeStop;
		int waitTime = atoi(timeStop.c_str());
		stopWatch(waitTime);
	}
return 0;
}

 
