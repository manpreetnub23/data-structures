#include<iostream>
using namespace std;
template<class X>
class Node
{
	X data;
	Node<X> *next;
	Node<X> *prev;
	template<class T>friend class DLL;	
};
template<class X>
class DLL
{
	Node<X> *head;
	Node<X> *tail;
	public:
		DLL()
		{
			head=NULL;
			tail=NULL;
		}
	~DLL();
	bool isempty()
	{
		if(head==NULL && tail==NULL)
		return true;
		else
		return false;
	}
	void insertAthead(X n);
	void insertAtend(X n);
	void insertAti(X val,int i);
	X deletefromhead();
	X deletefromi(int i);
	X deletefromend();
	Node<X>* search(X val);
	void display();
	void concatenate(DLL B);
	void menu();
	
	
	//X middle();
	
		
};
template<class X>
void DLL<X>::insertAthead(X n)
{
	Node<X> *naya=new Node<X>();
	naya->next=NULL;
	naya->prev=NULL;
	naya->data=n;
	if(!isempty())
	{
		naya->next=head;
		head->prev=naya;
		head=naya;
	}
	else
	{
		head=naya;
		tail=naya;
	}
	
}
template<class X>
void DLL<X>::insertAtend(X n)
{
	Node<X> *naya=new Node<X>();
	naya->next=NULL;
	naya->prev=NULL;
	naya->data=n;
	if(isempty())
	{
		head=naya;
		tail=naya;
	}
	else
	{
		naya->prev=tail;
		tail->next=naya;
		tail=naya;	
	}
}
template<class X>
void DLL<X>::insertAti(X val,int i)
{
	Node<X> *naya=new Node<X>();
	naya->next=NULL;
	naya->prev=NULL;
	naya->data=val;
	if(i==1)
	insertAthead(val);
	else
	{
		int c=1;
		Node<X> *temp=head;
		while(c!=i-1&&temp->next!=NULL)
		{
			temp=temp->next;
			c++;
		}
		if(c==i-1 )
		{
			if(temp->next==NULL)
			{
			temp->next=naya;
			naya->prev=temp;
			tail=naya;
			}
			else 
			{
				temp->next->prev=naya;
				naya->next=temp->next;
				temp->next=naya;
				naya->prev=temp;
			}
		}
		else
		{
			cout<<"Not Valid Index\n";
		}
	}
}
template<class X>
X DLL<X>::deletefromi(int i)
{
	X dat;

	if(isempty())
	{
		cout<<"Your List is empty\n";
		return dat;
		
	}
	else{
		if(i==1)
		{
			deletefromhead();
			//return dat ;
		}
		else{	
			int c=1;
			Node<X> *temp=head;
			while(c!=i&&temp!=NULL)
			{
				temp=temp->next;c++;
			}
			if(temp!=NULL)	{
			if(c==i && temp->next==NULL){
				deletefromend();
			}
			else if(temp!=NULL)
			{	
				temp->prev->next=temp->next;
				temp->next->prev=temp->prev;
				temp->next=NULL;
				temp->prev=NULL;
				dat=temp->data;
				delete temp;
				return dat;
			}}
			else
				cout<<"Not Valid Index\n";
		}
	}
}
template<class X>
X DLL<X>::deletefromhead()
{
	if(isempty())
	{
		cout<<"List is EMPTY\n";
	}
	else
{
	X dat;
	Node<X> *temp=head;
	if(head==tail)
	{
		dat=temp->data;
		head=tail=NULL;
		
	}
	else
	{	
	head=head->next;
	head->prev=NULL;
	temp->next=NULL;
	dat=temp->data;
	}
	delete temp;
	return dat;
}
}
template<class X>
X DLL<X>::deletefromend()
{
	if(isempty())
	{
		cout<<"List is EMPTY\n";
	}
	else
	{
		Node<X> *temp=tail; 
		if(head==tail)
		{
			head=tail=NULL;
		}
		else{
		
		tail=tail->prev;
		tail->next=NULL;
		temp->prev=NULL;
		}
		X x=temp->data;
		delete temp;
		return x;
		
	}
}
template<class X>
Node<X>* DLL<X>::search(X val)
{
	if(isempty())
	{
	cout<<"LIST is empty";
	return NULL;
	}
	else
	{
		Node<X> *curr=head;
		while(curr!=NULL)
		{
			if(curr->data==val)
			{
				return curr;
			}
			curr=curr->next;
		}
	}
	
}
template<class X>
void DLL<X>::concatenate(DLL b)
{
	if(!isempty()&&(!b.isempty()))
	{
		Node <X>*curr=tail;
		curr->next=b.head;
		b.head=NULL;
		tail=b.tail;
		b.tail=NULL;
	}
	if(isempty())
	{
		head=b.head;
		b.head=NULL;
		tail=b.tail;
		b.tail=NULL;
	}
}
template<class X>
void DLL<X>::display()
{
	cout<<"YOUR LIST IS\n";
	if(isempty())
	cout<<"List is empty\n";
	else
	{
		Node<X> *temp=head;
		while(temp!=NULL)
		{
			cout<<temp->data<<" ";
			temp=temp->next;
		}
		cout<<endl;
	}
}
template<class X>
DLL<X>::~DLL()
{
cout<<"Destructor called"<<endl;
	while(!isempty())
	{
		deletefromend();
	}
}

