#include <string>
#include <iostream>


class Student {
// 	Student (std::string name, std::string program, int year, float day);
	
	private:
		// variables
		std::string name;
		std::string program;
		int graduation_year;
		int max_hours_per_day;
		int years_passed;
		int day;
		float time;
		int burnout;
		float productivity;
		
	public:
		std::string set_name(std::string name);
		std::string set_program(std::string program);
		void init_graduation_year();
		void init_max_working_hours();
		int get_max_hours();
		void init_year();
		int get_year();
		void update_year();
		void init_days();
		void update_days(float time);
		void update_time(float time);
		int get_days();
		void init_time();
		float check_time();
		void init_burnout();
		void update_burnout(int burn);
		void update_burnout();
		void check_burnout();
		int get_burnout();
};

void Student::init_graduation_year() {
	graduation_year = 7;
};

void Student::init_max_working_hours() {
	max_hours_per_day = 8;
};

int Student::get_max_hours() {
	return max_hours_per_day;
}

void Student::init_year() {
	years_passed = 0;
};

int Student::get_year() {
	return years_passed;
}

float Student::check_time() {
	return time;
}

void Student::update_days(float loc_time) {
	if (time >= max_hours_per_day) {
		day = day + 1;
		if (time > max_hours_per_day) {
			Student::update_burnout();
		}
		Student::init_time();
	}
};

int Student::get_days() {
	return day;
}

void Student::init_time() {
	time = 0.0;
};
void Student::update_time(float loc_time) {
	time = loc_time;
}

void Student::update_burnout(int burn) {
	burnout = burnout + burn;
}

void Student::update_burnout() {
	burnout = burnout + 1;
}

int Student::get_burnout() {
	return burnout;
}

void Student::check_burnout() {
	if (burnout > 50 && burnout < 75) {
		Student::update_productivity(-0.01);
	}
	else if (burnout >= 75 && burnout <90) {
		Student::update_productivity(-0.1);
	}
	else if (burnout >= 90) {
		Student::updateupdate_productivity(-1.0)
	}
	if 
}

void Student::init_productivity() {
	productivity = 1;
}


void Student::update_productivity(float prod) {
	productivity = productivity + prod
	if (productivity > 1.0) {
		productivity = 1.0;
	} else if (productivity < -1.0) {
		productivitiy = -1.0;
	}
}

int main() {
	Student obj1;
	obj1.init_graduation_year();
	obj1.init_max_working_hours();
	obj1.init_year();
	obj1.init_time();
	float local_time = 0;
	int max_time = obj1.get_max_hours();
	
	while (local_time <= max_time) {
	
		
		local_time = local_time + 0.5;
		obj1.update_time(local_time);
		std::cout << "Current Time: " << 1.0 * obj1.check_time() << std::endl; 
	}
	obj1.update_days(local_time);
	std::cout << "Days Passed " << obj1.get_days() << std::endl;
	return 0;
}
