#include<iostream>
#include "list.cpp"
using namespace std;

int main()
{
    list<int> l;
    l.display();
    l.append(1);
    l.append(2);
    l.append(3);
    l.append(4);
    l.display();
    l.pop();
    l.display();
    l.pop(0);
    l.display();
    cout<<l.len();

    return 0;
}