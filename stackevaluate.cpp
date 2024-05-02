#include "sll.h"
#include <string>
#include <math.h>
template <class t>
class stack
{
public:
    sll<t> obj;
    stack<t>();
    ~stack<t>();
    t push(t);
    t pop();
    t display();
    t evaluate();
    bool isEmpty();
    void peekToTop();
    void menu();
};
template <class t>
stack<t>::stack()
{
}
template <class t>
stack<t>::~stack()
{
}
template <class t>
bool stack<t>::isEmpty()
{
    if (!obj.isEmpty())
    {
        cout << obj.head->data;
    }
    else
        cout << "stack is empty.\n";
}
template <class t>
void stack<t>::peekToTop()
{
    if(!obj.isEmpty())
    {
        cout<<obj.head->data;
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
t stack<t>::evaluate()
{
    string s;
    cout << "enter the expression.\n";
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '$')
        {
            int var1 = pop();
            int var2 = pop();
            switch (s[i])
            {
            case '+':
            {
                int calc = var2 + var1;
                push(calc);
                break;
            }
            case '-':
            {
                int calc = var2 - var1;
                push(calc);
                break;
            }
            case '*':
            {
                int calc = var2 * var1;
                push(calc);
                break;
            }
            case '/':
            {
                int calc = var2 / var1;
                push(calc);
                break;
            }
            case '$':
            {
                int calc = pow(var2, var1);
                push(calc);
                break;
            }
            }
        }
        else
        {
            int store = s[i] - 48;
            push(store);
        }
    }
    // peekToTop();
}
// t stack<t>::push(t el)
// {
//     obj.insertAtHead(el);
// }
template <class t>
t stack<t>::push(t el)
{
    obj.insertAtHead(el);
}
template <class t>
t stack<t>::pop()
{
    if (!obj.isEmpty())
    {
        t delval = obj.deleteFromHead();
        return delval;
    }
    else
        return -99;
}
template <class t>
void stack<t>::menu()
{
    int value, ask;
    char choice;
    do
    {
        cout << "1)push the element.\n2)pop the element.\n3)peek to top.\n4)display the stack.\n";
        cin >> ask;
        switch (ask)
        {
        case 1:
        {
            cout << "enter the value.\n";
            cin >> value;
            push(value);

            break;
        }
        case 2:
        {
            cout << "value that is popped out : " << pop() << "\n";
            break;
        }
        case 3:
        {
            cout << "value at top of stack is : ";
            peekToTop();
            break;
        }
        case 4:
        {
            display();
            cout << "\n";
            break;
        }
        default:
            cout << "invalid input.\n";
            break;
        }
        cout << "do you want to continue ? enter y|n \n";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
}
int main()
{
    // int datatype;
    // cout<<"enter the data type.\n1)int.\n2)float.\n3)char.\n";
    // cin>>datatype;
    // switch(datatype)
    // {
    //     case 1:
    //     {
    //         stack<int> x;
    //         x.menu();
    //         break;
    //     }
    //     case 2:
    //     {
    //         stack<float> x;
    //         x.menu();
    //         break;
    //     }
    //     case 3:
    //     {
    //         stack<char> x;
    //         x.menu();
    //         break;
    //     }
    // }
    stack<float> obj;
    obj.evaluate();
    cout<<"the final value at top of stack after all calculations is : ";
    obj.peekToTop();
}