template<class X>
void DLL<X>:: menu()
{
	//DLL<char> obj;
	
	int choice,index;
	char ask;
	X value;
	do
	{
		cout<<"MENU**"<<endl;
		cout<<"1:INSERT AT HEAD\n2:INSERT AT i POSITION\n3:INSERT AT END\n4:DELETE FROM HEAD\n5:DELETE FROM TAIL\n6:DELETE FROM i POSITION\n7:CONCATENATE\n8:SEARCH\n9:DISPLAY\nEnter choice";
		cin>>choice;
		switch(choice)
		{
			case 1:
			{
			cout<<"Enter value";cin>>value;insertAthead(value);break;}

			case 2:
				cout<<"Enter value,index";cin>>value>>index;insertAti(value,index);break;
			case 3:
				cout<<"Enter value";cin>>value;insertAtend(value);break;
			case 4:
				cout<<"Value deleted : "<<deletefromhead()<<endl;break;
			case 5:
				cout<<"Value deleted "<<deletefromend()<<endl;break;
			case 7:
				{
				cout<<"***Second list*****\n";
				DLL<X> l2;
				l2.menu();
				concatenate(l2);
				cout<<"After Concatenation"<<endl;
				display();
				break;
				
				}
			
			case 6:
				cout<<"Enter index";cin>>index;deletefromi(index);break;
			case 8:
				cout<<"Enter value to search";cin>>value;cout<<"Pointer "<<search(value)<<endl;break;
				
			case 9:
				display();break;
			default:
				cout<<"Not Valid Choice\n";
		}
		cout<<"continue";
		cin>>ask;
	}while(ask=='y');
}



