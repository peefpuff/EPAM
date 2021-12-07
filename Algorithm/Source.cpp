#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <chrono>
#include <string>

using std::cout;
using std::endl;
using clocks = std::chrono::steady_clock;
using dur = std::chrono::duration<double>;

struct client
{
	std::string name;
	std::string email;
	int purchases;
	int sum;

	std::string print()
	{
		return name + " \t" + email + " \t" + std::to_string(purchases) + " \t" + std::to_string(sum);
	};
};

void bubble_sort(std::vector<client> &, int &);
void insert_sort(std::vector<client> &, int &);
client binary_search(std::vector<client>&, int, int&);


int main()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> purch(1, 100);
	std::uniform_int_distribution<> sum(50, 5000);
	std::uniform_int_distribution<> name(0,5);

	std::vector<std::string> names{"Mike","Alice","Jack","Katie","Johny","Mary"};
	std::vector<std::string> surnames{"Cage","Gordon","Weak","Piko","Lu","White"};

	int n{ 0 };

	cout << "Enter size of base: ";
	std::cin >> n;

	std::vector<client> base;

	for (int i{ 0 }; i < n; ++i)
	{
		std::string temp_name{ names[name(gen)] + " " + surnames[name(gen)]};
		base.push_back({ temp_name, temp_name + "@mail.com", purch(gen), sum(gen) });
	}
		
	//for (auto i : base)
	//	cout << i.print() << endl;

	int counter{0};
	auto comparator = [&](client a, client b)
	{
		if (a.purchases < b.purchases)
			++counter;
		return a.purchases < b.purchases;
	};

	std::vector<client> base_copy{ base };
	// STD sort
	auto start = clocks::now();
	std::sort(base.begin(), base.end(), comparator);
	auto finish = clocks::now();
	dur elapsed = finish - start;
	cout << "STD sort: " << elapsed.count() << endl;
	cout << "Counter: " << counter << endl;
	// My sort
	counter = 0;
	start = clocks::now();
	insert_sort(base_copy, counter);
	//bubble_sort(base_copy, counter);
	finish = clocks::now();
	elapsed = finish - start;
	cout << "Bubble sort: " << elapsed.count() << endl;
	cout << "Counter: " << counter << endl;
	// STD find
	counter = 0;
	int what_to_find;
	std::cin >> what_to_find;
	auto search = [&, what_to_find](client a)
	{
		++counter;
		return (a.purchases == what_to_find);
	};
	start = clocks::now();
	std::find_if(base.begin(), base.end(), search);
	finish = clocks::now();
	elapsed = finish - start;
	cout << "STD Find time: " << elapsed.count() << endl;
	cout << "Counter: " << counter << endl;
	// My find
	counter = 0;
	start = clocks::now();
	binary_search(base, what_to_find, counter);
	finish = clocks::now();
	elapsed = finish - start;
	cout << "My find time: " << elapsed.count() << endl;
	cout << "Counter: " << counter << endl;

	//
	
	std::vector<std::vector<client>::iterator> list;
	int j{ 0 };
	for (auto i = base.begin(); (i < base.end()) && (j < 500); ++i, ++j)
		list.push_back(i);

	//for (auto i : list)
	//	cout << (*i).print() << endl;
	cout << "Size of the list: " << list.size();
	
	return 0;
}

void bubble_sort(std::vector<client>& v, int &count)
{
	for (int i{ 0 }; i < v.size(); ++i) 
	{
		for (int j{ 0 }; j < v.size() - i - 1; ++j) 
		{
			if (v[j].purchases > v[j + 1].purchases)
			{
				std::swap(v[j], v[j + 1]);
			}
			++count;
		}
	}
}

void insert_sort(std::vector<client>& v, int &count) 
{
	for (int i{ 0 }; i < v.size(); ++i) 
	{
		for (int j{ i }; (j > 0) && (v[j].purchases < v[j - 1].purchases); --j) 
		{
			std::swap(v[j], v[j - 1]);
			++count;
		}
	}
}

client binary_search(std::vector<client>& v, int value, int& count)
{
	unsigned int left{ 0 };
	unsigned int right{ v.size() };
	unsigned int middle{ (left + right) / 2 };
	while (left < right - 1)
	{
		if (v[middle].purchases < value)
			left = middle;
		else 
			right = middle;
		middle = (left + right) / 2;
		++count;
	}
	return v[middle];
}