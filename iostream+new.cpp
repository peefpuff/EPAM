// 1. Определить комбинированный (структурный) тип, содержащий информацию о студенте: фамилия, имя, массив из 3-х оценок.
// 2. Определить динамический массив структур, состоящий из N элементов (N>=5, вводится с клавиатуры).
// 3. Выполнить ввод элементов в массив структур.
// 4. Вывести исходный массив структур на консоль, разработав функцию для форматного вывода элементов массива.
// 5. Разработать функцию для сортировки массива структур по убыванию; признак для сортировки: суммарный балл по 3-м предметам.
// 6. Вывести измененный массив структур на консоль, используя созданную в п. 4 функцию.
// 7. Освободить динамически выделенную память под массив структур


#include <iostream>

struct student
{
    char name[15];
    char surname[15];
    int scor[3];
};

int sum_mark(student st);
void sort(student *st, int n);
void show(student *st, int n);

int main()
{
    setlocale(LC_ALL, "Russian");
    
//вводим значение n с клавиатуры до тех пор, пока оно не будет удолетворять условию (>=5)
    do
    {
        std::cout << "Введите кол-во студентов в группе: (>=5)" << std::endl;
        std::cin >> n;
    } 
    while (n < 5);

    
    student* group = new student[n];

// заполнение массива данными с клавиатуры
    for (int i = 0; i < n; i++)
    {
        std::cout << "Введите имя" << std::endl;
        std::cin >> group[i].name;
        std::cout << "Введите фамилию" << std::endl;
        std::cin >> group[i].surname;

        for (int j = 0; j < 3; j++)
        {
            std::cout << "Введите оценку " << j + 1  << std::endl;
            std::cin >> group[i].scor[j];
        }
        
    }

    show(group, n);
    std::cout << "------------------Сортировка-----------------------" << std::endl;
    sort(group, n);

    show(group,n);

    delete[] group;
        
}

// функция для подсчёта суммы всех оценок студента
int sum_mark(student st)
{
    int sum = 0;

    for (int i = 0; i < 3; i++)
    {
        sum += st.scor[i];
    }

    return sum;
}

// функция сортировки массива по возрастанию. Критерий сортировки - сумма всех оценок
void sort(student *st, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - i - 1; j++)
        {
            if (sum_mark(st[j]) < sum_mark(st[j + 1]))
            {
                std::swap(st[j], st[j + 1]);
            }
        }
}

// функция для вывода массива
void show(student *st, int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << "Имя: " << st[i].name << "\tФамилия: " << st[i].surname;
        std::cout << " \tОценки: ";
        for (int j = 0; j < 3; j++)
        {
            std::cout << st[i].scor[j] << " ";
        }
        std::cout << "\tСумма баллов: " << sum_mark(st[i]) << std::endl;
    }  
}