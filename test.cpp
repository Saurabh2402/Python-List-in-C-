#include<iostream>
#include "list.cpp"
#include<vector>
using namespace std;

int main()
{
    List<int> l1;
    l1.append(10);
    l1.append(20);
    l1.append(30);
    l1.append(40);
    l1.append(50);
    l1.append(60);
    l1.append(70);
    l1.append(40);
    l1.append(80);
    l1.append(90);
    l1.append(100);
    l1.display();

    //Demo of Slicing
    List<int> l2 = l1(1,-3); // l1(start,end)
    l2.display();
    
    List<int> l3 = l1(1,8,2);// l1(start,end,step)
    l3.display();

    List<int> l4 = l1(-5,-1);// l1(start,end,step)
    l4.display();

    //Demo of index function
    cout<<"index : "<<l1.index(40)<<endl;
    cout<<"index : "<<l1.index(40,4,-1)<<endl;
    cout<<"index : "<<l1.index(40,l1.index(40)+1)<<endl;
    
    cout<<endl<<endl;
    return 0;
}