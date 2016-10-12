//INSTRUCTION:
//Use the provided text to help create llist.cpp
//based on Yoshii  CS311  Notes-6A

//- Make sure PURPOSE and PARAMETER comments are given
//  DO NOT DELETE my descriptions but USE them.
//- Make sure all if-then-else are commented describing which case it is
//- Make sure all local variables are described fully with their purposes
//EMACS HINT:
//  control-K cuts and control-Y pastes
//  Esc X replace-str does string replacements
//  Esc > goes to the end of the file; Esc < to the beginning
//  Tab on each line will indent perfectly for C++

// ====================================================
//HW#: HW3P1 llist
//Your name: Chris Morikawa
//Complier:  g++
//File type: llist implementation file
//=====================================================

using namespace std;

#include<iostream>
#include"llist.h" 

/*Constructor
- initialize Front and Rear to be NULL and Count = 0.
- This does not create any node.  The new list is empty.
*/
llist::llist()
{
 Rear = NULL;
 Front = NULL;
 Count = 0;
}  
/*
Destructor 
Purpose: To destroy a Link List. 
Algorithm: while the list is not empty, call deleteFront repeatedly to delete all nodes.
Please place a cout in this function "calling the llist desctructor."
Local Variables: Node* p;
*/
llist::~llist()
{
cout << "!!!!!!!!!!!!!" << endl;
cout << "~llist" << endl;
 Node* p;
 while(Front != NULL)
  {
    p = Front;
    Front = Front->Next;
    delete p;
  }
}

/*
Purpose: To tell either if the Link List is empty or not. 
Algorithm: return true if Front and Rear are both pointing to NULL and Count is 0.
(all 3 conditions must be checked)
*/
bool llist::isEmpty()
{
 if(Count == 0 && Front == NULL && Rear == NULL)
    return true;
 else
    return false;
}

/*
 //Purpose: To display all items from the list.
 // - Special case: if the list is empty, display [ empty ] ).
 // - Regular:
  ///  displays each element of the list horizontally starting from Front in [ ]
 //Algorithm: Have a pointer point to the front of the list, go through a while loop
// and display each number from the node and go on to the next until you reach the end.
 //Local variable: Node* p
*/

void llist::displayAll()
{
if (isEmpty())
cout << "[ empty ]" << endl; 
else
 {
   Node* p = Front; //Have p point to front
   cout << "[ ";
   while (p != NULL) //Go through the linked list till the end
   {
    cout << p -> Elem << " "; //grab the element from the node.
    p = p -> Next; //go on to the next node.
   }
   cout << " ]" << endl; 
 }
}  

/*
Purpose: Add a node to the rear end of the linked list.
Algorthim: adds a new node at the rear and puts NewNum in the Elem field
of this new node. Count is updated.
(special case: if this is going to be the very first node, you must
 create a new node and make Front and Rear point to it.)
Local variables: Node* p, Node* newN
*/
void llist::addRear(el_t NewNum) 
{
 if(Front == NULL)
  addFront(NewNum);  
 else
 {
  Node* p = Front;
  Node* newN = new Node;
  while(p-> Next != NULL)
    p=p->Next;
  Rear->Next=newN;
  Rear=Rear->Next; 
  newN->Elem = NewNum; //set the new node's Elem to the number
  Rear->Next = NULL; //point newN's next to Null.
  Count++;
 }
}

/*
Purpose: To add a new Node to the front of the linked list.
Algorithm: will add a new node to the front of the list. Count is updated.
(special case: if this is going to be the very first node, you must
create a new node and make Front and Rear point to it.)
Local Variable: Node* newN
*/
void llist::addFront(el_t NewNum)
{
 Node* newN = new Node;
 if (Front == NULL)
  {
   Front = newN;
   Rear = Front;
   newN-> Elem = NewNum;
  }
 else
 {
  newN->Next = Front;
  Front = newN;
  Front->Elem = NewNum;
 }
 Count++;
}

