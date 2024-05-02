#include "bst.h"
int main()
{
    int dataType;
    cout << "enter the datatype.\n1)int.\n2)float.\n3)char.\n";
    cin >> dataType;
    switch (dataType)
    {
    case 1:
    {
        bst<int> x;
        x.menu();
        break;
    }
    case 2:
    {
        bst<float> x;
        x.menu();
        break;
    }
    case 3:
    {
        bst<char> x;
        x.menu();
        break;
    }
    }
    // bst<int> x;
    // x.insertNode(10);
    // x.insertNode(20);
    // treeNode<int> *point=x.search(10);
    // cout<<"height of 10 is "<<x.height(point);
} 