#include"double_ended_queue.h"
int main()
{
    int datatype;
    cout<<"enter the data type.\n1)int.\n2)float.\n3)char.\n";
    cin>>datatype;
    switch(datatype)
    {
        case 1:
        {
            queue<int> z;
            z.menu();
            break;
        }
        case 2:
        {
            queue<float> z;
            z.menu();
            break;
        }
        case 3:
        {
            queue<char> z;
            z.menu();
            break;
        }
    }
}
