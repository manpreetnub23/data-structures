#include "heap.h"
int main()
{
    int datatype;
    std::cout << "enter the data type.\n1)int.\n2)float.\n3)char.\n";
    std::cin >> datatype;
    switch (datatype)
    {
    case 1:
    {
        heap<int> obj;
        obj.menu();
        break;
    }
    case 2:
    {
        heap<float> obj;
        obj.menu();
        break;
    }
    case 3:
    {
        heap<char> obj;
        obj.menu();
        break;
    }
    }
}