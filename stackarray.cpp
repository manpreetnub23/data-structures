#include<iostream>
using namespace std;
template <class t>
class stack
{
    private:
        t *arr;
        int tos,size;
    public:
        stack();
        ~stack();
        t pop();
        int peekToTop();
        bool isEmpty();
        bool isFull();
        void push(t);
        void menu();
        void display();
};
template <class t>
stack<t>::stack()
{
    tos=-1;
    cout<<"enter size.\n";
    cin>>size;
    arr=new t[size];
}
template <class t>
stack<t>::~stack()
{
    delete[] arr;
}
template <class t>
bool stack<t>::isEmpty()
{
    if(tos==-1)
    return true;
    else 
    return false;
}
template <class t>
bool stack<t>::isFull()
{
    if(tos==size-1)
    return true;
    else
    return false;
}
template <class t>
void stack<t>::push(t el)
{
    if(isFull())
    cout<<"stack overflow.\n";
    else
    {
        tos++;
        arr[tos]=el;
        cout<<"value pushed..\n";
    }
}
template <class t>
t stack<t>::pop()
{
    if(isEmpty())
    {
        cout<<"stack underflow.\n";
        return -99;
    }
    else
    {
        t var=arr[tos];
        tos--;
        cout<<"value popped..\n";
        return var;
    }
}
template <class t>
int stack<t>::peekToTop()
{
    if(!isEmpty())
    return arr[tos];
}
template <class t>
void stack<t>::display()
{
    cout<<"your stack is : ";
    if(!isEmpty())
    {
        for(int i=tos;i>=0;i--)
        cout<<arr[i]<<" ";
    }
    else
    cout<<"\nempty\n";
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
                pop();
                
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
void meenu()
{
	int datatype;
	cout<<"enter the data type.\n1)int.\n2)float.\n3)char.\n";
	cin>>datatype;
	switch(datatype)
	{
		case 1:
		{
			stack<int> obj;
			obj.menu();
			break;
		}
		case 2:
		{
			stack<float> obj;
			obj.menu();
			break;
		}
		case 3:
		{
			stack<char> obj;
			obj.menu();
			break;
		}
	}
}
int main()
{
    meenu();
}