srand(time(NULL));
int randNum(int min, int max) {
	//the parameters must be min = 3, max = 3; 
	int x = rand() % min +  max;
	return x;
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