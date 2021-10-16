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

void Meeting(Student &obj) {


	int inpt;
	std::ostringstream ozz;;
	ozz << "Prof: How are you doing  " << obj.get_name() << "?";
	std::string S = ozz.str();
	text_out(S);
	text_out("Prof: Let's see that new data.");
	std::cout << std::endl;
	text_out("How is your data?");
	std::cout<< "###################################################"<< std::endl;
	text_out("1. Here you go!");
	text_out("2. There was an issue...");
	text_out("3. Ok, this is going to take a min to explain.");
	std::cout<< "###################################################"<< std::endl;
	std::cout<< std::endl;

	std::cin >> inpt;
	if (inpt == 1) {
		if (randNum(-1,10)<=3) {
			text_out("Prof: Wait wait wait... something looks wrong.. I need you to try...");
			text_out("Your advisor goes on to describe the next two weeks of your life.");
			obj.update_burnout(4);
			obj.check_burnout();
			obj.update_time(1.0);
			std::cout<< std::endl;
		}
		else {
			text_out("Your advisor looks at the new data. The two of you discuss if the analysis makes sense, and what steps might be appropriate.");
			obj.update_time(1.0);
			std::cout<< std::endl;
		}
	}
	else if (inpt == 2) {
		if (randNum(-1,10)<=4) {
			text_out("Your advisor gives you a disapointed sigh.");
			text_out("Prof: That's a shame, but I know you've been working hard.");
			text_out("You and your advisor end the meeting early to give you more time to work");
			obj.update_burnout(1);
			obj.check_burnout();
			obj.update_time(.25);
			std::cout<< std::endl;
		} 
		else {
			text_out("Your advisor looks down their nose at you. And begins to talk about what needs to be done.");
			text_out("You are embarased and in desperate need of some coffee");
			obj.update_burnout(4);
			obj.check_burnout();
			obj.update_time(1.5);
			std::cout<< std::endl;
		}
	}
	else if (inpt == 3) {

		text_out("Your advisor looks at the new data, albiet confused by what you said.");
		text_out("Prof: SO... you did this this and this?");
		text_out("You reply in the affermative");
		text_out("Prof: Ah, ok, I'd try doing it this way, but lets see how it looks both ways tomorrow");
		obj.update_burnout(1);
		obj.check_burnout();
		obj.update_time(1.0);
		std::cout<< std::endl;

	}


}

void Workday(Student &obj, int days) {

	srand(time(0)); 


	float local_time = 0.0;
	obj.init_time();	
	int max_hours = obj.get_max_hours();
	std::string S;
	float accomplishments = 0;
	while (local_time <= max_hours)  {
		{
			std::ostringstream oss;;
			if (days == 4 && local_time < 1) {
				text_out("Don't forget about your weekly meeting today!");
				Meeting(obj);
			}
			std::string evnt = event(randNum(-1,11));
			event_effecot(obj,evnt);
			local_time = obj.check_time();
			oss << "Hours in the day passed: " << 1.0 * obj.check_time() << "...";
			S = oss.str();
			text_out(S);
			std::cout<< std::endl;
		}
	}
};

void Workweek(Student &obj) {

	int days = 0;
	text_out("Start of the Week.");
	std::cout<< std::endl;
	while (days <= 5) {
		Workday(obj,days);
		days = days + 1;
		text_out("The next day.");

	}
	std::cout<< std::endl;
	text_out("Finally, it's firday.");
}


int main() {
	Student obj1;
	Start_Accademica(obj1);
	int days = 0;
	int max_time = obj1.get_max_hours();
	std::cout << "Dawn of the First Day:" << days << std::endl;
	Workweek(obj1);
	std::cout << obj1.get_burnout();
	return 0;
}
