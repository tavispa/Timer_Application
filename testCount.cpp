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
	cout << "For a  count up timer starting at the present time for a specified number of seconds enter 1" << endl;
//	int timerNumber = atoi(numberOfTimer.c_str());
        cin >> numberOfTimer;
	int timerNumber = atoi(numberOfTimer.c_str()); 
 	if(timerNumber == 1){
	  	cout << "How many seconds do you want to count?" << endl;
		cin >> timeStop;
		//int stopTime = atoi(timeStop.c_str());
		countUp(timeStop);
	}
return 0;
}

 
