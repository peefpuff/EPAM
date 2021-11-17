#pragma once
#pragma warning(disable: 4996)
#include <string.h>

class MyString
{
public:
	MyString(const char * temp);
	~MyString();
	char* getString();
	int getLenght();
	int doTask();
	int doTask_1();


private:
	char* str;
	int lenght;
};