int main()
{
		int choice;
	cout<<"1:Character array";
	cout<<"2:Integer array";
	cout<<"3:Float array";
	cin>>choice;
	switch(choice)
	{
		case 1:
		{
			DLL<char> obj;
			obj.menu();break;
		}
		case 2:
		{
			DLL<int> obj;
			obj.menu();break;
		}
		case 3:
		{
			DLL<float> obj;
			obj.menu();break;
		}
			
	}
}/*#include<iostream>
using namespace std;
template<class X>
class Node
{
	X data;
	Node<X> *next;
	Node<X> *prev;
	template<class T>friend class DLL;	
};
template<class X>
class DLL
{
	Node<X> *head;
	Node<X> *tail;
	public:
		DLL()
		{
			head=NULL;
			tail=NULL;
		}
	//~DLL();
	bool isempty()
	{
		if(head==NULL && tail==NULL)
		return true;
		else
		return false;
	}
	void insertAthead(X n);
	void insertAtend(X n);
	void insertAti(X val,int i);
	X deletefromhead();
	X deletefromi(int i);
	X deletefromend();
	Node<X>* search(X val);
	void display();
	void concatenate(DLL B);
	void menu();	
};
template<class X>
void DLL<X>::insertAthead(X n)
{
	Node<X> *naya=new Node<X>();
	naya->next=NULL;
	naya->prev=NULL;
	naya->data=n;
	if(!isempty())
	{
		naya->next=head;
		head->prev=naya;
		head=naya;
	}
	else
	{
		head=naya;
		tail=naya;
	}
	
}
template<class X>
void DLL<X>::insertAtend(X n)
{
	Node<X> *naya=new Node<X>();
	naya->next=NULL;
	naya->prev=NULL;
	naya->data=n;
	if(isempty())
	{
		head=naya;
		tail=naya;
	}
	else
	{
		naya->prev=tail;
		tail->next=naya;
		tail=naya;	
	}
}
template<class X>
void DLL<X>::insertAti(X val,int i)
{
	Node<X> *naya=new Node<X>();
	naya->next=NULL;
	naya->prev=NULL;
	naya->data=val;
	if(i==1)
	insertAthead(val);
	else
	{
		int c=1;
		Node<X> *temp=head;
		while(c!=i-1&&temp->next!=NULL)
		{
			temp=temp->next;
			c++;
		}
		if(c==i-1 )
		{
			if(temp->next==NULL)
			{
			temp->next=naya;
			naya->prev=temp;
			tail=naya;
			}
			else 
			{
				temp->next->prev=naya;
				naya->next=temp->next;
				temp->next=naya;
				naya->prev=temp;
			}
		}
		else
		{
			cout<<"Not Valid Index\n";
		}
	}
}
template<class X>
X DLL<X>::deletefromi(int i)
{

	if(isempty())
	{
		cout<<"Your List is empty\n";
	}
//	else
//	{
		if(i==1)
		{
			deletefromhead();
			//return val ;
		}
		int c=1;
		Node<X> *temp=head;
		while(c!=i&temp!=NULL)
		{
			temp=temp->next;c++;
		}
		if(temp!=NULL)
		{	
		temp->prev->next=temp->next;
		if(temp->next!=NULL)
		temp->next->prev=temp->prev->next;
		{
			temp->next=NULL;
			temp->prev=NULL;
		}
		X dat=temp->data;
		delete temp;
		return dat;
		}
		}
		//else
		//	cout<<"Not Valid Index\n";
	

//}
template<class X>
X DLL<X>::deletefromhead()
{
	if(isempty())
	{
		cout<<"List is EMPTY\n";
	}
	else
{
	X dat;
	Node<X> *temp=head;
	if(head==tail)
	{
		dat=temp->data;
		head=tail=NULL;
		
	}
	else
	{	
	head=head->next;
	head->prev=NULL;
	temp->next=NULL;
	dat=temp->data;
	}
	delete temp;
	return dat;
}
}
template<class X>
X DLL<X>::deletefromend()
{
	if(isempty())
	{
		cout<<"List is EMPTY\n";
	}
	else
	{
		Node<X> *temp=tail; 
		if(head==tail)
		{
			head=tail=NULL;
		}
		else{
		
		tail=tail->prev;
		tail->next=NULL;
		temp->prev=NULL;
		}
		X x=temp->data;
		delete temp;
		return x;
		
	}
}
template<class X>
Node<X>* DLL<X>::search(X val)
{
	if(isempty())
	{
	cout<<"LIST is empty";
	return NULL;
	}
	else
	{
		Node<X> *curr=head;
		while(curr!=NULL)
		{
			if(curr->data==val)
			{
				return curr;
			}
			curr=curr->next;
		}
	}
	
}
template<class X>
void DLL<X>::concatenate(DLL b)
{
	if(!isempty()&&(!b.isempty()))
	{
		Node <X>*curr=tail;
		curr->next=b.head;
		b.head=NULL;
		tail=b.tail;
		b.tail=NULL;
	}
	if(isempty())
	{
		head=b.head;
		b.head=NULL;
		tail=b.tail;
		b.tail=NULL;
	}
}
template<class X>
void DLL<X>::display()
{
	cout<<"YOUR LIST IS\n";
	if(isempty())
	cout<<"List is empty\n";
	else
	{
		Node<X> *temp=head;
		while(temp!=NULL)
		{
			cout<<temp->data<<" ";
			temp=temp->next;
		}
		cout<<endl;
	}
}
template<class X>
void DLL<X>:: menu()
{
	//DLL<char> obj;
	
	int choice,index;
	char ask;
	X value;
	do
	{
		cout<<"MENU**"<<endl;
		cout<<"1:INSERT AT HEAD\n2:INSERT AT i POSITION\n3:INSERT AT END\n4:DELETE FROM HEAD\n5:DELETE FROM TAIL\n6:DELETE FROM i POSITION\n7:CONCATENATE\n8:SEARCH\n9:DISPLAY\nEnter choice";
		cin>>choice;
		switch(choice)
		{
			case 1:
			{
			cout<<"Enter value";cin>>value;insertAthead(value);break;}

			case 2:
				cout<<"Enter value,index";cin>>value>>index;insertAti(value,index);break;
			case 3:
				cout<<"Enter value";cin>>value;insertAtend(value);break;
			case 4:
				cout<<"Value deleted : "<<deletefromhead()<<endl;break;
			case 5:
				cout<<"Value deleted "<<deletefromend()<<endl;break;
			case 7:
				{
				cout<<"***Second list*****\n";
				DLL<X> l2;
				l2.menu();
				concatenate(l2);
				cout<<"After Concatenation"<<endl;
				display();
				break;
				
				}
			
			case 6:
				cout<<"Enter index";cin>>index;deletefromi(index);break;
			case 8:
				cout<<"Enter value to search";cin>>value;cout<<"Pointer "<<search(value)<<endl;break;
				
			case 9:
				display();break;
			default:
				cout<<"Not Valid Choice\n";
		}
		cout<<"continue";
		cin>>ask;
	}while(ask=='y');
}

int main()
{
		int choice;
	cout<<"1:Character array";
	cout<<"2:Integer array";
	cout<<"3:Float array";
	cin>>choice;
	switch(choice)
	{
		case 1:
		{
			DLL<char> obj;
			obj.menu();break;
		}
		case 2:
		{
			DLL<int> obj;
			obj.menu();break;
		}
		case 3:
		{
			DLL<float> obj;
			obj.menu();break;
		}
			
	}
}*/
