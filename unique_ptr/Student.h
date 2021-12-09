#pragma once
#include <string>
#include <iostream>

using std::string;

class Student
{
public:
	Student(string name = "", string group = "", int age = 18, int year = 1)
		: name_(name), group_(group), age_(age), year_(year) 
	{
		std::cout << "default constructor" << std::endl;
	}
	//Student(const Student& s) = default;
	//Student& operator=(const Student& s) = default;
	//Student(Student&& s) = default;
	//Student& operator=(Student&& s) = default;
	//~Student() = default;
	
	Student(const Student& s)
	{
		std::cout << "copy constructor" << std::endl;
		name_ = s.name_;
		group_ = s.group_;
		age_ = s.age_;
		year_ = s.year_;
	}
	Student(Student&& s)
	{
		std::cout << "move constructor" << std::endl;
		name_ = s.name_;
		group_ = s.group_;
		age_ = s.age_;
		year_ = s.year_;
		s.name_ = "";
		s.group_ = "";
		s.year_ = 0;
		s.age_ = 0;
	}
	Student& operator=(const Student& s)
	{
		std::cout << "copy =" << std::endl;
		name_ = s.name_;
		group_ = s.group_;
		age_ = s.age_;
		year_ = s.year_;
		return *this;
	}
	Student& operator=(Student&& s)
	{
		std::cout << "move =" << std::endl;
		name_ = s.name_;
		group_ = s.group_;
		age_ = s.age_;
		year_ = s.year_;
		s.name_ = "";
		s.group_ = "";
		s.year_ = 0;
		s.age_ = 0;
		return *this;
	}
	~Student()
	{
		std::cout << "destructor" << std::endl;
	}

	string printStudent()
	{
		return name_ + "\t " + group_ + "\t " + std::to_string(age_) + "\t " + std::to_string(year_);
	};
	string getName() { return name_; }
	string getGroup() { return group_; }
	int getAge() { return age_; }
	int getYear() { return year_; }

private:
	friend class Functor;
	string name_;
	string group_;
	int age_;
	int year_;
};