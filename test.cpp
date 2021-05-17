#include<iostream>
#include "list.cpp"
#include<vector>
using namespace std;

int main()
{
    List<int> l1;
    l1.append(1);
    l1.append(2);
    l1.append(1);
    l1.append(3);
    l1.append(3);
    l1.append(1);
    l1.append(1);
    l1.display();
    cout<<l1.count(1)<<endl;;

    

    cout<<endl<<endl;
    return 0;
}