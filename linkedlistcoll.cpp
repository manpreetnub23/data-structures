#include<iostream>
using namespace std;
template <class t>
class node
{
public:
    t data;
    node *next;
    template <class x> friend class sll;
};
template <class t>
class sll
{
    private:
        node<t> *head;
    public:
        sll();
        bool isEmpty();
        void display();
        void insertAtHead(t);
        void insertAtTail(t);
        void insertAtMid(int,t);
        void concatenate(sll l2);
        t deleteFromHead();
        t deleteFromTail();
        t deleteFromMid(int);
        node<t> *search(t);
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
template <class t >
void sll<t>::insertAtHead(t n)
{
    node<t> *neww = new node<t>();
    neww->data=n;
    neww->next=NULL;
    if(isEmpty())
    head=neww;
    else
    {
        neww->next=head;
        head=neww;
    }  
}
template <class t>
void sll<t>::insertAtTail(t n)
{
    node<t> *neww=new node<t>();
    neww->data=n;
    neww->next=NULL;
    if(isEmpty())
    head=neww;
    else
    {
        node<t> *temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=neww;    
    }
}
template <class t>
void sll<t>::insertAtMid(int i,t val)
{
    node<t> *neww=new node<t>();
    neww->data=val;
    neww->next=NULL;
    node<t> *temp=head;
    int c=1;
    if(i==1)
    insertAtHead(val);
    else{
        while(c!=i-1 && temp!=NULL)
        {
            c+=1;
            temp=temp->next;
        }
        if(c==i-1)
        {
        neww->next=temp->next;
        temp->next=neww;
        }
        else
        {
        cout<<"invalid position.\n";
        }
    }
}
template <class t>
void sll<t>::display()
{
    cout<<"your list is : \n";
    if(isEmpty())
    cout<<"list is empty. \n";
    else
    {
        node<t> *temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
}
template <class t>
t sll<t>::deleteFromHead()
{
    if(!isEmpty())
    {
    node<t> *temp=head;
    head=head->next;
    temp->next=NULL;
    t x=temp->data;
    delete temp;
    return x;
    }
    else
    {
    cout<<"list is empty.\n";
    }
}
template <class t>
t sll<t>::deleteFromTail()
{
    if(!isEmpty())
    {
        node<t> *prev=NULL;
        node<t> *curr=head;
        while(curr->next!=NULL)
        {
            prev=curr;
            curr=curr->next;
        }
        t x=curr->data;
        if(prev!=NULL)
        prev->next=NULL;
        else
        head=NULL;
        delete curr;
        return x;
        }
    else
    {
        cout<<"list is empty \n";
        return -1;
    }
}
template <class t>
t sll<t>::deleteFromMid(int index)
{
    if(isEmpty())
    cout<<"list is empty.\n";
    else{
        if(index==1)
        deleteFromHead();
        else{
            node<t> *prev=NULL;
            node<t> *curr=head;
            int c=1;
            while(c!=index && curr!=NULL)
            {
                prev=curr;
                curr=curr->next;
                c++;
            }
            if(c==index)
            {
                prev->next=curr->next;
                t x=curr->data;
                delete curr;
                return x;
            }
            else{
                cout<<"invalid input\n";
            }
        }
    }
}
template <class t>
void sll<t>::concatenate(sll<t> l2)
{
    cout<<"\nnew list after concatenation is : \n";
    if(isEmpty())
    {

    }
        node<t> *temp=head;
        while(temp->next!=NULL)
        temp=temp->next;
        temp->next=l2.head;
        l2.head=NULL;
        display();
        cout<<"\n";
}
template <class t>
node<t>* sll<t>::search(t value)
{
    node<t> *temp=head;
    if(temp->data==value)
    return head;
    else{
        temp=temp->next;
        while(temp!=NULL)
        {
            if(temp->data==value)
            return temp;
            else
            temp=temp->next;
        }
        if(temp==NULL)
        {
            cout<<"element not found \n";
        }
    }
    return NULL;
}
int main()
{
    sll<char> inselem;
    inselem.insertAtHead('5');
    inselem.insertAtHead('8');
    inselem.insertAtHead('9');
    inselem.insertAtTail('6');
    inselem.insertAtMid(4,'k');
    cout<<"value deleted from mid  : "<<inselem.deleteFromMid(3)<<"\n";
    cout<<"value deleted from head : "<<inselem.deleteFromHead()<<"\n";
    cout<<"value deleted from tail : "<<inselem.deleteFromTail()<<"\n";
    inselem.display();  
    //creating another list.
    sll<char> insdata;
    insdata.insertAtHead('1');
    insdata.insertAtHead('2');
    insdata.insertAtHead('3');
    insdata.insertAtTail('5');
    insdata.insertAtMid(2,'X');
    cout<<"\nvalue deleted from mid  : "<<insdata.deleteFromMid(4)<<"\n";
    cout<<"value deleted from head : "<<insdata.deleteFromHead()<<"\n";
    cout<<insdata.search('X')<<"\n";
    insdata.display();
    inselem.concatenate(insdata);
    return 0;
}