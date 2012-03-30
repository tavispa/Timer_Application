#include <iostream> 
#include <time.h>

using namespace std;

int main(){
	int seconds;
	cout << "How long do you want to wait?" ;
	cin >> seconds;
	clock_t endwait;
	endwait = clock()+seconds*CLOCKS_PER_SEC;
	int value = -1;
	while (clock() < endwait){
		if(clock()/CLOCKS_PER_SEC != value){
			value = clock()/CLOCKS_PER_SEC;
			cout << clock()/CLOCKS_PER_SEC << endl;
		}
	}
	return 0;
}
