#include <string>
#include <iostream>
//student.h

class Student {
// 	Student (std::string name, std::string program, int year, float day);
	
	private:
		// variables
		std::string name;
		std::string program;
		int graduation_year = 7;
		int max_hours_per_day = 8;
		int years_passed = 0;
		int day = 0;
		float time = 0.0;
		int burnout = 0;
		float productivity = 1;
		
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
		void update_days();
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
		void init_productivity();
		void update_productivity(float prod);
		float get_productivity();
};