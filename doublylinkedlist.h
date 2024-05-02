#include <iostream>
using namespace std;
template <class t>
class node
{
public:
    t data;
    node<t> *next, *prev;
    template <class x>
    friend class dll;
};
template <class t>
class dll
{
    // private:
public:
    dll();
    ~dll();
    void menu();
    bool isEmpty();
    void display();
    void reverse();
    void insertAtHead(t);
    void insertAtTail(t);
    void insertAtI(int, t);
    void concatenate(dll l2);
    node<t> *head, *tail;
    node<t> *search(t);
    t deleteFromHead();
    t deleteFromTail();
    t deleteFromI(int);
};
template <class t>
dll<t>::dll()
{
    head = NULL;
    tail = NULL;
}
template <class t>
dll<t>::~dll()
{
}
template <class t>
bool dll<t>::isEmpty()
{
    if ((head == NULL) && (tail == NULL))
        return true;
    else
        return false;
}
template <class t>
void dll<t>::display()
{
    if (!isEmpty())
    {
        cout << "your list is : ";
        node<t> *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    else
        cout << "list is empty.\n";
}
template <class t>
void dll<t>::insertAtHead(t val)
{
    node<t> *temp = new node<t>();
    temp->data = val;
    temp->next = NULL;
    temp->prev = NULL;
    if (isEmpty())
        head = tail = temp;
    else
    {
        head->prev = temp;
        temp->next = head;
        head = temp;
    }
}
template <class t>
void dll<t>::insertAtTail(t val)
{
    node<t> *temp = new node<t>();
    temp->data = val;
    temp->next = NULL;
    temp->prev = NULL;
    if (isEmpty())
        head = tail = temp;
    else
    {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}
template <class t>
void dll<t>::insertAtI(int index, t val)
{
    node<t> *temp = new node<t>();
    temp->data = val;
    temp->next = NULL;
    temp->prev = NULL;
    if (isEmpty() && index < 1)
        cout << "invalid position.\n";
    else if (index == 1)
        insertAtHead(val);
    else
    {
        int c = 1;
        node<t> *additnode = head;
        while (c != index - 1 && additnode->next != NULL)
        {
            additnode = additnode->next;
            c++;
            // cout<<"c";
        }
        if (c == index - 1)
        {
            // cout<<"w";
            if (additnode->next == NULL)
            {
                additnode->next = temp;
                temp->prev = additnode;
                tail = temp;
            }
            else
            {
                additnode->next->prev = temp;
                temp->next = additnode->next;
                additnode->next = temp;
                temp->prev = additnode;
            }
            // temp->next=additnode->next;
            // temp->prev=additnode;
            // additnode->next->prev=temp;
            // additnode->next=temp;
            // return;
        }
        else
        {
            cout << "invalid position.\n";
        }
    }
}
template <class t>
t dll<t>::deleteFromHead()
{
    // cout<<"inside delete from head"<<endl;
    if (isEmpty())
        cout << "list is empty.\n";
    else
    {
        if (head == tail)
        {
            node<t> *temp = head;
            t delval = temp->data;
            head = tail = NULL;
            delete temp;
            return delval;
        }
        else
        {
            // cout<<"inside else part"<<endl;
            node<t> *temp = head;
            head = head->next;
            head->prev = NULL;
            t delval = temp->data;
            // cout<<"del val ka data hai : "<<delval->data<<endl;
            delete temp;
            return delval;
        }
    }
}
template <class t>
t dll<t>::deleteFromTail()
{
    if (isEmpty())
        cout << "list is empty.\n";
    else
    {
        if (head == tail)
            head = tail = NULL;
        else
        {
            node<t> *temp = tail;
            tail = tail->prev;
            tail->next = NULL;
            delete temp;
        }
    }
}
template <class t>
t dll<t>::deleteFromI(int index)
{
    if (!isEmpty())
    {
        node<t> *temp = head;
        if (index == 1)
            deleteFromHead();
        else
        {
            int c = 1;
            while (c != index && temp->next != NULL)
            {
                temp = temp->next;
                c++;
            }
            if (c == index)
            {
                if (temp == tail)
                    deleteFromTail();
                else
                {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    temp->prev = NULL;
                    temp->next = NULL;
                    delete temp;
                }
            }
            else
            {
                cout << "invalid input.\n";
            }
        }
    }
    else
        cout << "list is empty \n";
}
template <class t>
void dll<t>::concatenate(dll<t> l2)
{
    cout << "\nafter concatenation ";
    if (!isEmpty())
    {
        tail->next = l2.head;
        l2.head->prev = tail;
        l2.head = NULL;
        tail = l2.tail;
        l2.tail = NULL;
    }
    else
    {
        head = l2.head;
        l2.head = NULL;
        tail = l2.tail;
        l2.tail = NULL;
    }
    display();
    cout << "\n";
}
template <class t>
node<t> *dll<t>::search(t value)
{
    if (isEmpty())
        cout << "list is empty,unable to find element.\n";
    else
    {
        node<t> *temp = head;
        if (temp->data == value)
            return head;
        else
        {
            temp = temp->next;
            while (temp != NULL)
            {
                if (temp->data == value)
                    return temp;
                else
                    temp = temp->next;
            }
            if (temp == NULL)
            {
                cout << "element not found \n";
            }
        }
    }
    return NULL;
}
template <class t>
void dll<t>::reverse()
{
    node<t> *p = NULL;
    node<t> *curr = head;
    while (curr != NULL)
    {
        p = curr->next;
        curr->next = curr->prev;
        curr->prev = p;
        curr = curr->prev;
    }
    p = head;
    head = tail;
    tail = p;
}
template <class t>
void dll<t>::menu()
{
    char c;
    int ask, index;
    t value;
    dll<t> l2;
    do
    {
        cout << "what operation you want to perform : \n1)insert at head.\n2)insert at tail.\n3)insert at I.\n4)delete from head.\n5)delete from tail.\n6)delete from I.\n7)concatenation.\n8)search an element.\n9)reverse.\n10)display the list.\n";
        cin >> ask;
        switch (ask)
        {
        case 1:
        {
            cout << "enter value you want to insert.\n";
            cin >> value;
            insertAtHead(value);
            break;
        }
        case 2:
        {
            cout << "enter value you want to insert.\n";
            cin >> value;
            insertAtTail(value);
            break;
        }
        case 3:
        {
            cout << "enter value you want to insert.\n";
            cin >> value;
            cout << "enter the index \n";
            cin >> index;
            insertAtI(index, value);
            break;
        }
        case 4:
        {
            deleteFromHead();
            break;
        }
        case 5:
        {
            deleteFromTail();
            break;
        }
        case 6:
        {
            cout << "enter the index to delete.\n";
            cin >> index;
            deleteFromI(index);
            break;
        }
        case 7:
        {
            l2.menu();
            concatenate(l2);
            break;
        }
        case 8:
        {
            cout << "enter the value you want to search.\n";
            cin >> value;
            cout << search(value) << endl;
            break;
        }
        case 9:
        {
            cout << "reverse of ";
            reverse();
            display();
            break;
        }
        case 10:
        {
            display();
            cout << "\n";
            break;
        }
        }
        cout << "do you want to continue? enter y|n \n";
        cin >> c;
    } while (c == 'y' || c == 'Y');
}
// void meenu()
// {
// 	int datatype;
// 	cout<<"enter the data type.\n1)int.\n2)float.\n3)char.\n";
// 	cin>>datatype;
// 	switch(datatype)
// 	{
// 		case 1:
// 		{
// 			dll<int> obj;
// 			obj.menu();
// 			break;
// 		}
// 		case 2:
// 		{
// 			dll<float> obj;
// 			obj.menu();
// 			break;
// 		}
// 		case 3:
// 		{
// 			dll<char> obj;
// 			obj.menu();
// 			break;
// 		}
// 	}
// }
// int main()
// {
//     meenu();
// }