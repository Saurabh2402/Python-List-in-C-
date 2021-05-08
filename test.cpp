#include<iostream>
#include "list.cpp"
using namespace std;

int main()
{
    List<int> l;
    l.display();
    l.append(1);
    l.append(2);
    l.append(3);
    l.append(4);
    l.append(5);
    l.append(6);
    l.append(7);
    l.append(8);
    l.display();
    // l.pop();
    // l.display();
    l.pop(0);
    l.display();
    // l.pop(7);
    // l.display();
    // cout<<l.pop(10).Error()<<endl;
    // cout<<l.len()<<endl;;
    // cout<<l.pop(1).Data()<<endl;
    // l.display();

    return 0;
}