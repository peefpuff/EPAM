#pragma once
#include <iostream>
#include <random>
#include <iomanip>

using std::cout;
using std::endl;

class matrix
{
public:
	matrix(int, int);
	~matrix();

	void print();

	friend void doTask(matrix&);
private:
	int** arr;
	int rows_;
	int columns_;
};

