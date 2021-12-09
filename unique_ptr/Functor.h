#pragma once
#include "Student.h"

// 1 - name
// 2 - group
// 3 - age
// 4 - year

class comparator
{
public:
	bool operator()(Student& s1, Student& s2, int field=3)
	{
		switch (field)
		{
		case 1:
			return s1.getName() < s2.getName();
			break;
		case 2:
			return s1.getGroup() < s2.getGroup();
			break;
		case 3:
			return s1.getAge() < s2.getAge();
			break;
		case 4:
			return s1.getYear() < s2.getYear();
			break;
		default:
			return false;
		}
	}

	bool operator()(std::unique_ptr<Student>& s1, std::unique_ptr<Student>& s2, int field)
	{
		switch (field)
		{
		case 1:
			return s1.get()->getName() < s2.get()->getName();
			break;
		case 2:
			return s1.get()->getGroup() < s2.get()->getGroup();
			break;
		case 3:
			return s1.get()->getAge() < s2.get()->getAge();
			break;
		case 4:
			return s1.get()->getYear() < s2.get()->getYear();
			break;
		default:
			return false;
		}
	}
};