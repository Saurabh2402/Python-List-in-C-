#include<iostream>
#include "list.cpp"
#include<vector>
using namespace std;

int main()
{
    system("cls");

    List<char> l;
    for(int i=0;i<9;i++)
        l.append(i+'A');

    //Negative Indexes
    cout<<">> ";
    for(int i=l.len();i>0;i--)
        cout<<i<<" ";
    cout<<endl;

    //Positive Indexes
    cout<<">> ";
    for(int i=0;i<l.len();i++)
        cout<<i<<" ";
    cout<<endl;

    l.display();

    /*
   ReturnObject<char> poppedObj = l.pop(-99);
    if(poppedObj.Error()==0)
        cout<<"Popped Value : "<<poppedObj.Data()<<endl; 
    else if(poppedObj.Error()==1)
        cout<<"Cannot pop as List is EMPTY"<<endl;
    else if(poppedObj.Error()==2)
        cout<<"Cannot pop as passed position is out of SIZE"<<endl;
    l.display();
    */

   
    /*l.insert(-99,'*');  
    l.display();*/
    int answer = l.index('D',0,99);
    cout<<"Index of D is : "<<answer<<endl;
   /*l.index('Z');//0 to 9
   l.index('Z',2,4);//0 to 4
   l.index('Z',-4);//5 to 9
   l.index('Z',-6,-3);//3 to 6
   l.index('Z',2,55);// 2 to 55*/
    /*List<char> subList;
    subList = l(2,9,3);
    subList.display();
    */

   /*
   int answer = l[-5].Error();
   if(answer==0)
    cout<<"Element at index is : " << l[-5].Data()<<endl;
   if(answer==1)
    cout<<"Index is exceeding size"<<endl;
   if(answer==2)
    cout<<"List is EMPTY!"<<endl;
    */
   
    cout<<endl<<endl;
    return 0;



}