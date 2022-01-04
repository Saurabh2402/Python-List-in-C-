# Python's List Data Structure in C++

We have implemeted Python's List Data Structure in C++ Language.
This projects aims at implementing some member functions of List for any datatype (say int, char or any user defined datatype).


We were successful in implementing following functions - 

  ( x is a variable & can be of any datatype (c++ template is used for its implementation) )
  
  1) append(x)            :  x will be appended to the list. 
  
  2) insert(int pos, x)   :  x will be inserted at the respective position.
                             if pos is +ve : indexing starts from left by value 0,
                             if pos is -ve : indexing starts from the end by value -1, then
                             inserting will be done accordingly.
                       
  3) index(x, start, end) :  Finds x within the range (start, end) excluding end
                             User can pass start or end as -ve indices also.
                             It will work in the same way as it would in python.
                                 
  4) pop(int pos)         : Pops element at specified index.
  
  5) remove(x)            : Removes first occurance of element x.
  
  
Overloaded Operators - (), [], +

 6) slicing operator       () - (int start, int end, int step) : returns a new list from specified range(start,end) and specified step.
 
 8) member access operator [] - [int pos] : returns element at specified position.
 
 10) concatenation operator  + - (x1,x2) : returns a new list with x1 and x2 concatenated.
