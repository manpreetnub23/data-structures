#include "doublylinkedlist.h"
using namespace std;
template <typename t>
class queue
{
public:
    dll<t> x;
    bool isEmptyy()
    {
        return x.isEmpty();
    }
    void enqueueAtFront(t el)
    {
        x.insertAtHead(el);
    }
    void enqueueAtRear(t el)
    {
        x.insertAtTail(el);
    }
    t dequeueFromFront()
    {
        t temp = x.deleteFromHead();
        return temp;
    }
    t dequeueFromRear()
    {
        t delval = x.deleteFromTail();
        return delval;
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
            cout << "1)Enqueue at front.\n2)Enqueue at rear.\n3)Dequeue from Front.\n4)Dequeue from rear.\n5)peek to Front.\n6)peek to rear.\n";
            cin >> ask;
            switch (ask)
            {
            case 1:
            {
                cout << "enter the value.\n";
                cin >> value;
                enqueueAtFront(value);
                break;
            }
            case 2:
            {
                cout << "enter the value.\n";
                cin >> value;
                enqueueAtRear(value);
                break;
            }
            case 3:
            {
                cout << "value that is dequeued : " << dequeueFromFront() << "\n";
                break;
            }
            case 4:
            {
                cout << "value that is dequeued : " << dequeueFromRear() << "\n";
                break;
            }
            case 5:
            {
                cout << "value a front is : " << x.head->data << "\n";
                break;
            }
            case 6:
            {
                cout << "value a rear is : " << x.tail->data << "\n";
                break;
            }
            }
            cout << "do you want to continue ? enter y|n \n";
            cin >> choice;
        } while (choice == 'y' || choice == 'Y');
    }
};
