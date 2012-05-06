
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


/*
 * Converts input string to seconds
 * @parm inputTime - string format of time
 * @return (sec + min + hour) - total time converted to seconds  
 */
 
int convertTime(string inputTime)
{
	int sec;
	int min;
	int hour;
	
	string secString=inputTime.substr(6,2);
	string minString=inputTime.substr(3,2);
	string hourString=inputTime.substr(0,2);
	
	//convert string to int for seconds
	stringstream secTime(secString);
	secTime >> sec; 
	//convert string to int for minutes		
	stringstream minTime(minString);
	minTime >> min;
	min = min * 60;
	//convert string to int for hours	
	stringstream hourTime(hourString);
	hourTime >> hour;
	hour = hour * 3600;		
	
	return (sec + min + hour);
			
}


/*
 * Output of timer to console
 * @param number - number of timers
 * @param timers - number of timers input by user
 * @param timeDifference - vector of time differentials
 * @param events - array of events
 * 
 */
void execute(int number, int timers, vector<int> timeDifference, string events[])
{
	if(number < timers-1)
	{
		cout << "Time to start " << events[number+1] << endl;
	}
	if(number < timers-2)
	{
		
		cout << "In " << timeDifference.at(number+1) << " seconds, you need to start the " << events[number+2] << endl;
		cout << endl;
	}
	if(number == timers-2 ) 
	{
		sleep(timeDifference.at(timers));
				
		cout << "***************************************************************************" << endl;
		cout << "Everything is completed" << endl;
	}	
}

/*
 * Sorts the inputed times - longest time at first element of array
 * @param sortTime[] - array of user input times
 * @param sortEvent[] - array of user input events
 * @param size -  number of user input timers
 */
 
void descendSort(int sortTime[], string sortEvent[], int size)
{
	int tempTime = 0;
	string tempEvent = "";
	for (int i=0; i < size; i++)
    {
		for (int j=0; j <= i; j++)
        {
               if( sortTime[j] < sortTime[i]) 
               {
                    tempTime = sortTime[j];
                    tempEvent = sortEvent[j];
                    
					sortTime[j] = sortTime[i];
					sortEvent[j] = sortEvent[i];
					
                    sortTime[i] = tempTime;
                    sortEvent[i] = tempEvent;
               }

         } 
	}
}

/*
 *  Check the given command line arguments for proper usage
 * @param numberOfTimer - number of user input timers needed
 * @param argc - number of command line arguments
 * @param switchCase - value of argv[1] - used for determine which version to execute
 */


void checkCommandLine(int numberOfTimers, int switchCase)
{
	if(switchCase < 1 || switchCase > 3)
	{
		cout << "To use this application: Enter ./timer [timer option] [# of timers]" << endl;
		cout << "-------------------------------------------------------------------" << endl;
		cout << endl;
		cout << "Timer 0ptions" << endl;
		cout << "------------- " << endl;
		cout << "1 - console timer" << endl;
		cout << "2 - GUI timer" << endl;
		cout << "3 - console input and GUI output" << endl;
		exit(EXIT_FAILURE);
    } 
	if(numberOfTimers > 10 || numberOfTimers < 1)
	{
		cout << "You can not use more than 10 timers on this system" << endl;
		cout << "Please enter a number between 1 and 10 " << endl;
		exit(EXIT_FAILURE);
	}
	
}

/*
 * Calculate the time difference between input timer values
 * @param eventTimes[] - array of user input events
 * @param size - number of user input timers
 * @return delayTime - vector of times to delay.
 */ 

vector<int> getTimeDifference(int eventTimes[], int size)
{
	vector<int> delayTime;
	
	if(size == 1)
	{
		delayTime.push_back(eventTimes[0]);
		return delayTime;
	}
	else
	{
		for(int i = 0; i < size ; i ++)
		{
			delayTime.push_back(eventTimes[i] - eventTimes[i+1]);
		}
	
		return delayTime;
	}
}

/*
 * Simple function to sleep for given amount of time
 * @param time - amount of time to sleep in seconds
 * @return - 1 when sleep completes executing
 */ 
int newTimer(int time)
{
	int count = 0;
	while(1)
	{
		sleep(1);
		count ++;
		if(count == time)
		{
			return 1;
		}
	}
}

