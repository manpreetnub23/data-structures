#include"circularll.h"
// #include<iostream>
int main()
{
    int datatype;
    cout<<"enter the data type.\n1)int.\n2)float.\n3)char.\n";
    cin>>datatype;
    switch(datatype)
    {
        case 1:
        {
            cll<int> obj;
            obj.menu();
            break;
        }
        case 2:
        {
            cll<float> obj;
            obj.menu();
            break;
        }
        case 3:
        {
            cll<char> obj;
            obj.menu();
            break;
        }
    }
}
