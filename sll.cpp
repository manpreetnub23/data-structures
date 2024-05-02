#include "sll.h"
int main()
{
    int datatype;
    cout << "enter the data type.\n1)int.\n2)float.\n3)char.\n";
    cin >> datatype;
    switch (datatype)
    {
    case 1:
    {
        sll<int> obj;
        obj.menu();
        break;
    }
    case 2:
    {
        sll<float> obj;
        obj.menu();
        break;
    }
    case 3:
    {
        sll<char> obj;
        obj.menu();
        break;
    }
    }
}