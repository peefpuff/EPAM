#include "myVector.h"

//конструктор по-умолчанию. Создаёт пустой массив ёмкостью в 1 элемент
myVector::myVector() : size_(0), capacity_(1)
{
	arr = new int[1];
}

//создаёт массив на size элементов ёмкостью size * 2 
myVector::myVector(int size) : size_(size), capacity_(size*2)
{
	arr = new int[capacity_];
}

//конструктор со списком инициализации, размер массива совпадает с размером списка, ёмкость - size * 2 
myVector::myVector(std::initializer_list<int> list) : size_(list.size()), capacity_(list.size()*2)
{
	arr = new int[capacity_];
	for (int i = 0; auto j : list)
	{
		arr[i] = j;
		++i;
	}
}

void myVector::push_back(int value)
{
	if (size_ == capacity_)
	{
		int* temp = new int[capacity_ * 2];
		for (int i = 0; i < size_; ++i)
			temp[i] = arr[i];
		delete[] arr;
		arr = temp;
		capacity_ *= 2;
	}
	arr[size_] = value;
	++size_;		
}

//если вектор пуст, то возвращает 0
int myVector::pop_back()
{
	return !empty() ? arr[--size_] : 0;
}

void myVector::print()
{
	for (int i = 0; i < size_; ++i)
		std::cout << arr[i] << ' ';
	std::cout << std::endl;
}

//перемещает элементы, которые попадают в интервал [lowerBound, upperBound] в начало массива 
//последовательно проходим по всем элементам массива и ищем элемент, который не попадает в заданный интервал. (1)
//После нахождения такого элемента просматриваем все следующие за ним элементы в поисках входящего в интервал. (2)
//Как только нашли - меняем элементы (не входящий и входящий в интервал) местами (3)
void myVector::doTask(int lowerBound, int upperBound)
{
	for (int i = 0; i < size_; ++i)
		if ((arr[i] < lowerBound) || (arr[i] > upperBound)) //1
			for (int j = i + 1; j < size_; ++j) //2
				if ((arr[j] >= lowerBound) && (arr[j] <= upperBound)) //2
					std::swap(arr[i], arr[j]); //3
}
