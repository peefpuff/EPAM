#include "matrix.h"

int main()
{
    int rows, columns;
    cout << "Enter number of lines: ";
    std::cin >> rows;
    cout << endl;
    cout  << "Enter number of columns: ";
    std::cin >> columns;
    cout << endl;

    matrix m(rows,columns);
    m.print();
    doTask(m);
}
