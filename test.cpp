#include<iostream>
#include "list.cpp"
#include<vector>
using namespace std;

int main()
{
    List<int> l1;
    for(int i=0;i<10;i++)
    {
        l1.append(i);
    }
    l1.display();

    List<int> l2;
    for(int i=10;i<20;i++)
    {
        l2.append(i);
    }
    l2.display();

    List<int> l3;
    l3=l1+l2;
    l3.display();    

    cout<<endl<<endl;
    return 0;
}