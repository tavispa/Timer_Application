#include <iostream>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <array>
#include <string>
#include <unistd.h>
#include <stdlib.h>





using namespace std; 

int convertTime(string inputTime);
void execute(int number, int timers, vector<int> timeDifference, string events[]);
void descendSort(int sortTime[], string sortEvent[], int size);
void checkCommandLine(int numberOfTimers, int switchCase);
vector<int> getTimeDifference(int eventTimes[], int size);
int newTimer(int time);


