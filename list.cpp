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

    int len()
    {
        return size;
    }
    
    void insert(int pos, T value)//remember to do size++
    {
       // if(pos>size || pos<-size-2) // Checking if pos is valid 
       //     cout<<"Cannot insert, as pos is excedding range of size"<<endl;
       // else
        {
            
            if(pos==0 || pos<=-size)//Insert at beginning
            {
                Node<T>* newNode = new Node<T>();
                newNode->setData(value);
                newNode->setNext(head);
                head = newNode;
            }
            else if(pos>=size)   //Insert at end
                append(value);

            else    // Insert at any middle position
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
        

    }

    int index(T val, int start=0, int end=-1)
    {
        //Will return -1 if element is not found
        //Will return -2 if Start index is greater than size
        //Will return -3 if End index is smaller than start
        //Will return -1 if element is not found
        start = convertNegativeIndexToPositive(start);
        if(end==-1)
            end = size;
        end = convertNegativeIndexToPositive(end);

        if(head==NULL)
            {cout<<"List is Empty"<<endl;return -1;}
        if(start>=size)
            {cout<< "Start index is greater than size!"<<endl;return -2;}
        else if( end<start)
            {cout<< "End index is smaller than start!"<<endl;return -3;}

        else
        {
            cout<<"\nStarted search from "<< start << " to "<<end<<endl;
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


    ReturnObject<T> pop(int pos=-1)//remember to do size--
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
            pos = convertNegativeIndexToPositive(pos);
        
            if(head==NULL)
                obj.setError(1);
            
            else if(pos==-1 || pos==size-1) //As we have converted the negative index to psitive, just check pos==size-1
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
    
    int convertNegativeIndexToPositive(int index)
    {   //If index is negative, it will return corresponding positive index
        //else will return the positive index itself
        if(index<0)
            return size+index;
        return index;

    }
    
    ReturnObject<T> operator[](int index)
    {
        //error is 1 if index exceeds size
        //error is 2 if list is empty
        //error is 0 if there is no error
        index = convertNegativeIndexToPositive(index);
        ReturnObject<T> obj;
        if(index>size)
        {
            obj.setError(1);
            return obj;
        }
        if(head==NULL)
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


    
};