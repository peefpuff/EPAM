//1. Разработать класс «вектор» (одномерный динамический массив). Методы класса: конструкторы, деструктор и методы преобразования массива в соответствии с вариантом. 
//2. Ввести 2 массива по 10 элементов, используя различные конструкторы.
//3. Один из массивов отсортировать(четные варианты – по убыванию, нечетные – по возрастанию), найти минимальное, среднее и максимальное значение массива.
//4. Для второго массива выполнить задание по варианту
// Вариант 18: Преобразовать массив так, чтобы сначала располагались элементы в интервале [а, b], а потом – все остальные

#include "myVector.h"

int main()
{
    myVector v1;
    myVector v2{ 1, 77, 3, 15, 10, 23, 61, -4, 40, 117};

    v1.push_back(2);
    v1.push_back(-1);
    v1.push_back(23);
    v1.push_back(15);
    v1.push_back(10);
    v1.push_back(-17);
    v1.push_back(13);
    v1.push_back(0);
    v1.push_back(69);
    v1.push_back(47);

    std::cout << "First vector:" << std::endl;
    v1.print();
    std::cout << "size: " << v1.size() << " capacity: " << v1.capacity() << " min: " << v1.min() << " max: " << v1.max() << " average: " << v1.average() << std::endl;
    std::cout << "sorted: " << std::endl;
    v1.sort();
    v1.print();

    std::cout << "Second vector:" << std::endl;
    v2.print();
    int a, b;
    std::cout << "Input [a,b]: ";
    std::cin >> a >> b;
    v2.doTask(a,b);
    std::cout << "After doTask():" << std::endl;
    v2.print();

}
