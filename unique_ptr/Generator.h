#pragma once
#include "Student.h"
#include <vector>
#include <random>

using std::vector;

class Generator
{
public:
	Student getStudent()
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> age_dist(18, 99);
		std::uniform_int_distribution<> year_dist(1, 4);
		std::uniform_int_distribution<> name_dist(0, 9);
		std::uniform_int_distribution<> group_dist(0, 4);

		int age{ age_dist(gen) };
		int year{ year_dist(gen) };
		string name{ names[name_dist(gen)] + " " + surnames[name_dist(gen)] };
		string group{ groups[group_dist(gen)] };

		return Student(name, group, age, year);
	}

private:
	vector<string> names{ "Mike", "Alice", "Jack", "Katie", "Johny", "Mary", "Harry", "April", "Oscar", "Anna"};
	vector<string> surnames{ "Cage", "Gordon", "Weak", "Ozborn", "Murphy", "White", "Cooper", "Smith", "Brown", "Wulf"};
	vector<string> groups{"ASOI", "CMS&N", "AI", "PMS", "IE"};

};