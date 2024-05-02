#include "heap.h"
template <typename t>
class priorityQueue
{
public:
    heap<t> p;
    void enqueue(t value)
    {
        p.insert(value);
        p.buildHeap();
    }
    void dequeue()
    {
        p.deleteMin();
    }
    void peek()
    {
        std::cout << "element with highest priority is : " << p.h.tree[1] << std::endl;
    }
    void display()
    {
        p.h.display();
    }
    void menu()
    {
        t value;
        int ask;
        char choice;
        do
        {
            std::cout << "1)Enqueue.\n2)Dequeue.\n3)peek.\n4)display.\n";
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
                dequeue();
                break;
            }
            case 3:
            {
                peek();
                break;
            }
            case 4:
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
        priorityQueue<int> obj;
        obj.menu();
        break;
    }
    case 2:
    {
        priorityQueue<float> obj;
        obj.menu();
        break;
    }
    case 3:
    {
        priorityQueue<char> obj;
        obj.menu();
        break;
    }
    }
}