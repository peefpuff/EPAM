#include "myVector.h"

//����������� ��-���������. ������ ������ ������ �������� � 1 �������
myVector::myVector() : size_(0), capacity_(1)
{
	arr = new int[1];
}

//������ ������ �� size ��������� �������� size * 2 
myVector::myVector(int size) : size_(size), capacity_(size*2)
{
	arr = new int[capacity_];
}

//����������� �� ������� �������������, ������ ������� ��������� � �������� ������, ������� - size * 2 
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

//���� ������ ����, �� ���������� 0
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

//���������� ��������, ������� �������� � �������� [lowerBound, upperBound] � ������ ������� 
//��������������� �������� �� ���� ��������� ������� � ���� �������, ������� �� �������� � �������� ��������. (1)
//����� ���������� ������ �������� ������������� ��� ��������� �� ��� �������� � ������� ��������� � ��������. (2)
//��� ������ ����� - ������ �������� (�� �������� � �������� � ��������) ������� (3)
void myVector::doTask(int lowerBound, int upperBound)
{
	for (int i = 0; i < size_; ++i)
		if ((arr[i] < lowerBound) || (arr[i] > upperBound)) //1
			for (int j = i + 1; j < size_; ++j) //2
				if ((arr[j] >= lowerBound) && (arr[j] <= upperBound)) //2
					std::swap(arr[i], arr[j]); //3
}
