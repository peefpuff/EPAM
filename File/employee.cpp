#include "employee.h"

employee::employee(string surn, string n, char gen, string d)
	: surname(surn), name(n), gender(gen), 
	date(d)
{
}


string employee::printEmployee()
{
	return surname + " " + name + "\t gender: " + gender + " \tbirth date: " + date;
}
