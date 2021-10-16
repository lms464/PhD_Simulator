#include <string>
#include <iostream>
#include <unistd.h>
#include <sstream>
#include "student.h"



int randNum(int min, int max) {

	return rand()%max + min;
}

void text_out (std::string arr) {
	// outputs text to make it look like some one is typing
	for (int i = 0 ; i < arr.length(); i++) {
		std::cout << arr[i] << std::flush;
		usleep(70000);
	}
	std::cout << std::endl;
	usleep(100000);
};


void Start_Accademica(Student &obj) {
	std::string name;
	std::string program;
	std::string grad;
	std::string S = "Hello World!\nWelcome to Ph.D. simulator, a text based grad school simulator!\nWhat is your name?";
	text_out(S);
	std::cout<<std::endl;
	std::cin >> name;
	std::ostringstream oss;
	oss << "Welcome "<<name<<"!";
	S = oss.str();
	text_out(S);
	std::cout<<std::endl;
	S = "What school or program are you in?";
	text_out(S);
	std::cin >> program;
	std::cout<<std::endl;
	S = "What what year to expect to graduate?";
	text_out(S);
	std::cin >> grad;
	std::cout<<std::endl;
	S = "I'm not sure about that year... lets say you've got about 7 years from now.";
	text_out(S);
	obj.set_name(name);
	obj.set_program(program);

};

std::string event(int randn) {
	if (randn <= 1 ) {
		return "unexpected meeting";
		// unexpected meeting
	}
	else if (randn >=2 && randn < 8) {
		return "Continue working";
		// nothing
	}
	else if (randn >=8 && randn < 9) {
		return "Coffee Break!";
		// ???
	} 
	else if (randn >=9 && randn < 10) {
		return "lab meeting";
		// ???
	} 
	else {
		return "unexpected visitor";
		// ???
	}
}

void event_effecot(Student &obj, std::string evnt) {
	if (evnt == "Continue working") {
		text_out("Continue working");
		obj.update_time(1);
		if (randNum(-1,10)<=3) {
			text_out("An issue has occured with your data!");
			obj.update_time(3);
			obj.update_productivity(-.1);
			obj.update_burnout(10);
		}

	}
	else if (evnt == "unexpected meeting") {
		obj.update_burnout(3);
		obj.check_burnout();
		obj.update_time(1.0);
		obj.update_productivity(-.1);
		text_out("unexpected meeting");
	}
	else if (evnt == "lab meeting") {
		obj.update_burnout(1);
		obj.check_burnout();
		obj.update_time(1.0);
		obj.update_productivity(-.1);
		text_out("lab meeting");
	}
	else if (evnt == "Coffee Break!") {

		obj.update_time(0.5);
		obj.update_burnout(-1);
		obj.check_burnout();
		text_out("Coffee Break!");

	}
	else if (evnt == "unexpected visitor") {
		obj.update_productivity(-.1);
		obj.update_time(randNum(-1, 3)/10);
		obj.update_burnout(-1);
		obj.check_burnout();
		text_out("unexpected visitor");
	}

}

void Workday(Student &obj) {

	srand(time(0)); 


	float local_time = 0.0;
	int max_hours = obj.get_max_hours();
	std::string S;
	float accomplishments = 0;
	while (local_time <= max_hours)  {
		{
			std::ostringstream oss;;
			
			std::string evnt = event(randNum(-1,11));
			event_effecot(obj,evnt);
			local_time = obj.check_time();
			oss << "Current Time: " << 1.0 * obj.check_time() << "...";
			S = oss.str();
			text_out(S);
		}
	}
};


int main() {
	Student obj1;
	Start_Accademica(obj1);
	int days = 0;
	int max_time = obj1.get_max_hours();
	std::cout << "Dawn of the First Day:" << days << std::endl;
	while (days < 2) {
		Workday(obj1);
/*
		float local_time = 0;
		while (local_time <= max_time) {

			local_time = local_time + 0.5;
			obj1.update_time(local_time);
			std::cout << "Current Time: " << 1.0 * obj1.check_time() << std::endl; 
			obj1.update_burnout();
			obj1.check_burnout();
		}*/
		obj1.update_days();
		days = obj1.get_days();
		std::cout << "Days Passed " << days << std::endl;
	}
	std::cout << obj1.get_burnout();
	return 0;
}