/*
Purpose: To delete the front node from the link list.
Algorithm: error case: if the List is empty, throw an exception.
else give back the front node element through OldNum (pass by reference)
and also remove the front node. Count is updated.
(special case: if this is going to make the list empty,
make sure both Front and Rear become NULL).
Local variable: Node* p
*/
void llist::deleteFront(el_t& OldNum)
{
 if(isEmpty())
  throw llist::Underflow();
 Node* p = Front; // pointer point to front
 Front = Front -> Next;
 if(Count == 1)
  {
   Rear = Front;
   Count--;
   OldNum = p->Elem;
   delete p;
  }
 else
  {
  Count--;
  OldNum = p->Elem;
  delete p;
  }
}

/*
Purpose: To delete the Rear of the linked list.
Algorithm: error case: if the List is empty, throw an exception.
else give back the front node element through OldNum (pass by reference)
and also remove the front node. Count is updated.
(special case: if this is going to make the list empty,
make sure both Front and Rear become NULL).
Local Variable: Node* p
*/
void llist::deleteRear(el_t& OldNum)
{
 if(isEmpty())
  throw llist::Underflow();
 else if(Front->Next == NULL) //Special Case for only one node
 {
  OldNum = Rear -> Elem;
  delete Rear;
  Front = NULL;
  Rear = NULL;
  Count--;
 }
 else
 {
  Node* p = Front; //New pointer to point to the front
  while( p -> Next -> Next != NULL) // Go to the end of the list
  {
    p = p -> Next;
  }
  OldNum = Rear->Elem;
  delete Rear;
  Rear = p;
  Rear -> Next = NULL;
  Count--;
 }
}

/*
Purpose: To delete a specific node within the linked list.
Algorithm:4 cases:
- Error case:
  If I is an illegal value (i.e. > Count or < 1) throw OutOfRange.
- Special cases: this should simply call deleteFront when I is 1 or
  deleteRear when I is Count
- Regular: delete the Ith node (I starts out at 1).  Count is updated.
<see the template loops in the notes to move 2 pointers to the right nodes;
and make sure you indicate the purposes of these local pointers>
Local Variable: Node* p, Node* q, int J
*/
void llist::deleteIth(int I, el_t& OldNum)
{
 Node* p = Front;// Current 
 Node* Del;// Previous
 if(I < 1 || I > Count) //If the element is beyond the range.
  throw llist::OutOfRange();
 if(isEmpty())
  throw llist::OutOfRange(); 
 else
 {
  if(I == 1) //If the element is in the first slot
   deleteFront(OldNum);
  else if (I == Count) //If the element is the rear of the list.
   deleteRear(OldNum);
  else //Regular Case
  {
   for(int j = 1; j < I-2; j++)
   {
    p = p-> Next;
   }
   Del = p->Next;
   OldNum = Del -> Elem;
   p->Next = Del->Next;
   delete Del;
   Count--;
  }
 }
}

/*
Purpose: Add a node before a specifc node wihtin the linked list.
Algorithm: 4 cases:
-  Error case:
   If I is an illegal value (i.e. > Count+1 or < 1) throw OutOfRange.
-  Special cases: this should simply call addFront when I is 1 or addRear when
   I is Count+1
-  Regular: add right before the Ith node. Cout if updated.
<see the template loops in the notes to move 2 pointers to the right nodes
and make sure you indicate the purposes of these local pointers>
Local variable: Node* p, Node* q, int K
*/
void llist::addbeforeIth(int I, el_t newNum)
{ 
 Node* p = Front;//Current
 Node* q;//Prev

 if(I < 1 || I > Count+1)// Check to see if the node will be count of range
  throw llist::OutOfRange();
 else
 {
  if(I == 1)//If it is the front node
   addFront(newNum);
  else if (I == Count+1) //If it is the last node.
   addRear(newNum);
  else// otherwise 
  {
   for(int K = 1; K < I-1; K++)
   {
    p = p -> Next;
   }
   q = p->Next;
   p->Next = new Node;
   p = p->Next;
   p->Elem = newNum;
   p->Next = q;
   Count++;
  }
 }
}
