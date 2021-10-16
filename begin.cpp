#include <string>
#include <iostream>
#include <unistd.h>
#include <sstream>

void text_out (std::string arr) {

	for (int i = 0 ; i < arr.length(); i++) {
		std::cout << arr[i] << std::flush;
		usleep(70000);
	}
	std::cout << std::endl;
	usleep(100000);
}

void Start_Accademica() {
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
}
