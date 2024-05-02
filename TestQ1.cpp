#include"sll.h"
int main()
{
    sll<int> x;
    x.insertAtHead(5);
    x.insertAtHead(4);
    x.insertAtHead(3);
    x.insertAtHead(2);
    x.insertAtHead(1);
    if(x.head==nullptr || x.head->next==nullptr)
        cout<<"head is : "<<x.head<<"\n";
    node<int> *current=x.head;
    node<int> *next_to_current=x.head->next;
    x.head->next=nullptr;
    while(next_to_current!=nullptr)
    {
        cout<<"hello harshita."<<endl;
        node<int> *temp=next_to_current->next;
        // cout<<"temp is pointing on : "<<temp->data<<"right now.(1)\n";
        next_to_current->next=current;
        cout<<"next_to_current's next is : "<<next_to_current->next->data<<"(2)\n";
        current=next_to_current;
        cout<<"current is now at : "<<current->data<<"right now.(3)\n";
        next_to_current=temp;
        // cout<<"next_to_current is now : "<<next_to_current->data<<"(4)\n";
    }
    cout<<"current's data at last is : "<<current->data<<endl;
}
