#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "employee.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    std::vector<employee> arr;

    auto emptyList = []() { cout << "List is empty! Load from file first" << endl; };

    int action{ 0 };

    do
    {
        cout << "---------------------------------------------------------" << endl;
        cout << "1. Load from file" << endl;
        cout << "2. Print" << endl;
        cout << "3. Sort" << endl;
        cout << "4. Birth in month" << endl;
        cout << "5. The oldest man" << endl;
        cout << "6. All surnames, starts from char" << endl;
        cout << "0. Exit" << endl;
        cout << "Select the action: ";
        cin >> action;

        cout << "---------------------------------------------------------" << endl;
    
        switch (action)
        {
        case 1:
        {
            // загрузка данных из файла 
            std::ifstream input("input.txt");
            if (!input)
            {
                cout << "file not found!" << endl;
            }
            int i{ 0 };
            // построчно считываем файл пока не дойдём до его конца
            while (!input.eof())
            {
                // формат файла:
                // фамилия
                // имя
                // пол (F - женский (female), M - мужской (male))
                // день рождения в формате YYYY-MM-DD
                employee tmp;
                string temp;
                input >> temp;
                tmp.setSurname(temp);
                input >> temp;
                tmp.setName(temp);
                input >> temp;
                tmp.setGender(temp[0]);
                input >> temp;
                tmp.setDate(temp);
                arr.push_back(tmp); // сохраняем данные в векторе
                ++i;
            }
            input.close();
            cout << i << " employes added successfully!" << endl;
        }
            break;
        case 2:
            // вывод списка работников на экран
            if (!arr.empty()) // сначала проверяем, есть ли данные
                for (auto i : arr) 
                    cout << i.printEmployee() << endl;
            else emptyList(); // если список пустой, то сообщаем об этом и ничего больше не делаем
            break;
        case 3:
            // сортировка списка по фамилиям в алфавитном порядке
            if (!arr.empty())
            {
                std::sort(arr.begin(), arr.end(), [](employee a, employee b) { return a.getSurname() < b.getSurname(); });
                cout << "List sorted!" << endl;
            }
            else emptyList();
            break;
        case 4:
            // поиск всех работников, родившихся в заданный месяц
            if (!arr.empty())
            {
                cout << "Input month: ";
                int month{ 0 };
                cin >> month;
                cout << endl;
                std::for_each(arr.begin(), arr.end(),
                    [month](employee a) 
                    {
                        // дата указана в формате строки YYYY-MM-DD
                        // с помощью substr(5) выделяем из неё MM-DD
                        // stoi преобразует самую длинную последовательность в строке в целое число
                        // в нашем случае этой последовательностью будет MM (символ '-' выступает разделителем)
                        string date = a.getDate();
                        int birth_month{ std::stoi(date.substr(5)) };
                        // выводим всех подходящих работников
                        if (birth_month == month)
                            cout << a.printEmployee() << endl;
                    });
            }
            else emptyList();
            break;
        case 5:
            // поиск самого старшего работника-мужчины
            if (!arr.empty())
            {
                // поиск минимальной строки даты в списке, где gender = 'M'
                // здесь формат YYYY-MM-DD облегчает задачу
                // достаточно просто сравнить две строки, меньше строка == дата раньше
                std::vector<employee>::iterator oldest = arr.begin();
                for (auto i = arr.begin() + 1; i != arr.end(); ++i)
                    if ((*i).getGender() == 'M')
                        if ((*oldest).getDate().compare((*i).getDate()) > 0) oldest = i;
                        // str1.compare(str2) возвращает >0, если str1 > str2
                // проверяем oldest - если он не изменился (т.е. равен begin), то 
                // либо в списке нет мужчин, либо первый работник в списке самый старший мужчина
                if ((oldest != arr.begin()) || ((*oldest).getGender() == 'M')) 
                    cout << (*oldest).printEmployee() << endl;
                else cout << "There are no males in the list!" << endl;
            }
            else emptyList();
            break;
        case 6:
            // поиск по первой букве фамилии
            if (!arr.empty())
            {
                cout << "Input char for searching in surname: ";
                char c;
                cin >> c;
                cout << endl;
                std::for_each(arr.begin(), arr.end(),
                    [c](employee a)
                    {
                        string sur{ a.getSurname() };
                        if (sur[0] == c) 
                            cout << a.printEmployee() << endl;
                    });
            }
            else emptyList();
            break;
        case 0:
            // завершение работы программы
            return 0;
        default:
            cout << "Wrong action!" << endl;
            break;
        }

    } while (1);   
}