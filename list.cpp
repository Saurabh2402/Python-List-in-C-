#include<iostream>
using namespace std;

template <class T>
class Node
{
    T data;
    Node* next;

    public:
    Node()
    {
        next=NULL;
    }
    void setData(T val)
    {
        data=val;
    }
    void setNext(Node<T>* point)
    {
        next=point;
    }
    T Data()
    {
        return data;
    }
    Node<T>* Next()
    {
        return next;
    }
};

template <class T>
class list
{
    Node<T>* head;
    int size;
    
    public:
    list()
    {
        head=NULL;
        size=0;
    }

    void append(T data)
    {
        Node<T>* node=new Node<T>;
        node->setData(data);

        if(head==NULL)
            head=node;

        else
        {
            Node<T>* temp;
            temp=head;
            while(temp->Next()!=NULL)
                temp=temp->Next();
            temp->setNext(node);
        }
        size++;
    }

    int len()
    {
        return size;
    }
    
    T pop(int pos=-1)
    {
        if(head==NULL)
            return -1;
        if(pos==-1)
        {
            Node<T>* temp1,*temp2;
            temp1=head;

            while(temp1->Next()!=NULL)
            {
                temp2=temp1;
                temp1=temp1->Next();
            }
            temp2->setNext(NULL);
            T val=temp1->Data();
            delete temp1;
            size--;
            return val;
        }
        if(pos==0)
        {
            T val=head->Data();
            Node<T>* temp;
            temp=head;
            head=head->Next();
            delete temp;
            size--;
            return val;
        }

        else
        {
            cout<<"backup";
            return -1;
        }
    }

    void display()
    {
        Node<T>* temp;
        temp=head;
        cout<<">> ";
        if(temp==NULL)
        {
            cout<<"EMPTY"<<endl;
            return;
        }
        while(temp!=NULL)
        {
            cout<<temp->Data()<<" ";
            temp=temp->Next();
        }
        cout<<endl;
    }
};