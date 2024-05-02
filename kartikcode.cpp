#include<iostream>

using namespace std;
template<typename t> class stack
{
	private:
		int top,size;
		t *arr;
	public:
		stack();
            int pop();
            void push(t el);
            bool isempty();
            int peektop();
            void display();
            bool isEmpty();
		    bool isfull();
	      
};

template<typename t> stack<t> ::stack(){
	top=-1;
	cout<<"enter the size of stack";
	cin>>size;
	arr=new t[size];
	
}
template<typename t>void stack<t>::push(t el){
	
	if(isfull())
	cout<<"stack overflow";
	else{
		top++;
		arr[top]=el;
	}
}
template<typename t>int stack<t> ::pop(){
	if(isEmpty())
    {
        cout<<"stack underflow";
        return -99;
    }
	else
    {
        t x=arr[top];
        top--;
        return x;
    }
}
template<typename t> bool stack<t>::isEmpty(){
    if (top==-1)
        return true;
    else 
        return false;
}
template<typename t> bool stack<t>::isfull(){
     	if(top==(size-1))
     	    return true;
     	else 
            return false;
  }
template<typename t>int stack<t> ::peektop(){
	if(!isEmpty())
	    return arr[top];
    else
        return -99;
     }
template<typename t>void stack<t> ::display(){
	if(!isEmpty());
	for(int i=top;i>=0;i--)
	cout<<arr[i];
}

int main(){
    stack<int> obj;
    obj.push(1);
    obj.push(2);
    obj.push(3);
    obj.push(4);
    // obj.pop();
    obj.isEmpty();
    cout<<"element at the top is : "<<obj.peektop()<<endl;
    obj.display();
    	return 0;
}