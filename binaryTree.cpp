#include "binaryTree.h"
int main()
{
    int datatype;
    std::cout << "enter the data type.\n1)int.\n2)float.\n3)char.\n";
    std::cin >> datatype;
    switch (datatype)
    {
    case 1:
    {
        binaryTree<int> obj;
        obj.menu();
        break;
    }
    case 2:
    {
        binaryTree<float> obj;
        obj.menu();
        break;
    }
    case 3:
    {
        binaryTree<char> obj;
        obj.menu();
        break;
    }
    }
}