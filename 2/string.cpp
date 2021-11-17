#include <iostream>
#include "MyString.h"

int main()
{
    MyString str("H3ll3 W3.rld!3");
    std::cout << str.getString() << std::endl;
    std::cout << str.doTask_1() << std::endl; //Заменяет в строке знаком "+" все цифры "3" до первой точки, выводит кол - во таких замен
    std::cout << str.getString() << std::endl;

    MyString str1("Halla Warld!");
    std::cout << str1.getString() << std::endl;
    std::cout << str1.doTask() << std::endl; //Заменяет в строке каждую букву "а" на последнюю букву последовательности, выводит кол - во таких замен
    std::cout << str1.getString() << std::endl;
}

