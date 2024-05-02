#include "double_ended_queue.h"
using namespace std;
template <typename t>
class treeNode
{

public:
    t data;
    treeNode(t);
    template <class x>
    friend class bst;
    treeNode<t> *left, *right;
};

template <typename t>
treeNode<t>::treeNode(t val)
{
    this->data = val;
    this->left = NULL;
    this->right = NULL;
}
template <typename t>
class bst
{
public:
    bst();
    t bfs();
    void menu();
    bool isEmpty();
    void deletion(t);
    treeNode<t> *root;
    t leaf_count(treeNode<t> *r);
    void insertNode(t);
    treeNode<t> *search(t);
    void searchAndChange(t, t);
    t height(treeNode<t> *r);
    treeNode<t> *findParent(treeNode<t> *r);
    void inorder(treeNode<t> *r);
    void preorder(treeNode<t> *r);
    void postorder(treeNode<t> *r);
    treeNode<t> *predecessor(treeNode<t> *r);
};
template <typename t>
bst<t>::bst()
{
    root = NULL;
}
template <typename t>
bool bst<t>::isEmpty()
{
    if (root == NULL)
        return true;
    else
        return false;
}
template <typename t>
void bst<t>::insertNode(t val)
{
    treeNode<t> *temp = new treeNode<t>(val);

    treeNode<t> *traverse = root;

    treeNode<t> *prev = NULL;

    if (!isEmpty())
    {
        while (traverse != NULL)
        {
            prev = traverse; // traverse=18 , prev=18
            if (val < traverse->data)
            {                              // 10 -->left
                traverse = traverse->left; // trev=null
            }
            else
            {
                traverse = traverse->right;
            }
        }
        if (val < prev->data)
            prev->left = temp;
        else
            prev->right = temp;
    }
    else
    {
        root = temp; // root 18
    }
}
template <typename t>
void bst<t>::preorder(treeNode<t> *r)
{
    if (r == NULL)
    {
    }
    else
    {
        cout << r->data << " ";
        preorder(r->left);
        preorder(r->right);
    }
}
template <typename t>
void bst<t>::inorder(treeNode<t> *r)
{
    //     cout<<"in inorder"<<endl;
    //     cout<<"r data is : "<<r->data<<endl;
    if (r == NULL)
    {
        // cout<<"r is null"<<endl;
    }
    else
    {
        inorder(r->left);
        cout << r->data << " ";
        inorder(r->right);
    }
}
template <typename t>
void bst<t>::postorder(treeNode<t> *r)
{
    if (r == NULL)
    {
    }
    else
    {
        postorder(r->left);
        postorder(r->right);
        cout << r->data << " ";
    }
}
template <typename t>
t bst<t>::bfs()
{
    queue<treeNode<t> *> obj;
    treeNode<t> *temp = root;
    if (!isEmpty())
    {
        obj.enqueueAtFront(temp);
        cout << "root pushed" << endl;
        while (!obj.isEmptyy())
        {
            temp = obj.dequeueFromFront();
            cout << temp->data << " ";
            if (temp->left != NULL)
            {
                obj.enqueueAtRear(temp->left);
            }
            if (temp->right != NULL)
            {
                obj.enqueueAtRear(temp->right);
            }
        }
    }
}
template <typename t>
t bst<t>::leaf_count(treeNode<t> *temp)
{
    if (temp == NULL)
        return 0;
    else if (temp->left==NULL && temp->right==NULL)
        return 1;
    else
        return leaf_count(temp->left)+leaf_count(temp->right);
}
template <typename t>
treeNode<t> *bst<t>::predecessor(treeNode<t> *predNode)
{
    if (!isEmpty())
    {
        treeNode<t> *tempo = predNode;
        tempo = tempo->left;
        while (tempo->right != NULL) // 5 ka right andar gaya//andr gaya
        {
            tempo = tempo->right; // 6///7
        }
        if (tempo->right == NULL)
            return tempo;
    }
    else
    {
        cout << "tree is empty." << endl;
        return NULL;
    }
}
template <typename t>
void bst<t>::searchAndChange(t find, t newVal)
{
    if (!isEmpty())
    {
        deletion(find);
        insertNode(newVal);
        // bfs();
    }
    else
        cout << "tree is Empty." << endl;
}
template <typename t>
treeNode<t> *bst<t>::search(t value)
{
    // treeNode<t> *prev = NULL;
    if (!isEmpty())
    {
        treeNode<t> *temp = root;
        while (temp != NULL)
        {
            // prev=temp;
            if (temp->data == value)
            {
                cout << "node to be returned data is : " << temp->data << endl;
                return temp;
            }
            else if (value > temp->data)
            {
                // prev = temp;
                temp = temp->right;
                // cout << "temp in right.data is : " << temp->data << endl;
            }
            else
            {
                // prev = temp;
                temp = temp->left;
                // cout << "temp in left.data is : " << temp->data << endl;
            }
        }
        if (temp == NULL)
        {
            cout << "value nott found" << endl;
            return NULL;
        }
    }
    else
    {
        cout << "tree is empty." << endl;
        return NULL;
    }
}
template <typename t>
treeNode<t> *bst<t>::findParent(treeNode<t> *delNode)
{
    if (delNode != NULL)
    {
        if (delNode == root)
            return NULL;
        queue<treeNode<t> *> obj;
        treeNode<t> *temp = root;
        if (!isEmpty())
        {
            obj.enqueueAtFront(temp);
            // cout << "root pushed" << endl;
            while (!obj.isEmptyy() && temp->right != delNode && temp->left != delNode)
            {
                temp = obj.dequeueFromFront();
                cout << temp->data << " ";
                if (temp->left != NULL)
                {
                    obj.enqueueAtRear(temp->left);
                }
                if (temp->right != NULL)
                {
                    obj.enqueueAtRear(temp->right);
                }
            }
            return temp;
        }
    }
    else
        return NULL;
}
template <typename t>
t bst<t>::height(treeNode<t> *temp)
{
    if (temp == NULL)
        return 0;
    else
    {
        t lHeight = height(temp->left);
        t rHeight = height(temp->right);
        if (lHeight > rHeight)
            return (lHeight + 1);
        else
            return (rHeight + 1);
    }
}
template <typename t>
void bst<t>::deletion(t val)
{
    if (!isEmpty())
    {
        cout << "inside deletion" << endl;
        treeNode<t> *delNode = search(val);
        treeNode<t> *parentNode = findParent(delNode);
        // cout << "parent is : " << parentNode->data << endl;
        if (delNode->right == NULL && delNode->left == NULL) // zero child case.
        {
            cout << "in zero child case." << endl;
            if (val == root->data)
            {
                cout << "inside if ja del node root hai toh root kodelete kar diya " << endl;
                if (delNode->left == NULL && delNode->right == NULL) // 0 child
                {
                    // cout<<"now tree is empty.\n";
                    delete delNode;
                    root = NULL;
                    cout << "tree is empty." << endl;
                }
            }
            else if (parentNode->left != NULL)
            {
                cout << "inside else if " << endl;
                if (val == parentNode->left->data)
                {
                    parentNode->left = NULL;
                    delete delNode;
                }
            }
            else
            {
                cout << "ab ye else mein aaya hai 0 child ke" << endl;
                parentNode->right = NULL;
                delete delNode;
            }
        }
        else if ((delNode->left != NULL && delNode->right == NULL) || (delNode->left == NULL && delNode->right != NULL)) // one child case
        {
            cout << "inside else if when there is only one child of the node to be deleted" << endl;
            if (delNode == root)
            {
                if (delNode->left == NULL)
                {
                    root = delNode->right;
                    delete delNode;
                }
                else
                {
                    root = delNode->left;
                    delete delNode;
                }
            }
            else if (val < root->data)
            {
                cout << "if node to be deleted is in left subtree." << endl;
                if (delNode->left == NULL)
                {
                    parentNode->left = delNode->right;
                    cout << "ab parent node ke right mein hai : " << parentNode->right << endl;
                    delete delNode;
                }
                else if (delNode->right == NULL)
                {
                    parentNode->left = delNode->left;
                    cout << "ab parent node ke left mein hai : " << parentNode->left << endl;
                    delete delNode;
                }
            }
            else
            {
                cout << "if a node to be deleted is in right sutree." << endl;
                if (delNode->left == NULL)
                {
                    parentNode->right = delNode->right;
                    cout << "ab parent node ke right mein hai : " << parentNode->right << endl;
                    delete delNode;
                }
                else if (delNode->right == NULL)
                {
                    parentNode->right = delNode->left;
                    cout << "ab parent node ke left mein hai : " << parentNode->left << endl;
                    delete delNode;
                }
            }
        }
        else if (delNode->left != NULL && delNode->right != NULL) // 2 children
        {
            cout << "in 2 child case " << endl;
            treeNode<t> *pre = predecessor(delNode); // 10
            treeNode<t> *prePar = findParent(pre);   // NULL
            cout << "when there are 2 children of the delNode  " << endl;
            delNode->data = pre->data; // DELNODE JO HAI 20 USMEIN 10 AA JAAYEGA
            // cout << "delnode ka data ab change ho gaya , aur ab delnode ka data hai : " << delNode->data << endl;
            // pre=NULL;
            // cout<<"delete hone se pehle pre ke left mein hai : "<<pre->left<<endl;
            // if(prePar==NULL)
            //     root->left=pre->left;
            // else
            if (prePar != NULL)
                prePar->right = pre->left;

            delete pre;
            // delNode->left==NULL;
            cout << "pre delete ho chuka hai." << endl;
        }
    }
    else
    {
        cout << "tree is empty." << endl;
    }
}
template <typename t>
void bst<t>::menu()
{
    t value, newValue;
    int ask;
    char c;
    do
    {
        cout << "what operation you want to perform ? \n";
        cout << "1)Insert a node.\n2)display using pre order.\n3)display using in order.\n4)display using post order.\n5)search.\n6)predecessor.\n7)deletion.\n9)bfs.\n10)height of tree.\n11)search and change the value.\n12)leaf count.\n";
        cin >> ask;
        switch (ask)
        {
        case 1:
        {
            cout << "enter the value you want to insert.\n";
            cin >> value;
            insertNode(value);
            break;
        }
        case 2:
        {
            if (isEmpty())
            {
                cout << "tree is Empty.\n";
                break;
            }
            else
            {
                preorder(root);
                break;
            }
        }
        case 3:
        {
            if (isEmpty())
            {
                cout << "tree is Empty.\n";
                break;
            }
            else
            {
                inorder(root);
                break;
            }
        }
        case 4:
        {
            if (isEmpty())
            {
                cout << "tree is Empty.\n";
                break;
            }
            else
            {
                postorder(root);
                break;
            }
        }
        case 5:
        {
            cout << "enter the value you want to search.\n";
            cin >> value;
            search(value);
            break;
        }
        case 6:
        {
            treeNode<t> *printPred = predecessor(root);
            cout << "predecessor node returned value is : " << printPred->data << endl;
            break;
        }
        case 7:
        {
            cout << "enter the value you want to delete.\n";
            cin >> value;
            deletion(value);
            break;
        }
        case 9:
        {
            bfs();
            break;
        }
        case 10:
        {
            cout << "height of the tree is : " << (height(root) - 1) << endl;
            break;
        }
        case 11:
        {
            cout << "enter the value you want to search.\n";
            cin >> value;
            cout << "enter the new value.\n";
            cin >> newValue;
            searchAndChange(value, newValue);
            break;
        }
        case 12:
        {
            std::cout<<"total leaves are : "<<leaf_count(root);
            break;
        }
        }
        cout << "do you want to continue? enter y|n\n";
        cin >> c;
    } while (c == 'y' || c == 'Y');
}
