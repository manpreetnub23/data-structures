#include <bits/stdc++.h>
template <typename t>
class node
{
public:
    t data;
    node<t> *next, *prev;
    template <typename x>
    friend class dll;
};
template <typename t>
class dll
{
public:
    node<t> *head, *tail;
    dll()
    {
        head = NULL;
        tail = NULL;
    }
    ~dll(){};
    bool isEmpty()
    {
        if ((head == NULL) && (tail == NULL))
            return true;
        else
            return false;
    }
    void display()
    {
        std::cout << " your list is : ";
        if (!isEmpty())
        {
            node<t> *temp = head;
            while (temp != NULL)
            {
                std::cout << temp->data << " ";
                temp = temp->next;
            }
            std::cout << std::endl;
        }
        else
            std::cout << "empty." << std::endl;
    }
    void addToTail(t value)
    {
        node<t> *temp = new node<t>();
        temp->data = value;
        temp->next = NULL;
        temp->prev = NULL;
        if (isEmpty())
            head = tail = temp;
        else
        {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
    }
    t deleteFromHead()
    {
        if (isEmpty())
            std::cout << "list is empty.\n";
        else
        {
            node<t> *temp = head;
            t delval = temp->data;
            if (head == tail)
            {
                head = tail = NULL;
                delete temp;
                return delval;
            }
            else
            {
                head = head->next;
                head->prev = NULL;
                delete temp;
                return delval;
            }
        }
    }
    t deleteFromTail()
    {
        if (isEmpty())
            std::cout << "list is empty." << std::endl;
        else
        {
            if (head == tail)
                head = tail = NULL;
            else
            {
                node<t> *temp = tail;
                tail = tail->prev;
                tail->next = NULL;
                delete temp;
            }
        }
    }
    t deleteFromI(int index)
    {
        if (!isEmpty())
        {
            node<t> *temp = head;
            if (index == 1)
                deleteFromHead();
            else
            {
                int c = 1;
                while (c != index && temp->next != NULL)
                {
                    temp = temp->next;
                    c++;
                }
                if (c == index)
                {
                    if (temp == tail)
                        deleteFromTail();
                    else
                    {
                        t deletedData = temp->data;
                        temp->prev->next = temp->next;
                        temp->next->prev = temp->prev;
                        temp->prev = NULL;
                        temp->next = NULL;
                        delete temp;
                        return deletedData;
                    }
                }
                else
                    std::cout << "invalid input.\n";
            }
        }
        else
            std::cout << "list is empty \n";
    }
    void insertAtI(int index, t value)
    {
        node<t> *temp = new node<t>();
        temp->next = NULL;
        temp->prev = NULL;
        temp->data = value;
        if ((isEmpty()) && (index > 1))
            std::cout << "invalid index." << std::endl;
        else if ((isEmpty()) && (index == 1))
            addToTail(value);
        else
        {
            int c = 1;
            node<t> *extra = tail;
            while ((c != index - 1) && (extra->prev != NULL))
            {
                extra = extra->prev;
                c++;
            }
            if (c == index - 1)
            {
                if (extra->prev == NULL)
                {
                    extra->prev = temp;
                    temp->next = extra;
                    head = temp;
                }
                else
                {
                    temp->prev = extra->prev;
                    extra->prev->next = temp;
                    extra->prev = temp;
                    temp->next = extra;
                }
            }
        }
    }
    t deleteMiddle()
    {
        node<t> *slow=head;
        node<t> *fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        if(slow->prev==NULL)
        {
            head=head->next;
            if(head!=NULL)
            {
                head->prev==NULL;
            }
                delete slow;
        }
        slow->prev->next=slow->next;    
        slow->next->prev=slow->prev;
        t slowdata=slow->data;
        delete slow;
        return slowdata;
    }
    void menu()
    {
        int index,ask;
        char c;
        t value;
        do
        {
            std::cout<<"1)insert at i from back.\n2)delete from middle.\n3)display."<<std::endl;
            std::cin>>ask;
            switch(ask)
            {
                case 1:
                {
                    std::cout<<" index and value you want to insert."<<std::endl;
                    std::cin>>value>>index;
                    insertAtI(index,value);
                    break;
                }
                case 2:
                {
                    std::cout<<"value that is deleted : "<<deleteMiddle()<<std::endl;
                    break;
                }
                case 3:
                {
                    display();
                    break;
                }
                std::cout<<"do you want to continue ? y|n"<<std::endl;
                std::cin>>c;
            }
        } while (c == 'y' || c == 'Y');
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
        dll<int> obj;
        obj.menu();
        break;
    }
    case 2:
    {
        dll<float> obj;
        obj.menu();
        break;
    }
    case 3:
    {
        dll<char> obj;
        obj.menu();
        break;
    }
    }
}
