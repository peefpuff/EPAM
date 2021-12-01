#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <string_view>
#include <random>
#include <numeric>

using std::cout;
using std::endl;
using std::cin;

int main()
{
    int n{ 0 };
    cout << "Enter the size of the vector: ";
    cin >> n;
    cout << endl;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(-50, 200);
    std::vector<int> arr;

    for (int i = 0; i < n; ++i)
        arr.push_back(dist(gen));
    
    // 1. Создать лямбда-выражение для вывода элементов вектора.

    auto print = [] (int i) { cout << i << " "; };
    
    cout << "Initial vector: ";
    for (int i : arr) print(i);

    int count{ 0 };

    // 2. Создать лямбда-выражение для подсчета количества перестановок при выполнении сортировки элементов вектора
    std::sort(arr.begin(), arr.end(), [&count](int a, int b)
        {
            if (a > b)
            count++;
            return a > b;
        });
    cout << endl << "Sorted vector: ";
    for (int i : arr) print(i);
    cout << endl << "Swap counter: " << count << endl;


    // 3. Создать лямбда - выражение для поиска вхождения подстроки, задаваемой пользователем, в строку.
    std::vector <std::string_view> str{ "banana", "meat", "soup", "potato", "ice-cream" };

    cout << "String array: ";
    for (auto i : str) cout << i << " ";

    cout << endl << "search for: ";
    std::string search;
    cin >> search;

    auto find = [search](std::string_view str)
    {
        return (str.find(search) != std::string_view::npos);
    };

    auto found{ std::find_if(str.begin(), str.end(), find) };
    if (found == str.end())
    {
        cout << "Not found" << endl;
    }
    else
    {
        cout << "Found: " << *found << endl;
    }

    // Выполнить генерацию вектора из N последовательных элементов (например, 0 1 2 3 4)
    // Сформировать новый вектор по следующему правилу: 
    // отбросить слева k первых элементов и добавить k последовательных элементов в конец вектора
    // (например, k = 2, новый вектор 2 3 4 5 6)
    
    cout << "Enter n: ";
    cin >> n;
    
    std::vector<int> arr1(n), arr2(n);

    std::iota(arr1.begin(), arr1.end(), 1);

    cout << endl << "Initial vector: ";
    for (int i : arr1) print(i);

    int k{ 0 };
    do
    {
        cout << endl << "Enter n (k <= n): ";
        cin >> k;
    } 
    while (k > n);

    auto doTask = [k](int a)
    {
        return a + k;
    };

    std::transform(arr1.begin(),arr1.end(), arr2.begin(), doTask);

    cout << endl << "New vector: ";
    for (int i : arr2) print(i);
}