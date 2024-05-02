// #include<iostream>
#include<bits/stdc++.h>
#include<string.h>
using namespace std;
template <class t>
class stacks
{
    private:
        t *arr;
        int tos,size;
    public:
        stacks();
        ~stacks();
        t pop();
        int peekToTop();
        bool isEmpty();
        bool isFull();
        void push(t);
        void menu();
        void display();
        bool isPalindrome();
};
template <class t>
stacks<t>::stacks()
{
    tos=-1;
    cout<<"enter size.\n";
    cin>>size;
    arr=new t[size];
}
template <class t>
stacks<t>::~stacks()
{
    delete[] arr;
}
template <class t>
bool stacks<t>::isEmpty()
{
    if(tos==-1)
    return true;
    else 
    return false;
}
template <class t>
bool stacks<t>::isFull()
{
    if(tos==size-1)
    return true;
    else
    return false;
}
template <class t>
void stacks<t>::push(t el)
{
    if(isFull())
    cout<<"stacks overflow.\n";
    else
    {
        tos++;
        arr[tos]=el;
        cout<<"value pushed..\n";
    }
}
template <class t>
t stacks<t>::pop()
{
    if(isEmpty())
    {
        cout<<"stacks underflow.\n";
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
int stacks<t>::peekToTop()
{
    if(!isEmpty())
    return arr[tos];
}
template <class t>
void stacks<t>::display()
{
    cout<<"your stacks is : ";
    if(!isEmpty())
    {
        for(int i=tos;i>=0;i--)
        cout<<arr[i]<<" ";
    }
    else
    cout<<"\nempty\n";
}
template<class t>
bool stacks<t>::isPalindrome()
{
    string s;
    cout<<"enter string to check if it is palindorme or not.\n";
    cin>>s;
    int length = s.size();
    int i, mid = length/2;
    for(i = 0; i < mid; i++)
        push(s[i]);
    //checking if length is odd or even.if odd then skip the middle character,else continue.
    if(length % 2!= 0)
        i++;
    char ele;
    while(s[i]!='\0')  //while string is not empty.
    {
        ele = peekToTop();
        pop();
        if(ele!=s[i])
            return false;
        i++;
    }
    return true;
}
template <class t>
void stacks<t>::menu()
{
    int value,ask;
    char choice;
    do
    {
        cout<<"1)push the element.\n2)pop the element.\n3)peek to top.\n4)display the stacks.\n5)to check a string palindrome.\n";
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
                cout<<"value at top of stacks is : "<<peekToTop()<<endl;
                break;
            }
            case 4:
            {
                display();
                cout<<"\n";
                break;
            }
            case 5:
                if(isPalindrome())
                    cout<<"string is palindrome.\n";
                else   
                    cout<<"string is not palindrome.\n";
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
			stacks<int> obj;
			obj.menu();
			break;
		}
		case 2:
		{
			stacks<float> obj;
			obj.menu();
			break;
		}
		case 3:
		{
			stacks<char> obj;
			obj.menu();
			break;
		}
	}
}
int main()
{
    meenu();
    // stacks<char> x;
    // if(x.isPalindrome())
    //     cout<<"string is palindrome.\n";
    // else
    //     cout<<"string is not palindrome.\n";
}