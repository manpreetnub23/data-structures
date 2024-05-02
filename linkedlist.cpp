#include<iostream>
using namespace std;
template <class t>
class node
{
    public:
        t data;
        node<t> *next;
        template <class x>friend class sll;
};
template <class t>
class sll
{
    node<t> *head,*tail;
    public:
        sll();
        bool isEmpty();
        void display();
        void insertAtHead(t);
        void insertAtTail(t);
};
template <class t>
sll<t>::sll()
{
    head=NULL;
}
template <class t>
bool sll<t>::isEmpty()
{
    if(head==NULL)
    return true;
    else
    return false;
}
template <class t>
void sll<t>::display()
{
    node<t> *temp;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
template <class t>
void sll<t>::insertAtHead(t n)
{
    if(isEmpty())
    cout<<"list is empty.\n";\
    else{
        node<t> *temp=new node<t>();
        temp->data=n;
        head=temp;
        temp->next=head;
        head=temp;
    }
}
template <class t>
void sll<t>::insertAtTail(t n)
{
    node<t> *temp=new node<t>();
    temp->data=n;
    temp->next=NULL;
    if(isEmpty())
    head=temp;
    //else{
        temp=head;
        while(temp!=NULL)
        {
            temp=temp->next;
        }
        temp->data=n;
    //}
}
int main()
{
    sll<int> datax;
    datax.insertAtHead(5);
    datax.insertAtHead(3);
    datax.insertAtHead(9);
    // datax.insertAtTail(4);
    datax.display();
    return 0;
}