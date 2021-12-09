#pragma once
#include "Student.h"
#include "Generator.h"
#include "Functor.h"
#include <memory>
#include <algorithm>
#include <vector>

using std::vector;

int main()
{
	int n{ 5 };
	vector<Student> list;
	list.reserve(5);
	vector<std::unique_ptr<Student>> list1;
	//list1.reserve(5);
	std::cout << "-----Create students list-----" << std::endl;
	for (int i = 0; i < n; ++i)
		list.push_back(Generator().getStudent());
	std::cout << "-----Create unique_ptr list-----" << std::endl;
	for (int i = 0; i < n; ++i)
		list1.push_back(std::make_unique<Student>(Generator().getStudent()));

	comparator comp;
	int field{ 3 };
	std::cout << "Enter sorting column(1 - name, 2 - group, 3 - age, 4 - year):" << std::endl;
	std::cin >> field;
	std::cout << "-----Show students list-----" << std::endl;
	std::cout << "Name          \t Group \t Age \t Year \t" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	for (auto &i : list)
		std::cout << i.printStudent() << std::endl;

	std::cout << "-----------------------------" << std::endl;
	std::sort(list.begin(), list.end(), [&, field](Student& a, Student& b) { return comp(a, b, field);});
	std::cout << "-----Sorted students list-----" << std::endl;
	std::cout << "Name          \t Group \t Age \t Year \t" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	for (auto &i : list)
		std::cout << i.printStudent() << std::endl;
	std::cout << "-----------------------------" << std::endl;

	std::cout << "-----Show unique_ptr list-----" << std::endl;
	std::cout << "Name          \t Group \t Age \t Year \t" << std::endl;
	std::cout << "----------------------------------------" << std::endl;

	for (auto i = list1.begin(); i < list1.end(); ++i)
		std::cout << (*i).get()->printStudent() << std::endl;

	std::cout << "-----------------------------" << std::endl;
	std::sort(list1.begin(), list1.end(), [&, field](std::unique_ptr<Student>& a, std::unique_ptr<Student>& b) { return comp(a, b, field); });
	std::cout << "-----Sorted unique_ptr list-----" << std::endl;
	std::cout << "Name          \t Group \t Age \t Year \t" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	//for (auto i : list1)
	for (auto i = list1.begin(); i < list1.end(); ++i)
		std::cout << (*i).get()->printStudent() << std::endl;
	std::cout << "-----------------------------" << std::endl;

	std::cout << "-----Delete unique_ptr list-----" << std::endl;
	list1.clear();
	std::cout << "-----Delete unique_ptr list end-----" << std::endl;

}