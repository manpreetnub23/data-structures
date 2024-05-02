#include<iostream>
#include"doublylinkedlist.h"
using namespace std;
template <typename t>
class queue{
    public:
        dll<t> x;
        void enqueue(t el)
        {
            x.insertAtTail(el);
        }
        t dequeue()
        {
            if(!x.isEmpty())
            {
                t delval=x.deleteFromHead();
                return delval;
            }
            else
            {
                return -99;
            }
        }
        void display()
        {
            x.display();
        }
        void menu()
        {
            t value;
            int ask;
            char choice;
            do
            {
                cout<<"1)Enqueue.\n2)Dequeue.\n3)display.\n";
                cin>>ask;
                switch(ask)
                {
                    case 1:
                    {
                        cout<<"enter the value.\n";
                        cin>>value;
                        enqueue(value);
                        break;
                    }
                    case 2:
                    {
                        cout<<"value that is dequeued : "<<dequeue()<<"\n";
                        break;
                    }
                    case 3:
                    {
                        x.display();
                        break;
                    }
                }
                cout<<"do you want to continue ? enter y|n \n";
                cin>>choice;
            }while(choice=='y' || choice=='Y');
        }
};
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
