#include <string>
#include <iostream>
#include <unistd.h>
#include <sstream>
#include "student.h"

int main() {
	Student obj1;
	obj1.init_graduation_year();
	obj1.init_max_working_hours();
	obj1.init_year();
	obj1.init_time();
	int days = 0;
	int max_time = obj1.get_max_hours();
	while (days < 7) {
		float local_time = 0;
		while (local_time <= max_time) {

			local_time = local_time + 0.5;
			obj1.update_time(local_time);
			std::cout << "Current Time: " << 1.0 * obj1.check_time() << std::endl; 
			obj1.check_burnout();
		}
		obj1.update_days(local_time);
		days = obj1.get_days();
		std::cout << "Days Passed " << days << std::endl;
	}
	return 0;
}
