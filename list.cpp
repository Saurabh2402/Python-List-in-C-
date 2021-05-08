#include<iostream>
using namespace std;

template<class T>
class ReturnObject
{
    T data;
    int error;

    public:
    ReturnObject()
    { error=0; }

    void setError(int e)
    { error=e; }

    void setData(T d)
    { data=d; }

    T Data()
    { return data; }

    int Error()
    { return error; }

};

template <class T>
class Node
{
    T data;
    Node* next;

    public:
    Node()
    { next=NULL; }

    void setData(T val)
    { data=val; }

    void setNext(Node<T>* point)
    { next=point; }

    T Data()
    { return data; }

    Node<T>* Next()
    { return next; }

};

template <class T>
class List
{
    Node<T>* head;
    int size;
    
    public:
    List()
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
    
    ReturnObject<T> pop(int pos=-1)
    {
        ReturnObject<T> obj;
        obj.setError(0);
        if(head==NULL)
        {
           obj.setError(1);
           return obj;
        }
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
            obj.setData(temp1->Data());
            delete temp1;
            size--;

            return obj;
        }
        if(pos==0)
        {
            obj.setData(head->Data());
            Node<T>* temp;
            temp=head;
            head=head->Next();
            delete temp;
            size--;
            return obj;
        }
        
        if(pos>=size)
        {
            obj.setError(1);
            return obj;
        }

        else
        {
            int count=0;
            Node<T>* temp=head, *temp1;
            while(count<pos)
            {
                temp1=temp;
                temp=temp->Next();
                count++;
            }
            obj.setData(temp->Data());
            temp1->setNext(temp->Next());
            delete temp;
            size--;
            return obj;
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