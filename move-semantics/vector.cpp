#include "myVector.h"
#include <random>

int main()
{
    myVector<double> v1;
    myVector<double> v2;
    myVector<double> v3;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(-10.0, 10.0);
    
    for (int i = 0; i < 10; ++i)
        v1.push_back(dist(gen));

    std::cout << "v1:" << std::endl;
    std::cout << "size: " << v1.size() << " capacity: " << v1.capacity() << endl;
    v1.print();

    std::cout << "v2:" << std::endl;
    std::cout << "size: " << v2.size() << " capacity: " << v2.capacity() << endl;
    v2.print();

    std::cout << "v3:" << std::endl;
    std::cout << "size: " << v3.size() << " capacity: " << v3.capacity() << endl;
    v3.print();

    myVector v4(v1);
    std::cout << "v4 (created with copy constructor from v1): " << std::endl;
    std::cout << "size: " << v4.size() << " capacity: " << v4.capacity() << endl;
    v4.print();

    myVector v5(std::move(v1));
    std::cout << "v5(created with move constructor from v1): " << std::endl;
    std::cout << "size: " << v5.size() << " capacity: " << v5.capacity() << endl;
    v4.print();

    std::cout << "v1:" << std::endl;
    std::cout << "size: " << v1.size() << " capacity: " << v1.capacity() << endl;
    v1.print();

    v2 = std::move(v4);
    std::cout << "v2 (modified with moving assignment from v4):" << std::endl;
    std::cout << "size: " << v2.size() << " capacity: " << v2.capacity() << endl;
    v2.print();

    std::cout << "v4: " << std::endl;
    std::cout << "size: " << v4.size() << " capacity: " << v4.capacity() << endl;
    v4.print();
    
}
