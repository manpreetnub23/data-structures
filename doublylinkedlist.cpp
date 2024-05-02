#include"doublylinkedlist.h"
int main()
{
    	int datatype;
        cout<<"enter the data type.\n1)int.\n2)float.\n3)char.\n";
        cin>>datatype;
        switch(datatype)
        {
            case 1:
            {
                dll<int> obj;
                obj.menu();
                break;
            }
            case 2:
            {
                dll<float> obj;
                obj.menu();
                break;
            }
            case 3:
            {
                dll<char> obj;
                obj.menu();
                break;
            }
        }
}