#pragma once
#include <iostream>
#include <initializer_list>
#include <algorithm>
#include <numeric>

template <class T>
class myVector
{
public:

	// конструктор без параметров
	myVector() : size_(0), capacity_(1)
	{
		arr = new T[1];
	};

	// конструктор с 1 параметром size
	myVector(int size) : size_(size), capacity_(size * 2)
	{
		arr = new T[capacity_];
	};

	// конструктор с 2 параметрами: size и value
	// создаётся вектор с заданным размером и заполняется указанным значением 
	myVector(int size, T value) : size_(size), capacity_(size * 2)
	{
		arr = new T[capacity_];
		for (int i = 0; i < size_; ++i)
			arr[i] = value;
	};

	// конструктор копирования
	myVector(const myVector& v)
	{
		size_ = capacity_ = v.size_;
		arr = new T[size_];
		for (int i = 0; i < size_; ++i)
			arr[i] = v.arr[i];
	};

	// конструктор со списком инициализации
	myVector(std::initializer_list<T> list) : size_(list.size()), capacity_(list.size() * 2)
	{
		arr = new T[capacity_];
		for (int i = 0; auto j : list)
		{
			arr[i] = j;
			++i;
		}
	};

	~myVector() { delete[] arr; };

	void push_back(T value)
	{
		if (size_ == capacity_)
		{
			T* temp = new T[capacity_ * 2];
			for (int i = 0; i < size_; ++i)
				temp[i] = arr[i];
			delete[] arr;
			arr = temp;
			capacity_ *= 2;
		}
		arr[size_] = value;
		++size_;
	};

	//если вектор пуст, то возвращает 0
	T pop_back()
	{
		return !empty() ? arr[--size_] : 0;
	};

	int size() { return size_; };
	int capacity() { return capacity_; };
	bool empty() { return size_ == 0; };

	void sort() { std::sort(arr, arr + size_, [](T a, T b) {return a > b; }); }; // сортировка по убыванию
	T min() { return *std::min_element(arr, arr + size_); };
	T max() { return *std::max_element(arr, arr + size_); };
	double average() 
	{
		double sum{ 0 };
		for (int i = 0; i < size_; ++i)
			sum += arr[i];
		return (sum / size_);
	};

	void print()
	{
		for (int i = 0; i < size_; ++i)
			std::cout << arr[i] << ' ';
		std::cout << std::endl;
	};

	myVector& operator=(const myVector& v)
	{
		T* temp;

		temp = new T[v.size_];
		delete[] arr;
		arr = temp;
		size_ = v.size_;

		for (int i = 0; i < size_; ++i)
			arr[i] = v.arr[i];
		return *this;
	}
//перемещает элементы, которые попадают в интервал [lowerBound, upperBound] в начало массива 
//последовательно проходим по всем элементам массива и ищем элемент, который не попадает в заданный интервал. (1)
//После нахождения такого элемента просматриваем все следующие за ним элементы в поисках входящего в интервал. (2)
//Как только нашли - меняем элементы (не входящий и входящий в интервал) местами (3)
	void doTask(T lowerBound, T upperBound)
	{
		for (int i = 0; i < size_; ++i)
			if ((arr[i] < lowerBound) || (arr[i] > upperBound)) //1
				for (int j = i + 1; j < size_; ++j) //2
					if ((arr[j] >= lowerBound) && (arr[j] <= upperBound)) //2
						std::swap(arr[i], arr[j]); //3
	};

private:
	int size_;
	int capacity_;
	T* arr;
};