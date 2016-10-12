#include "slist.h"
//===========================
//HW#: HW3P2
//Your Name: Chris Morikawa
//Complier: g++
//File Tpye: slist implementation file
//===========================

slist::slist():llist()
{
 //Calls the llist constructor
}

//========================
/*
Purpose: The purpose of the search function is to go through the list and 
find the postion of where that number is.
Algorithm: First check to see if the list is empty. Then make a pointer to
go through the list until it finds the number and return the position number.
Parameters: el_t Key
Local Variables: Node *p, int c
*/
int slist::search(el_t Key)
{
 int c = 0;//Local counter for position number.
 if(isEmpty())//Just return if the list is empty.
   return 0;
 Node *p = Front;//Make a pointer
 while(p != NULL)//Keep going while p is not NULL
 {
  c++;
  if(p->Elem == Key)//If the key matches exectue the following
  {
   cout << "Found the element in position: " << c << endl;
   return c;
  }
  p=p->Next;//If no key found, then on to the next one
 }
 cout<< "Could not find " << Key << endl;//If no key found, then return statement
}

//=========================
/*
Purpose: Take the postion number that the search function returns and 
go to that number and replace the old number with a new number.
Algorithm: Check to see if the posistion is Out of Range. Then go through the list 
till you get to that positon in the list. Then replace the old number with a new number. 
Parameters: el_t elem, int I
Local Variables: Node *p, int i 
*/
void slist::replace(el_t elem, int I)
{
 if(I<0 || I>Count)//If I is not within the range
  throw OutOfRange();
 Node* p = Front;//Make a pointer
 for(int i = 1; i<=I-1; i++)//Go to the right node, after finding it from the search function
   p=p->Next;
 p->Elem = elem;//Replace the old number with the new number
 cout << "The number has been replaced" << endl;
}

//======================
/*
Purpose: To copy a Linear Link List into another one. The Original 
being passed to the constructor by reference.
Algorithm: Create and initialized the linear link list, then 
copy the original values from the original llist into the new one.
Local Variable: Node* p
*/
slist::slist(const slist& Original)
{
  el_t n;
  if (&Original != this)
  {
   while (!this ->isEmpty())
    this->deleteRear(n);

   Node* p;//Local pointer
   p = Original.Front;//Have the p point to the Original Front of the llist.
   while(p!=NULL)//While p is not NULL
   {
    this->addRear(p->Elem);
    p=p->Next;
   }
  }//end of if
}

//====================
/*
Purpose: Overload the = operator to allow values from one linked list to another linked list
Algorithm: Pretty much follows the same algorithm as the copy constructor above. 
Local Variable: Node* p
*/
slist& slist::operator= (const slist& OtherOne)
{
 el_t n;
 // First make sure this-> and OtherOne are not the same object.
 // To do this, compare the pointers to the objects .
 if(&OtherOne != this)
  {
   // this-> object has to be emptied first.
   while(!this->isEmpty())
    this->deleteRear(n);
   // this-> object has to be built up by allocating new cells (**)
   Node* p;//Local Pointer for OtherOne
   p = OtherOne.Front;
   while( p != NULL)// This uses a loop which repeats until you reach the end of OtherOne. 
   {
    this->addRear(p->Elem);//p's element is added to this->
    p = p->Next;// Go to the next node in OtherOne
   }
 }
return *this;// return the result unconditionally.
}

//====================
/*
Purpose: Overload equality operator to help compare 
linked list.
Algorithm: If the Count does not equal to parameter link list,
return false. Go through the each linked list and compare their 
elements. Return true if all elements of both linked list equals.
Local Variable: Node* p, Node* q
*/
bool slist::operator==(const slist& OtherOne2) const
{
 //Check to see if both Linked list equals. 
 if(this->Count != OtherOne2.Count)
   return false;
 Node* p;//Local pointers
 Node* q;
 p = this->Front;// p points to copied list
 q = OtherOne2.Front; //q points to the other linked list. 
 while (p != NULL)
  {
    if (p->Elem != q->Elem)//if both elments don't match then return false. 
     return false;
   p = p->Next;
   q = q->Next;
  }
 return true;//After while, return true. 
}










