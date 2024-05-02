#include "binaryTree.h"
template <typename t>
class heap
{
public:
    binaryTree<t> h;
    void insert(t value)
    {
        h.insert(value);
    }
    void buildHeap()
    {
        // h.insert(value);
        // minheapify(h.index - 1);
        for (int j = h.getparent(h.tree[h.index - 1]); j > 0; j--)
            minheapify(j);
    }
    void minheapify(int i)
    {
        int smallest = i;
        int left = (2 * i);
        int right = (2 * i + 1);
        if (left < h.index && h.tree[left] < h.tree[smallest])
            smallest = left;
        if (right < h.index && h.tree[right] < h.tree[smallest])
            smallest = right;
        if (smallest != i)
        {
            t temp = h.tree[i];
            h.tree[i] = h.tree[smallest];
            h.tree[smallest] = temp;
            minheapify(smallest);
        }
    }
    void deleteMin()
    {
        std::cout << "element deleted : " << h.tree[1] << std::endl;
        h.tree[1] = h.tree[h.index - 1];
        h.index--;
        minheapify(1);
    }
    void menu()
    {
        t value;
        int ask;
        char choice;
        do
        {
            std::cout << "1)for insertion.\n2)for building heap.\n3)delete min.\n4)display.\n";
            std::cin >> ask;
            switch (ask)
            {
            case 1:
            {
                std::cout << "enter the value." << std::endl;
                std::cin >> value;
                // buildHeap(value);
                insert(value);
                break;
            }
            case 2:
            {
                buildHeap();
                break;
            }
            case 3:
            {
                deleteMin();
                break;
            }
            case 4:
            {
                h.display();
                break;
            }
            }
            std::cout << "want to continue ? y|n" << std::endl;
            std::cin >> choice;
        } while (choice == 'y' || choice == 'Y');
    }
};