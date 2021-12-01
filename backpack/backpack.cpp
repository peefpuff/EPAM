#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <random>
#include <ranges>
#include <format>

namespace rng = std::ranges;
namespace view = rng::views;

using std::cout;
using std::endl;
using std::cin;
using std::format;

class item
{
public:
    item(std::string str, int w, int p) : name(str), weight(w), price(p) {};
    ~item() {};

    int getWeight() { return weight; };
    int getPrice() { return price; };


    std::string print() 
    { 
        return format("{:^10}|{:^10}|{:^10}|", name, weight, price);
    };
private:
    std::string name;
    int weight;
    int price;
};


void findItems(int n, int w, int** A, std::vector<item>& arr, std::vector<item>& backpack)
{
    // если значение в ячейке == 0, значит дошли до края массива и пора возвращаться=)
    if (A[n][w] == 0) return;
    // если ценность наборов из n и (n - 1) предметов при вместимости w совпадает, то ищем дальше
    if (A[n - 1][w] == A[n][w]) findItems(n - 1, w, A, arr, backpack);
    // а если ценность наборов отличается, значит предмет под номером n нам подходит
    // добавляем предмет в рюкзак и продолжаем поиск по тому же принципу,
    // но уже среди наборов c весом (w - n.w) где n.w - вес последнего найденного премета
    else 
    {
        findItems(n - 1, w - arr[n - 1].getWeight(), A, arr, backpack);
        backpack.push_back(arr[n - 1]);
    }
}

int main()
{
    std::vector<item> arr;

    int n;
    int w;

    cout << "How many items to create? - ";
    cin >> n;
    cout << endl << "Size of backpack - ";
    cin >> w;
    cout << endl;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> weight(1, w);
    std::uniform_int_distribution<> price(1, 100);

    // генерируем набор предметов
    for (int i : view::iota(0, n))
        arr.push_back(item("item-" + std::to_string(i + 1), weight(gen), price(gen)));
    
    auto printLine = []()
    {
        cout << format("{:-^32}|", '-') << endl;
    };

    // выводим список сгенерированных предметов на экран
    printLine();
    cout << format("{:^10}|{:^10}|{:^10}|", "items", "weight", "price") << endl;
    for (auto i : arr)
    {
        printLine();
        cout << i.print() << endl;
    }
    printLine();

    // нулевая строка и столбец заполняется нулями, 
    // соотв. размер массива будет на 1 меньше значений n и w
    // компенсируем это инкрементом (это проще, чем везде прописывать (n + 1)и (w + 1))
    ++n;
    ++w;

    // выделяем память под двумерный массив
    int **A = new int*[n];
    for (int i = 0; i < n; ++i)
        A[i] = new int[w];

    // заполняем массив
    // кол-во предметов, j - промежуточный вес рюкзака
    // для каждого кол-ва предметов находим стоимость рюкзаков разной вместимости
    // в А[i][j] хранится максимальная стоимость набора из i предметов для вместимости j
    for (int  i : view::iota(0, n))
        for (int j : view::iota(0, w))
        {
            // нулевую строку и столбец заполняем нулями
            if ((i == 0) || (j == 0))
            {
                A[i][j] = 0;
                // для нулевых столбца и строки делать больше ничего не нужно, поэтому
                continue;
            }
            // arr[i - 1] т.к. заполнение массива значениями начинается c i = 1 и j = 1, а первый предмет находится в arr[0]
            // проверяем, помещается ли предмет в рюкзак
            if (j >= arr[i - 1].getWeight()) 
                // если помещается, то смотрим что выгоднее:
                // оставить предыдущий набор предметов или составить новый набор с этим предметом
                A[i][j] = std::max(A[i - 1][j], A[i - 1][j - arr[i - 1].getWeight()] + arr[i - 1].getPrice()); 
            // если предмет не помещается, то оставляем предыдущий набор предметов
            else A[i][j] = A[i - 1][j];
        }
    // в итоге в ячейке А[n-1][w-1] находится максимальная ценность рюкзака
    
    // вывод массива А на экран
    /*auto horizontalLine = [w]()
    {

        int n{ w - 1 };
        //for (int i = 0, n = w - 1; i < n; ++i)
        for (int i : view::iota(0, n))
            cout << "-------";
        cout << "------|" << endl;
    };

    horizontalLine();
    for (int i : view::iota(0, n))
    {
        if (!i)
        {
            for (int j : view::iota(1, w))
                cout << format("{:^6}|", j);
            cout << endl;
            horizontalLine();
        }
        for (int j = 1; j < w; ++j)
            cout << format("{:^6}|", A[i][j]);
        cout << endl;
        horizontalLine();
    }*/

    // создаём наш рюкзак
    std::vector<item> backpack;

    // восстанавливаем список предметов максимальной ценности
    // n и w уменьшаем на 1, чтобы не выйти за пределы массива
    findItems(n-1, w-1, A, arr, backpack);

    // выводим список предметов и заодно считаем итоговый вес и стоимость
    cout << endl;
    printLine();
    cout << format("{:^32}|", "contents of the backpack") << endl;
    printLine();
    cout << format("{:^10}|{:^10}|{:^10}|", "items", "weight", "price") << endl;
    printLine();
    int totalWeight{ 0 }, totalPrice{ 0 };
    for (auto i : backpack)
    {
        cout << i.print() << endl;
        totalWeight += i.getWeight();
        totalPrice += i.getPrice();
        printLine();
    }
    cout << format("{:^10}|{:^10}|{:^10}|", "Total", totalWeight, totalPrice) << endl;
    printLine();

    // освобождаем выделенную память
    for (int i = 0; i < n; ++i)
        delete[] A[i];
    delete[] A;
}