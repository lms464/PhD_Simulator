#include <iostream>
#include <cstdlib>
#include <ctime>

int randNum(int min, int max)
{
   return rand() % max + min;
}


int lab_meeting () {
	int time = 1;
	return time;
}

int meeting () {
	int time = 1;
	return time;
}

int lunch () {
	return randNum(0,2);
}

int research (int time) {
	int burnout = 0;
	while (burnout < 100) {
		burnout = burnout +1;
		time = time + 1;
		if (time > 13) {
			burnout = burnout + 25;
			return time;
		}
	}
	return time; 
}

int main() {
	for (int i=0; i < 100 ; i++) {
		std::cout<< randNum(0,3)<< std::endl;
	}
	return 0;

}