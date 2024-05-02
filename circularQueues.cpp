#include <bits/stdc++.h>
template <typename t>
class queue
{
private:
    t *q;
    int n, front, rear;

public:
    queue()
    {
        std::cout << "what is size of queue.\n";
        std::cin >> n;
        q = new t[n];
        front = rear = -1;
    }
    bool isEmpty()
    {
        if ((front == -1) && (rear == -1))
            return true;
        else
            return false;
    }
    bool isFull()
    {
        if (front == (rear + 1) % n)
            return true;
        else
            return false;
    }
    void enqueue(t val)
    {
        if (!isFull())
        {
            if ((front == -1) && (rear == -1)) // inserting first element
            {
                front = rear = 0;
                q[rear] = val;
            }
            else
            {
                rear = (rear + 1) % n;
                q[rear] = val;
            }
        }
        else
            std::cout << "queue is full.\n";
    }
    t dequeue()
    {
        if (!isEmpty())
        {
            t el = q[front];
            if (front == rear)
                front = rear = -1;
            else
                front = (front + 1) % n;
            return el;
        }
        else
            std::cout << "queue is empty.\n";
    }
    void display()
    {
        if(!isEmpty())
        {
            int i = front;
            while (true)
            {
                std::cout << q[i] << " ";
                if (i == rear)
                    break;
                i = (i + 1) % n;
            }
        }
        else
            std::cout<<"list is empty.\n";
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
                if (!isEmpty())
                {
                    std::cout << "value that is dequeued : " << dequeue() << "\n";
                    break;
                }
                else
                {
                    std::cout << "queue is empty.\n";
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