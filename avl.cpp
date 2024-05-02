#include "bst.h"
template <typename t>
class avl
{
public:
    bst<t> b;
    void insert(t value)
    {
        b.insertNode(value);
        treeNode<t> *p = b.search(value);
        while (p != NULL)
        {
            treeNode<t> *par = b.findParent(p);
            treeNode<t> *compare = rotation(p);
            if (par != NULL)
            {
                if (par->data > compare->data)
                    par->left = compare;
                else
                    par->right = compare;
            }
            else
                b.root = compare;
            p = b.findParent(p);
        }
    }
    t getBalance(treeNode<t> *temp)
    {
        if (temp == NULL)
            return 0;
        else
        {
            return ((b.height(temp->right) - b.height(temp->left)));
        }
    }
    void display()
    {
        b.bfs();
    }
    treeNode<t> *LLrotate(treeNode<t> *p) // left subtree ke left mein
    {
        treeNode<t> *q = p->left;
        p->left = q->right;
        q->right = p;
    }
    treeNode<t> *RLrotate(treeNode<t> *p) // right subtree ke left mein
    {
        treeNode<t> *q = p->right;
        p->right = LLrotate(q);
        return RRrotate(p);
    }
    treeNode<t> *LRrotate(treeNode<t> *p) // left subtree ke right mein
    {
        treeNode<t> *q = p->right;
        p->left = RRrotate(q);
        return LLrotate(p);
    }
    treeNode<t> *RRrotate(treeNode<t> *p) // right subtree ke right mein
    {
        treeNode<t> *q = p->right;
        p->right = q->left;
        q->left = p;
        return q;
    }
    treeNode<t> *rotation(treeNode<t> *p) // calculating balance factor and doing rotations.
    {
        int balance;
        std::cout << "p is now pointing at : " << p->data << std::endl;
        balance = getBalance(p);
        std::cout << "balance is : " << balance << endl;
        if (balance > 1)
        {
            if (getBalance(p->right) > 0)
            {
                p = RRrotate(p);
            }
            else
                p = RLrotate(p);
        }
        else if (balance < -1)
        {
            if (getBalance(p->left) < 0)
            {
                p = LLrotate(p);
            }
            else
                p = LRrotate(p);
        }
        return p;
    }
    void deletee(t value)
    {
        treeNode<t> *tempo = b.search(value);
        treeNode<t> *p = b.findParent(tempo);
        b.deletion(value);
        b.bfs();
        while (p != NULL)
        {
            treeNode<t> *par = b.findParent(p);
            treeNode<t> *compare = rotation(p);
            if (par != NULL)
            {
                if (par->data > compare->data)
                    par->left = compare;
                else
                    par->right = compare;
            }
            else
                b.root = compare;
            p = b.findParent(p);
        }
    }
    void menu()
    {
        t value;
        int ask;
        char choice;
        do
        {
            std::cout << "1)for insertion.\n2for deletion.\n3)display.\n";
            std::cin >> ask;
            switch (ask)
            {
            case 1:
            {
                std::cout<<"enter value you want to insert.\n";
                std::cin>>value;
                insert(value);
                break;
            }
            case 2:
            {
                std::cout<<"enter value you want to insert.\n";
                std::cin>>value;
                deletee(value);
                break;
            }
            case 3:
            {
                display();
                break;
            }
            }
            std::cout<<"do you want to continue ? y|n\n";
            std::cin>>choice;
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
        avl<int> obj;
        obj.menu();
        break;
    }
    case 2:
    {
        avl<float> obj;
        obj.menu();
        break;
    }
    case 3:
    {
        avl<char> obj;
        obj.menu();
        break;
    }
    }
}