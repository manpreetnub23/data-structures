#include"sll.h"
template <class t>
class stack{
    public:
        sll<t> obj;
        stack<t>();
        ~stack<t>();
        t push(t);
        t pop();
        t peekToTop();
        t display();
        bool isEmpty();
        void menu();
};
template<class t>
stack<t>::stack()
{}
template <class t>
stack<t>::~stack()
{}
template <class t>
bool stack<t>::isEmpty()
{
    t var=obj.isEmpty();
    return var;
}
template <class t>
t stack<t>::peekToTop()
{
    if(!obj.isEmpty())
    {
        return obj.head->data;
    }
    else
        cout<<"stack is empty.\n";
}
template <class t>
t stack<t>::display()
{
    obj.display();
}
template <class t>
t stack<t>::push(t el)
{
    obj.insertAtHead(el);
}
template <class t>
t stack<t>::pop()
{
    if(!obj.isEmpty())
    {
        t delval=obj.deleteFromHead();
        return delval;
    }
    else
        return -99;
}
template <class t>
void stack<t>::menu()
{
    int value,ask;
    char choice;
    do
    {
        cout<<"1)push the element.\n2)pop the element.\n3)peek to top.\n4)display the stack.\n";
        cin>>ask;
        switch(ask)
        {
            case 1:
            {
                cout<<"enter the value.\n";
                cin>>value;
                push(value);
               
                break;
            }
            case 2:
            {
                cout<<"value that is popped out : "<<pop()<<"\n";
                break;
            }
            case 3:
            {
                cout<<"value at top of stack is : "<<peekToTop()<<endl;
                break;
            }
            case 4:
            {
                display();
                cout<<"\n";
                break;
            }
            default:
                cout<<"invalid input.\n";
                break;
        }
        cout<<"do you want to continue ? enter y|n \n";
        cin>>choice;
    }while(choice=='y' || choice=='Y');
}
int main()
{
    int datatype;
    cout<<"enter the data type.\n1)int.\n2)float.\n3)char.\n";
    cin>>datatype;
    switch(datatype)
    {
        case 1:
        {
            stack<int> x;
            x.menu();
            break;
        }
        case 2:
        {
            stack<float> x;
            x.menu();
            break;
        }
        case 3:
        {
            stack<char> x;
            x.menu();
            break;
        }
    }
}