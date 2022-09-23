#include <string>
#include <iostream>
#include <unistd.h>
#include <sstream>
#include <random>
#include "student.h"
#include "global.h"


int writespeed = 50000;

int randNum() {
	std::normal_distribution<double> event_dist(5.0,2.0);
	return event_dist(generator);//rand()%max + min;
};

void text_out (std::string arr) {
	// outputs text to make it look like some one is typing
	for (int i = 0 ; i < arr.length(); i++) {
		std::cout << arr[i] << std::flush;
		usleep(writespeed);
	}
	std::cout << std::endl;
	usleep(writespeed);
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

void special_event(int years, int weeks, Student &obj) {
	if (years == 2) {
		if (obj.get_crashes() >= 1 && weeks == 0 && obj.get_master() == false) {
			int inpt;
			std::string S = "You've reached full burn out in your first two years.\nWhile totally ok, please consider your mental and physical health.";
			text_out(S);
			S = "At this juncture, you will be given the option to 'Master out'.\nIt is not required.";
			std::cout<< "###################################################"<< std::endl;
			text_out("1. Master out.");
			text_out("2. Keep going.");
			std::cout<< "###################################################"<< std::endl;
			std::cin >> inpt;
			std::cout<<std::endl;
			if (inpt == 1) {
				text_out("Totally ok! At the end of this year your all done!");
				obj.set_master();
			}
			else {
				text_out("Alrigh. Then you need to start getting ready for your quals.");
			}
		}
		if (years == 2 && weeks == 25 &&  obj.get_master()==false) {
			text_out("It's time for you qualifying exams!");
			text_out("Prof: Hello every one, this exam is open to the public and will happen in 3 parts.");
			text_out("1. A verbal presentation.\n2. A closed door question and answer session.\n3. A closed door discussion with the comittee.");
			obj.set_qual();
			obj.update_time(3);
			obj.update_burnout(2);
			obj.update_productivity(-.5);
		}
	}
}

// make each event its own function
void event(int randn, Student &obj) {
	// the range of events should update after the qual..
	// working path, should be must probable
	if (randn >=3 && randn < 6) {
		text_out("Continue to work.");
		int inpt;
		text_out("Will you read or analyze data?");
		std::cout<< "###################################################"<< std::endl;
		text_out("1. I need to do some reading..");
		text_out("2. I've got to get this analysis done.");
		std::cout<< "###################################################"<< std::endl;
		std::cin >> inpt;
		obj.update_time(inpt);
		float rand_tmp = randNum();
		if (rand_tmp == 0 || rand_tmp == 10) {
			rand_tmp = randNum();
			text_out("You have a eurika moment!");
			text_out("You message your advisor the results and ");
			text_out("your interpretation.");
			if (rand_tmp<4) {
				text_out("Your advisor agrees, and you plan out the next few steps");
				obj.update_time(1.5);
				obj.update_productivity(-.1);
				obj.update_burnout(-1);

			}
			else if (rand_tmp>=4 && rand_tmp<7) {
				text_out("Your advisor agrees with the results, however:");
				text_out("You are missing some key statistics. It's going to be ");
				text_out("nessisary to repeat the experiment at least two more times");
				obj.update_time(1);
				obj.update_productivity(-.2);
				obj.update_burnout(1);
			}
			else {
				text_out("Your advisor doesn't see the point of the analysis.");
				obj.update_time(1);
				obj.update_productivity(-.3);
				obj.update_burnout(3);
			}
		}

		// issues occur 
		// happens a little too frequently
		if (randNum()<=3) {
			int inpt;
			int desicion = 0;
			text_out("An issue has occured with your data!");
			text_out("What will you do to resolve it?");
			// set it up so that this can only happen 3 times, then add option to ask PI
			while (desicion == 0) {
				std::cout<< "###################################################"<< std::endl;
				text_out("1. Try it again, maybe it'll work this time");
				text_out("2. Read up about the issue, back to a lit search");
				text_out("3. Stare at it blankly");
				if (obj.get_burnout() > 50) {
					text_out("4. Take a step back, and get a snack.");
				}
				std::cout<< "###################################################"<< std::endl;
				std::cin >> inpt;

				if (inpt == 1) {
					text_out("That didn't do anything new");
					obj.update_productivity(-.1);
					obj.update_burnout(1);
				}
				else if (inpt == 2) {
					text_out("Yeah.. it'll take time, but this is the right choice..");
					obj.update_time(2.5);
					obj.update_burnout(1);
					desicion = 4;
				}

				else if (inpt == 3) {
					text_out("...");
					text_out("...");
					text_out("...");
					text_out("...");
					text_out("...");
					text_out("...");
					text_out("...");
					text_out("...");
					text_out("...");
					text_out("...");

				}
				else if (obj.get_burnout() > 50 && inpt == 4) {
					obj.update_time(.5);
				}

			}

		}
	}
	else if (randn <=2) {
		int inpt;
		text_out("unexpected email");		// nothing
		int rand_tmp = randNum();
		if (rand_tmp >=0 && rand_tmp <= 3) {

			text_out("Your PI informs you of a grant they are applying for.");
			text_out("They need some figures from you");
			text_out("What do you do?");

			std::cout<< "###################################################"<< std::endl;
			text_out("1. Get the plots out right away");
			text_out("2. Inform your PI that they might not be done, and you are still working on them");
			text_out("3. Stare at it blankly, maybe another student will pick up the work...");
			std::cout<< "###################################################"<< std::endl;

			std::cin >> inpt;

			if (inpt == 2) {
				text_out("You let your PI know that you are still working on them");
				text_out("They inform you this is now your priorety, and need to be done.");
				text_out("Looks like its going to be a long day..");
				obj.update_burnout(3);
				obj.update_time(12);
				obj.prof_affinity_update(0.1);

			}
			else if (inpt == 1) {
				text_out("Yeah.. it'll take time, but this is the right choice..");
				obj.update_time(4);
				obj.update_burnout(1);
				obj.prof_affinity_update(0.5);
			}

			else if (inpt == 3) {
				text_out("...");
				text_out("...");
				obj.prof_affinity_update(-1.0);
				// build a probability dist that changes prof's atitude.
			}
			obj.check_burnout();

		}
		else {
			text_out("You try to quickly respond, but it takes an hour to write the message right.");
			obj.update_time(1);
		}

	}
	else if (randn >7 && randn < 9) {
		obj.update_time(0.5);
		obj.update_burnout(-1);
		obj.check_burnout();
		text_out("Coffee Break!");		// ???
	} 
	else if (randn >=9 && randn < 10) {
		obj.update_burnout(1);
		obj.check_burnout();
		obj.update_time(1.0);
		obj.update_productivity(-.1);
		text_out("lab meeting");		// ???
	} 
	else {
		obj.update_productivity(-.1);
		obj.update_time(.5);
		obj.update_burnout(-1);
		obj.check_burnout();
		text_out("unexpected visitor");		// ???

	}
}


void Meeting(Student &obj) {
	// Mood range should be able to varry as the years progress
	std::normal_distribution<double> mood(obj.get_affinity(),1.5);
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
		if (mood(generator)<=3) {
			text_out("Prof: Wait wait wait... something looks wrong.. I need you to try...");
			text_out("Your advisor goes on to describe the next two weeks of your life.");
			obj.update_burnout(2);
			obj.check_burnout();
			obj.prof_affinity_update(-0.1);
			obj.update_time(1.0);
			std::cout<< std::endl;
		}
		else {
			text_out("Your advisor looks at the new data. The two of you discuss if the analysis makes sense, and what steps might be appropriate.");
			obj.update_time(1.0);
			obj.prof_affinity_update(0.2);
			std::cout<< std::endl;
		}
	}
	else if (inpt == 2) {
		if (mood(generator)<=4) {
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
			obj.prof_affinity_update(-0.5);
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


};

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
			int rand_mean = int((randNum() + randNum())/2);
			event(rand_mean, obj);
			local_time = obj.check_time();
			oss << "Hours in the day passed: " << 1.0 * obj.check_time() << "...";
			S = oss.str();
			text_out(S);
			std::cout<< std::endl;
		}
	}
	std::system("clear");
	std::system("clear");
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
	obj.write_in_lab_book();
	std::cout << std::endl;
	text_out("Finally, it's firday.");
};


int main(int argc, char **argv) {

	const char* logo = R"===(

    			     Welcome
    				2
    			 GRAD SCHOOOOOOL
    		  The gradschool simulator

    )===";

    std::cout << logo << std::endl;

	Student obj1;
	for (int i = 0; i < argc; ++i) {
		if (std::string(argv[i]) == "fast") {
			writespeed = 10;
		}
	}
	Start_Accademica(obj1);
	std::cout  << std::endl;
	std::cout << "Dawn of the First Day" << std::endl;
	std::cout << std::endl;
	int years = 0;
	while (years < 7) {
		int weeks = 0;
		while (weeks < 52) {
			if (years == 2) {
				special_event(years, weeks, obj1);
			}
			Workweek(obj1);
			std::cout << obj1.get_burnout()<<std::endl;
			std::cout << obj1.get_productivity()<<std::endl;
			weeks = weeks + 1;
		}
		years = years + 1;
	}
	return 0;
}
