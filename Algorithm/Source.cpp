#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <chrono>

using std::cout;
using std::endl;
using clocks = std::chrono::steady_clock;
using dur = std::chrono::duration<double>;

void bubble_sort(std::vector<int> &, int &);
void insert_sort(std::vector<int>& obj);

int main()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(0, 100);

	int n{ 0 };

	cout << "Enter size of vector: ";
	std::cin >> n;

	std::vector<int> arr(n);

	for (int i{ 0 }; i < arr.size(); ++i)
		arr[i] = dist(gen);

	int counter{ 0 };
	auto comparator = [&](int a, int b)
	{
		if (a < b)
			++counter;
		return a < b;
	};
	
	auto start = clocks::now();
	std::sort(arr.begin(), arr.end(), comparator);
	auto finish = clocks::now();
	dur elapsed = finish - start;
	cout << "STD sort: " << elapsed.count() << endl;
	cout << "Counter: " << counter << endl;

	for (int i{ 0 }; i < arr.size(); ++i)
		arr[i] = dist(gen);

	counter = 0;
	start = clocks::now();
	bubble_sort(arr, counter);
	finish = clocks::now();
	elapsed = finish - start;
	cout << "Bubble sort: " << elapsed.count() << endl;
	cout << "Counter: " << counter << endl;

	for (int i{ 0 }; i < arr.size(); ++i)
		arr[i] = dist(gen);

	counter = 0;
	start = clocks::now();
	insert_sort(arr);
	finish = clocks::now();
	elapsed = finish - start;
	cout << "Insert sort: " << elapsed.count() << endl;
	cout << "Counter: " << counter << endl;

	return 0;
}

void bubble_sort(std::vector<int>& v, int &count)
{
	for (int i{ 0 }; i < v.size(); ++i) 
	{
		for (int j{ 0 }; j < v.size() - i - 1; ++j) 
		{
			if (v[j] > v[j + 1])
			{
				std::swap(v[j], v[j + 1]);
			}
			++count;
		}
	}
}

void insert_sort(std::vector<int>& obj) 
{
	for (int i{ 0 }; i < obj.size(); ++i) 
	{
		for (int j{ i }; (j > 0) && (obj[j] < obj[j - 1]); --j) 
		{
			std::swap(obj[j], obj[j - 1]);
		}
	}
}