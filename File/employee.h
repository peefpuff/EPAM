#pragma once
#include <string>

using std::string;

class employee
{
public:
	employee() {};
	employee(string, string, char, string);
	~employee() {};
	void setSurname(string str) { surname = str; };
	void setName(string str) { name = str; };
	void setGender(char g) { gender = g; };
	void setDate(string d) { date = d; };
	string printEmployee();
	string getSurname() { return surname; };
	string getDate() { return date; };
	char getGender() { return gender; };

private:
	string surname;
	string name;
	char gender;
	string date;
};

