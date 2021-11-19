#pragma once
#include <iostream>
#include <initializer_list>
#include <algorithm>
#include <numeric>
class myVector
{
public:
	myVector();
	myVector(int size);
	myVector(std::initializer_list<int> l);

	~myVector() { delete[] arr; };

	void push_back(int value);
	int pop_back();

	int size() { return size_; };
	int capacity() { return capacity_; };
	bool empty() { return size_ == 0; };

	void sort() { std::sort(arr, arr + size_, [](int a, int b) {return a > b; }); }; // сортировка по убыванию
	int min() { return *std::min_element(arr, arr + size_); };
	int max() { return *std::max_element(arr, arr + size_); };
	double average() { return static_cast<double>(std::accumulate(arr, arr + size_, 0)) / size_;};

	void print();

	void doTask(int lowerBound, int upperBound);

private:
	int size_;
	int capacity_;
	int* arr;
};

