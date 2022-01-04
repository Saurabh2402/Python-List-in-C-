#include<iostream>
using namespace std;

template <class T>
class ReturnObject //Class to simplify error reporting with a few functions
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

    List<T> copy(Node<T>* node2, List<T> l)
    {
        Node<T>* from = node2;
        while(from!=NULL)
        {
            l.append(from->Data());
            from = from->Next();
        }
        return l;
    }
    
    public:
    List()
    {
        head=NULL;
        size=0;
    }
    
    Node<T>* getHead()
    { return head; }

    int len()
    { return size; }

    void setHead(Node<T>* node)
    { head=node; }

    int convertNegativeIndexToPositive(int index)
    {   //If index is negative, it will return corresponding positive index
        //else it will return the positive index itself
        if(index<0)
            return size+index;
        return index;
    }

    void append(T data)
    {
        Node<T>* node=new Node<T>();
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
    
    void insert(int pos, T value)//
    {
        // if(pos>size || pos<-size-2)
        // Checking if pos is valid 
        // cout<<"Cannot insert, as pos is excedding range of size"<<endl;
        // else

        if(pos==0 || pos<=-size) //Insert at beginning
        {
            Node<T>* newNode = new Node<T>();
            newNode->setData(value);
            newNode->setNext(head);
            head = newNode;
        }
        else if(pos>=size) //Insert at end
            append(value);
        else // Insert at any middle position
        {
            pos = convertNegativeIndexToPositive(pos);
            int count=0;
            Node<T>* temp = head;

            while(count<pos-1)
            {
                temp = temp->Next();
                count++;
            }
            Node<T>* newNode = new Node<T>();
            newNode->setData(value);
            newNode->setNext(temp->Next());
            temp->setNext(newNode);        
        }
        size++;
    }

    int index(T val, int start=0, int end=-1)
    {
        //Will return -1 if element is not found
        //Will return -2 if Start index is greater than size
        //Will return -3 if End index is smaller than start

        start = convertNegativeIndexToPositive(start);
        if(end==-1)
            end = size;
        end = convertNegativeIndexToPositive(end);

        if(head==NULL)
        { return -1; }

        if(start>=size)
        { return -2; }

        else if(end<start)
        { return -3; }

        else
        {
            int count=0;
            Node<T>* temp = head;

            while(count<start)
            {
                temp = temp->Next();
                count++;
            }
            while(count<end)
            {
                if(temp->Data()==val)
                    return count;
                if(temp->Next()==NULL)
                    return -1;
                temp = temp->Next();
                count++;
            }
            return -1;// Element not found
        }
    }

    ReturnObject<T> pop(int pos=-1)//To remove an element from the List
    {
        // setError(0) : if there is no error
        // setError(1) : if list is empty
        // setError(2) : if pos is not in the range of size

        ReturnObject<T> obj;
        obj.setError(0);
        if(pos>=size || pos<-size)
            obj.setError(2);    
        else
        {
            pos=convertNegativeIndexToPositive(pos);
        
            if(head==NULL)
                obj.setError(1);
            else if(pos==-1 || pos==size-1) //As we have converted the negative index to positive, just check pos==size-1
            {
                Node<T> *temp1,*temp2;
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
            }
            else if(pos==0)
            {
                obj.setData(head->Data());
                Node<T>* temp;
                temp=head;
                head=head->Next();
                delete temp;
                size--;
            }
            else
            {
                int count=0;
                Node<T> *temp=head, *temp1=head;
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
            }
        }
        return obj;
    }

    ReturnObject<T> remove(T value) //Removes a particular value from the list
    {
        ReturnObject<T> obj;
        if(head->Data()==value)
        {
            pop(0);
            obj.setError(0);
            return obj;
        }
        Node<T> *temp, *prev;
        temp=head;
        while(temp->Data()!=value && temp!=NULL)
        {
            prev=temp;
            temp=temp->Next();
        }
        if(temp==NULL)
            obj.setError(1);
        else
        {   
            obj.setError(0);
            prev->setNext(temp->Next());
            delete temp;          
        }
        return obj;
    }

    void display()
    {
        Node<T>* temp;
        temp=head;
        cout<<">> ";
        if(temp==NULL)
        {
            cout<<"List is EMPTY"<<endl;
            return;
        }
        while(temp!=NULL)
        {
            cout<<temp->Data()<<" ";
            temp=temp->Next();
        }
        cout<<endl;
    }

    void clear() //clears the list
    {
        Node<T> *temp=head, *prev=NULL;
        while(temp!=NULL)
        {   
            delete prev;
            prev=temp;
            temp=temp->Next();
        }
        delete prev;
        head=NULL;
    }

    int count(T val)
    {
        int occur=0;
        Node<T> *temp=head;
        while(temp!=NULL)
        {
            if(temp->Data()==val)
                occur++;
            temp=temp->Next();
        }
        return occur;
    }
    
    ReturnObject<T> operator[](int index)//To get the value at a particular index
    {
        //error is 0 if there is no error
        //error is 1 if list is empty
        //error is 2 if index exceeds size
        
        index = convertNegativeIndexToPositive(index);
        ReturnObject<T> obj;

        if(head==NULL)
        {
            obj.setError(1);
            return obj;
        }
        if(index>size)
        {
            obj.setError(2);
            return obj;
        }

        Node<T>* temp = head;
        int count=0;
        while(count!=index)
        {
            temp = temp->Next();
            count++;
        }
        //cout<<"Count: "<<count<<"  Index: "<<index<<endl;
        obj.setError(0);
        obj.setData(temp->Data());
        return obj;
    }
    
    List<T> operator()(int start,int end,int step=1)
    {
        start = convertNegativeIndexToPositive(start);
        end = convertNegativeIndexToPositive(end);
        int counter = 0;
        List<T> newlist;

        Node<T>* temp = head;
        while(counter<start)
        {
            temp = temp->Next();
            counter++;
        }

        while(counter<end)
        {
            newlist.append(temp->Data());
            //cout<<"Appended: "<<temp->Data()<<endl;

            for(int j=0;j<step;j++){
                if(temp==NULL)
                    break;
                temp = temp->Next();
            }
            counter+=step;
        }
        return newlist;
    }

    List<T> operator+(List<T> list2)
    {
        List<T> list3;
        return copy(list2.getHead(), copy(this->getHead(), list3));
    }
    //l3=l1+l2
};