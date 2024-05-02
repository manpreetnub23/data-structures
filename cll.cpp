#include<iostream>
using namespace std;
template <class t>
class node
{
    private:
        t data;
        node<t> *next;
        template <class x> friend class cll;
};
template <class t>
class cll
{
    private:
        node<t> *cursor;
        public:
            cll();
           // ~cll();
            bool isEmpty();
            void menu();
            void display();
            void addAtFront(t);
            void addAfter(int,t);
            void addBefore(t);
            t remove(t);
            t deleteBefore();
            t deleteAfter();
            node<t> *search(t);
};
template <class t>
cll<t>::cll()
{
    cursor=NULL;
}
template <class t>
bool cll<t>::isEmpty()
{
    if(cursor==NULL)
    return true;
    else
    return false;
}
template <class t>
void cll<t>::display()
{
    cout<<"your list is : ";
    if(!isEmpty())
    {
        node<t> *temp=cursor;
        cout<<temp->data<<" ";
        temp=temp->next;
        while(temp!= cursor)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        //cout<<temp->data<<" ";
    }
    else
    cout<<"empty\n";
}
template <class t>
void cll<t>::addAtFront(t val)
{
    node<t> *temp=new node<t>();
    temp->data=val;
    temp->next=NULL;
    if(isEmpty())
    {
        cursor=temp;
        cursor->next=cursor;
    }
    else
    {
    //if(temp
    temp->next=cursor->next;
    cursor->next=temp;
        //temp->next=cursor;
       // cursor->next=temp;
    }
}
template <class t>
void cll<t>::addAfter(int index,t val)
{
    node<t> *temp=new node<t>();
    temp->data=val;
    temp->next=NULL;
    node<t> *point=cursor;
    // int c=1;
    if(!isEmpty())
    {
        while(point->data!=val && point!=cursor)
            point=point->next;
        if(point!=cursor)
        {
            temp->next=point->next;
            point->next=temp;
        }
        else
        {
            temp->next=cursor;
            cursor->next=temp;
        }
        
    }
    else
        cout<<"list is empty.\n";
}
template <class t>
void cll<t>::addBefore(t val)
{
    node<t> *temp=new node<t>();
    temp->data=val;
    temp->next=NULL;
    if(!isEmpty())
    {
        node<t> *prev=cursor;
        while(prev->next!=cursor)
        prev=prev->next;
        prev->next=temp;
        temp->next=cursor;
    }
    else
    addAtFront(val);
}
template <class t>
t cll<t>::remove(t val)
{
    if(!isEmpty())
    {
        node<t> *curr=cursor;
        node<t> *prev=cursor;
        while(curr->data!=val && prev->next!=cursor)
        {
            prev=curr;
            curr=curr->next;
        }
        if(curr->data==val && curr!=cursor)
        {
            prev->next=curr->next;
            curr->next=NULL;
            t y=curr->data;
            delete curr;
            cout<<"value deleted.\n";
            return y;
        }
        else if(curr==cursor && prev==cursor && cursor->data==val)
        {
            if(curr->next==cursor)
            {
                cursor=NULL;
                delete curr;
            }
            else
            {   
                while(prev->next!=cursor)
                    prev=prev->next;
                prev->next=cursor->next;
                delete curr;
                cursor=prev;
                cout<<"deleted successfully \n";
            }
        }
        else
            cout<<"element not present \n";
    }
    else
        cout<<"list is empty.\n";
}
template <class t>
t cll<t>::deleteBefore()
{
    if(!isEmpty())
    {
        node<t> *temp=cursor;
        node<t> *del=NULL;
        // node<t> *p=cursor->next;
        if(cursor->next!=cursor)
        {
            while(temp->next->next!=cursor)
                temp=temp->next->next;
            del=temp->next;
            temp->next=cursor;
            temp->next=NULL;
            t data=del->data;
            delete del;
            return data;
        }
        else
        {
            t x=cursor->data;
            cursor=NULL;
            delete temp;
            return x;
        }
        // temp->next->next=NULL;
        // delete temp->next;
    }
    // else
    //     cout<<"list is empty.\n";
}
template <class t>
t cll<t>::deleteAfter()
{
    if(!isEmpty())
    {
        node<t> *temp=cursor;
        node<t> *point=cursor;
        if(cursor->next!=cursor)
        {
            while(temp->next!=cursor)
                temp=temp->next;
            temp->next=point->next;
            cursor=temp;
            point->next=NULL;
            t x=point->data;
            delete point;
            return x;
        }
        else
        {
            t x=cursor->data;
            cursor=NULL;
            delete temp;
            return x;
        }
    }
    // else
    //     cout<<"list is empty.\n";
}
template <class t>
node<t>* cll<t>::search(t value)
{
    if(isEmpty())
    cout<<"list is empty,unable to find element.\n";
    else
    {
        node<t> *temp=cursor;
        if(temp->data==value)
        return cursor;
        else{
            temp=temp->next;
            while(temp!=cursor)
            {
                if(temp->data==value)
                return temp;
                else
                temp=temp->next;
            }
            if(temp==cursor)
            {
                cout<<"\nelement not found \n";
            }
        }
    }
    return NULL;
}
// template <class t>
// void cll<t>::menu()
// {
//     cll<t> l2;
//     char c;
//     int ask,index;
//     t value;
//     do
//     {
//     	cout<<"what operation you want to perform : \n1)add at front.\n2)add before.\n3)add after.\n4)remove by value.\n5)delete before.\n6)delete after.\n7)concatenation.\n8)search an element.\n9)display the list.\n";
//     	cin>>ask;
//     	switch(ask)
//     	{
//     		case 1:
//     		{
//     			cout<<"enter value you want to insert.\n";
//     			cin>>value;
//     			addAtFront(value);
//     			break;
//     		}
//     		case 2:
//     		{
//     			cout<<"enter value you want to insert.\n";
//     			cin>>value;
//     			addBefore(value);
//     			break;
//     		}
//     		case 3:
//     		{
//     			cout<<"enter value you want to insert.\n";
//     			cin>>value;
//     			addAfter(value);
//     			break;
//     		}
//     		case 4:
//     		{
//     			remove();
//     			break;
//     		}
//     		case 5:
//     		{
//     			deleteBefore();
//     			break;
//     		}
//     		case 6:
//     		{
//     			deleteAfter();
//     			break;
//     		}
//     		case 7:
//     		{
//     			l2.menu();
//     			concatenate(l2);
//                 break;
//     		}
//     		case 8:
// 			{
// 				cout<<"enter the value you want to search.\n";
// 				cin>>value;
// 				cout<<search(value)<<endl;
// 				break;
//             }
// 			case 9:
// 			{
// 				display();
// 				break;
// 			}    		
//     	}
//     	cout<<"do you want to continue? enter y|n \n";
//     	cin>>c;
//     }while(c=='y' || c=='Y');
// }
int main()
{
    cll<int> obj;
    obj.addAtFront(7);
    obj.addAtFront(3);
    obj.addAtFront(8);
    obj.addAfter(3,5);
    // obj.addAfter(5);
    // obj.addBefore(6);
    // obj.remove(7);
    // obj.deleteBefore();
    // obj.deleteAfter();
    // obj.deleteAfter();
    obj.display();
    // cout<<endl<<obj.search(1)<<endl;
}