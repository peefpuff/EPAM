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
	//���� ������ ��������. �������� � ��� ������ ����� "�" �� ��������� ����� ������������������, ���������� ���-�� ����� �����
	//������� ���������� ���-�� �����
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
	//���� ������ ��������, ����� ������� ���� ���� �� ���� �����. �������� � ��� ������ "+" ��� ����� "3" �� ������ �����, ���������� ���-�� ����� �����
	//������� ���������� ���-�� �����
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

