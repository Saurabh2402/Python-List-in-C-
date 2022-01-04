# Python's List Data Structure in C++

We have implemeted Python's List Data Structure in C++ Language.
This projects aims at implementing some member functions of List for any datatype (say int, char or any user defined datatype).



We were successfull in implementing following functions - 
  ( x is a variable & can be of any datatype (c++ template is used for its implementation) )
  
  append(x) :  x will be appended to the list. 
  
  insert(int pos, x) : x will be inserted at the respective position.
                       if pos is +ve : indexing starts from left by value 0,
                       if pos is -ve : indexing starts from the end by value -1, then
                       inserting will be done accordingly.
                       
  index(x, int start, int end) : Finds x within the range (start, end) excluding end
                                 User can pass start or end as -ve indices also.
                                 It will work in the same way as it would in python.
                                 
  pop(int pos)           : Pops element at specified index.
  
  remove(x)              : Removes first occurance of element x.
  
  
Overloaded Operators - (), [], +

 slicing operator () - (int start,int end, int step) : returns a new list from specified range(start,end) and specified step.
 member access operator[] - [int pos] : returns element at specified position.
 concatenation operator + - (x1,x2) : returns a new list with x1 and x2 concatenated;
