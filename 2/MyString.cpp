#include "MyString.h"


MyString::MyString(const char* temp)
{
	lenght = strlen(temp);
	str = new char[lenght+1];
	strcpy(str, temp);
}

MyString::~MyString()
{
	delete[] str;
}
char* MyString::getString()
{
	return str;
}
int MyString::getLenght() 
{ 
	return lenght; 
}

int MyString::doTask()
{
	//Дана строка символов. Заменить в ней каждую букву "а" на последнюю букву последовательности, подсчитать кол-во таких замен
	//Функция возвращает кол-во замен
	int count = 0;

	for (int i = 0; i < lenght; i++)
	{
		if (str[i] == 'a')
		{
			count++;
			str[i] = str[lenght-1];
		}
	}
	return count;
}

int MyString::doTask_1()
{
	//Дана строка символов, среди которых есть хотя бы одна точка. Заменить в ней знаком "+" все цифры "3" до первой точки, подсчитать кол-во таких замен
	//Функция возвращает кол-во замен
	int count = 0;

	int i = 0;
	while (str[i] != '.')
	{
		if (str[i] == '3')
		{
			count++;
			str[i] = '+';
		}
		i++;
	}

	return count;

}

