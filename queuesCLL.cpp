#include "circularll.h"
template <typename t>
class QCLL
{
public:
    cll<t> obj;
    void enqueue(t val)
    {
        obj.addAtFront(val);
    }
    t dequeue()
    {
        if (!obj.isEmpty())
        {
            t del = obj.deleteAfter();
            return del;
        }
        else
            std::cout << "Q is empty\n"
                      << std::endl;
    }
    void display()
    {
        obj.display();
    }
    void menu()
    {
        t value;
        int ask;
        char choice;
        do
        {
            std::cout << "1)Enqueue.\n2)Dequeue.\n3)display.\n";
            std::cin >> ask;
            switch (ask)
            {
            case 1:
            {
                std::cout << "enter the value.\n";
                std::cin >> value;
                enqueue(value);
                break;
            }
            case 2:
            {
                if (!obj.isEmpty())
                {
                    std::cout << "value that is dequeued : " << dequeue() << "\n";
                    break;
                }
                else
                {
                    dequeue();
                    break;
                }
            }
            case 3:
            {
                display();
                break;
            }
            }
            std::cout << "do you want to continue ? enter y|n \n";
            std::cin >> choice;
        } while (choice == 'y' || choice == 'Y');
    }
};
int main()
{
    int datatype;
    std::cout << "enter the data type.\n1)int.\n2)float.\n3)char.\n";
    std::cin >> datatype;
    switch (datatype)
    {
    case 1:
    {
        QCLL<int> z;
        z.menu();
        break;
    }
    case 2:
    {
        QCLL<float> z;
        z.menu();
        break;
    }
    case 3:
    {
        QCLL<char> z;
        z.menu();
        break;
    }
    }
}
