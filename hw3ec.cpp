#include <iostream>
#include "slist.h"
using namespace std;
/*
=======================
Extra Credit for overload operator of ==.
Name: Chris Morikawa
Complier: g++
File Type: hw3 Extra Credit
=======================
*/

//Purpose: A function to compare both linked list.
//Algorithm: Display both L1 and L2, and return either true or false.
void CompTest(slist& list1, slist& list2)
{
 cout << "L1:";
 list1.displayAll();
 cout << " " << endl;
 cout << "L2: ";
 list2.displayAll();
 cout << "Comparing lists" << endl;
 if(list1 == list2)
  cout << "They are the same" << endl;
 else
  cout << "They are different" << endl;
}

//Purpose: To test out the overload operator of comparison.
//Algorithm: Initialized linked list. First, compare both empty linked list.
//Add two elements into the L2 and compare L1 and L2. Then, delete both
// elements from L2 and add two elements into L1, and compare. Next, add both 
//1,2,3 into both lists and compare. Then, delete only 3 from L2 and compare both
// lists. Next, add 3 and 4 into L2 and compare lists. Finally, find 3 in L2 and 
//delete it and compare both lists.
//Local Varialbes: slist L1, slist L2, int result. 
int main ()
{
 int result;
 slist L1, L2;//Initilized linked list.
 
 cout << "1. L1 is empty and L2 is empty" <<endl;
 CompTest(L1, L2);// Compare the empty list. 
 cout << "====================" << endl;
 L2.addRear(1);
 L2.addRear(2);
 cout << "2. L1 is empty and L2 has two elements" << endl;
 CompTest(L1, L2);
 cout << "====================" << endl;
 L1.addRear(1);
 L1.addRear(2);
 L2.deleteRear(result);
 L2.deleteRear(result);
 cout << "3. L1 has 2 elements and L2 is empty" << endl;
 CompTest(L1, L2);
 cout << "====================" << endl;
 L1.addRear(3);
 L2.addRear(1);
 L2.addRear(2);
 L2.addRear(3);
 cout << "4. L1 has 1,2,3 and L2 has 1,2,3" << endl;
 CompTest(L1, L2);
 cout << "====================" << endl;
 L2.deleteRear(result);
 cout << "5. L1 has 1,2,3 and L2 has 1,2" << endl;
 CompTest(L1,L2);
 cout << "====================" << endl;
 L2.addRear(3); 
 L2.addRear(4);
 cout << "6. L1 has 1,2,3 and L2 has 1,2,3,4" <<endl;
 CompTest(L1, L2);
 cout << "====================" << endl;
 L2.deleteIth(3, result);
 cout << "7. L1 has 1,2,3 and L2 has 1,2,4" << endl;
 CompTest(L1, L2);
cout << "====================" << endl;
 return 0;
}
