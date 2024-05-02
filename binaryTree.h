#include <bits/stdc++.h>
template <typename t>
class binaryTree
{
public:
    t *tree;
    int size, index = 1;

    binaryTree()
    {
        std::cout << "enter the size" << std::endl;
        std::cin >> size;
        tree = new t[size]{};
    }
    t getleft(t value)
    {
        int returned = search(value);
        int leftchild = (2 * returned);
        std::cout << "left child of " << value << " is  : " << tree[leftchild] << std::endl;
        return leftchild;
    }
    t getright(t value)
    {
        int returned = search(value);
        int rightchild = ((2 * returned) + 1);
        std::cout << "right child of " << value << " is  : " << tree[rightchild] << std::endl;
        return rightchild;
    }
    t getparent(t value)
    {
        int returned = search(value);
        int father = (floor(returned / 2));
        std::cout << "Parent of " << value << " is  : " << tree[father] << std::endl;
        return father;
    }
    void insert(t value)
    {
        if(index>size)
            std::cout<<"invalid input."<<std::endl;
        else
        tree[index] = value;
        index++;
    }
    t search(t value)
    {
        for (int i = 1; i <= size; i++)
        {
            if (tree[i] == value)
            {
                std::cout << "value found at " << i << " index." << std::endl;
                std::cout << "i is : " << i << std::endl;
                return i;
            }
        }
        return -99;
    }
    void display()
    {
        for (int i = 1; i < index; i++)
            std::cout << tree[i] << " ";
    }
    void menu()
    {
        t value;
        int ask;
        char choice;
        do
        {
            std::cout << "1)for insertion.\n2)for left child.\n3)for right child.\n4)for parent.\n5)display.\n";
            std::cin >> ask;
            switch (ask)
            {
            case 1:
            {
                std::cout << "enter the value." << std::endl;
                std::cin >> value;
                insert(value);
                break;
            }
            case 2:
            {
                std::cout << "enter the value." << std::endl;
                std::cin >> value;
                getleft(value);
                break;
            }
            case 3:
            {
                std::cout << "enter the value." << std::endl;
                std::cin >> value;
                getright(value);
                break;
            }
            case 4:
            {
                std::cout << "enter the value." << std::endl;
                std::cin >> value;
                getparent(value);
                break;
            }
            case 5:
            {
                display();
                break;
            }
            }
            std::cout << "want to continue ? y|n" << std::endl;
            std::cin >> choice;
        } while (choice == 'y' || choice == 'Y');
    }
};
