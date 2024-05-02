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
    // private:
    public:
        node<t> *head;
        sll();
        ~sll();
        void menu();
        bool isEmpty();
        void display();
        void reverse();
        void insertAtHead(t);
        void insertAtTail(t);
        void insertAtMid(int,t);
        void concatenate(sll l2);
        node<t> *search(t);
        t deleteFromHead();
        t deleteFromTail();
        t deleteFromMid(int);
};
template <class t>
sll<t>::sll()
{
    head=NULL;
}
template <class t>
sll<t>::~sll()
{
    // while(!isEmpty())
    // deleteFromHead();
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
    cout<<"\nafter concatenation ";
    if(!isEmpty())
    {
        node<t> *temp=head;
        while(temp->next!=NULL)
        temp=temp->next;
        temp->next=l2.head;
        l2.head=NULL;
        cout<<"\n";
    }
    else
    {
        head=l2.head;
        l2.head=NULL;    
    }
    display();
}
template <class t>
node<t>* sll<t>::search(t value)
{
    if(isEmpty())
    cout<<"list is empty,unable to find element.\n";
    else
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
    }
    return NULL;
}
template <class t>
void sll<t>::reverse()
{
    node<t> *curr=head;
    node<t> *prev=NULL;
    node<t> *temp=NULL;
    while(curr!=NULL)
    {
        temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    head=prev;
}
template <class t>
void sll<t>::menu()
{
    char c;
    int ask,index;
    t value;
    do
    {
    	cout<<"what operation you want to perform : \n1)insert at head.\n2)insert at end.\n3)insert at mid.\n4)delete from head.\n5)delete from end.\n6)delete from mid.\n7)concatenation.\n8)search an element.\n9)reverse list.\n10)display the list.\n";
    	cin>>ask;
    	switch(ask)
    	{
    		case 1:
    		{
    			cout<<"enter value you want to insert.\n";
    			cin>>value;
    			insertAtHead(value);
    			break;
    		}
    		case 2:
    		{
    			cout<<"enter value you want to insert.\n";
    			cin>>value;
    			insertAtTail(value);
    			break;
    		}
    		case 3:
    		{
    			cout<<"enter value you want to insert.\n";
    			cin>>value;
    			cout<<"enter the index \n";
    			cin>>index;
    			insertAtMid(index,value);
    			break;
    		}
    		case 4:
    		{
    			deleteFromHead();
    			break;
    		}
    		case 5:
    		{
    			deleteFromTail();
    			break;
    		}
    		case 6:
    		{
    			cout<<"enter the index to delete.\n";
    			cin>>index;
    			deleteFromMid(index);
    			break;
    		}
    		case 7:
    		{
    			sll<t> l2;
    			l2.menu();
    			concatenate(l2);
                break;
    		}
    		case 8:
			{
				cout<<"enter the value you want to search.\n";
				cin>>value;
				cout<<search(value)<<endl;
				break;
			}
            case 9:
            {
                cout<<"reverse of ";
                reverse();
                display();
                break;
            }
			case 10:
			{
				display();
				break;
			}    		
    	}
    	cout<<"do you want to continue? enter y|n \n";
    	cin>>c;
    }while(c=='y' || c=='Y');
}
/*
void meenu()
{
	int datatype;
	cout<<"enter the data type.\n1)int.\n2)float.\n3)char.\n";
	cin>>datatype;
	switch(datatype)
	{
		case 1:
		{
			sll<int> obj;
			obj.menu();
			break;
		}
		case 2:
		{
			sll<float> obj;
			obj.menu();
			break;
		}
		case 3:
		{
			sll<char> obj;
			obj.menu();
			break;
		}
	}
}
int main()
{ 
   	meenu();
}
*/