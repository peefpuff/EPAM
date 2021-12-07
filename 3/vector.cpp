//1. Разработать класс «вектор» (одномерный динамический массив). Методы класса: конструкторы, деструктор и методы преобразования массива в соответствии с вариантом. 
//2. Ввести 2 массива по 10 элементов, используя различные конструкторы.
//3. Один из массивов отсортировать(четные варианты – по убыванию, нечетные – по возрастанию), найти минимальное, среднее и максимальное значение массива.
//4. Для второго массива выполнить задание по варианту
// Вариант 18: Преобразовать массив так, чтобы сначала располагались элементы в интервале [а, b], а потом – все остальные

#include "myVector.h"
#include <random>

int main()
{
    myVector<int> v1;
    myVector<int> v2{ 1, 77, 3, 15, 10, 23, 61, -4, 40, 117};
    myVector<double> v3;
    myVector<double> v4;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(-10.0, 10.0);
    std::uniform_int_distribution<> dist_int(-50, 50);

    for (int i = 0; i < 10; ++i)
    {
        v1.push_back(dist_int(gen));
        v3.push_back(dist(gen));
    }

    v4 = v3;

    std::cout << "First vector:" << std::endl;
    v1.print();
    std::cout << "size: " << v1.size() << " capacity: " << v1.capacity() << " min: " << v1.min() << " max: " << v1.max() << " average: " << v1.average() << std::endl;

    v1.pop_back();
    std::cout << v1.size();
    /*std::cout << "sorted: " << std::endl;
    v1.sort();
    v1.print();

    std::cout << "Second vector:" << std::endl;
    v2.print();
    std::cout << std::endl;
    int a, b;
    std::cout << "Input [a,b]: ";
    std::cin >> a >> b;
    v2.doTask(a,b);
    std::cout << "After doTask():" << std::endl;
    v2.print();

    std::cout << "Double vector v3: " << std::endl;
    v3.print();
    std::cout << "Double vector v4: " << std::endl;
    v4.print();
    */
}
