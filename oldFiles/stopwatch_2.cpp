#include <iostream>
#include <ctime>   //ctime and time.h are the same

using namespace std;

int main(){
	time_t desiredTime;
	cout << "How long do you want the stop watch to go? (in seconds)? ";
	cin >> desiredTime;

	desiredTime += time(NULL);
	int prevTime = 0;

	for(int i = difftime(desiredTime, time(NULL)); i != 0; i = difftime(desiredTime, time(NULL))){
		if(prevTime != i){
			prevTime = i;		
			cout << prevTime << endl;
		};
	}
	cout << "Done!" << endl;

return 0;
}
