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
		int burnout = 0; //HP
		float productivity = 1.0; //MP
		float achivements = 0.0; //exp
		int crashes = 0;
		float prof_affinity = 5.0; // how much your prof likes you
							// value feeds into the normal distiribution 
							// for a profs reaction to the student
		
	public:
		//functions
		void set_name(std::string name);
		void set_program(std::string program);
		std::string get_name();
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
		void prof_affinity_update(float affinity);
		float get_affinity();
};