#include <fstream>
#include <string>
#include <iostream>
#include "student.h"


// functions for student

void Student::set_name(std::string name_in) {
	name = name_in;
}

std::string Student::get_name() {
	return name;
}

void Student::set_program(std::string prog) {
	program = prog;
}


void Student::init_graduation_year() {
	graduation_year = 7;
};

void Student::init_max_working_hours() {
	max_hours_per_day = 3;
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

void Student::update_days() {
	if (time >= max_hours_per_day) {
		day = day + 1;
		if (time > max_hours_per_day) {
			Student::update_burnout();
		}
		Student::init_time();
	}
};

void Student::update_days(float local_time) {
	if (local_time >= max_hours_per_day) {
		day = day + 1;
		if (local_time > max_hours_per_day) {
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
	time = time + loc_time;
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
		Student::update_productivity(-1.0);
	}
	if (burnout >= 100) {
		Student::update_days(max_hours_per_day);
		burnout = 0;
		crashes = crashes + 1;
	}
}

void Student::init_productivity() {
	productivity = 1;
}

void Student::update_productivity(float prod) {
	productivity = productivity + prod;
	if (productivity > 1.0) {
		productivity = 1.0;
	} else if (productivity < -1.0) {
		productivity = -1.0;
	}
}

float Student::get_productivity() {
	return productivity;
}

void Student::prof_affinity_update(float affinity) {
	prof_affinity = prof_affinity + affinity;
}

float Student::get_affinity() {
	return prof_affinity;
}

int Student::get_crashes() {
	return crashes;
}

void Student::set_qual() {
	qual = true;
}

bool Student::get_qual() {
	return qual;
}

void Student::set_master() {
	master_out = true;
}

bool Student::get_master() {
	return master_out;
}

void Student::write_in_lab_book() {
	// Save your data
	std::ofstream LabLog("Log.log");
	LabLog << Student::get_name() << std::endl;
	LabLog << Student::get_year() << std::endl;
	LabLog << Student::get_burnout() << std::endl;
	LabLog << Student::get_affinity() << std::endl;
	LabLog.close();
}