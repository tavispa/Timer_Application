#include <iostream>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <array>
#include <string>
#include <unistd.h>
#include <stdlib.h>
#include "timer.h"

using namespace std;

int main(int argc, char *argv[])
{
	if(argc == 1 || argc ==2)
	{
		cout << "There is a README for a reason" << endl;
		cout << "READ IT!!" << endl;
		return EXIT_FAILURE;
	}
		
	int switchCase = atoi(argv[1]);
   	int numberOfTimers = atoi(argv[2]);
    
   	checkCommandLine(numberOfTimers, switchCase); 
	
	string event;
	string time; // string representation of user inputted time
	int timeNumber; // variable to store timer as an integer
	
	vector<int> timeDifference; //Vector of user inputted times
	
	int times[numberOfTimers]; // array to hold times
	string events[numberOfTimers]; // array to hold events
	
	
	
	
	
	
	if(switchCase==2)
	{
		execv("timerGUI/finalTimer",NULL);
	}
	else if(switchCase == 1)
	{
		//Populate vectors with user input
		for(int index = 0; index < numberOfTimers; index++)
		{
			cout << "Enter timed event: "; 
			getline (cin, event);
	    	events[index] = event;
	    	cout << "Enter time needed for " << events[index] << " : ";
	    	getline(cin, time);
			timeNumber = convertTime(time);
			times[index] = timeNumber;
		}
		
		descendSort(times, events, numberOfTimers); // put longest times at beginning of array
		
		timeDifference = getTimeDifference(times, numberOfTimers); // Load time difference into vector
		timeDifference.push_back(times[numberOfTimers-1]); // push the least time to the back of the timerDifference vector 
		
		cout << "------------------------------------------------------------------------" << endl;
		cout << "The timer for " << events[0] << " has started" << endl;
		cout << "In " << timeDifference.at(0) << " seconds, you need to start the " << events[1] << endl;
		cout << endl;
			
	
	
		for(int x = 0; x < numberOfTimers -1; x++)
		{
			if(newTimer(timeDifference.at(x)))
			{
				execute(x, numberOfTimers, timeDifference, events);
			}
		}
				
   		return EXIT_SUCCESS;
	}
	else 
	{	
		cout << "***********************************************" << endl;
		cout << "This version is still under construction" << endl;
		cout << "When completed it will take input from the user" << 
		 " and excute the gui timer interface for the provided input" << endl;
		cout << "***********************************************" << endl;
		pid_t pId = fork();
		exit(0);
    }
return 0;


}


