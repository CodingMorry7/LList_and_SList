//====================================
//HW#: HW3P1 llist
//Your name: Chris Morikawa
//Complier:  g++
//File type: llist implementation file
//====================================
#ifndef llist_h
#define llist_h

typedef int el_t;

struct Node
{
  el_t Elem;
  Node *Next;
};

//------------------------------

class llist
{

 protected:
  Node *Front;
  Node *Rear;
  int  Count;

 public:
  class Underflow{};
  class OutOfRange{};
 
  llist();
  ~llist();
 
 /*
 Purpose: To tell either if the Link List is empty or not.
 Algorithm: return true if Front and Rear are both pointing to NULL and Count is 0.
 (all 3 conditions must be checked)
 */
  bool isEmpty();
 
 /*
 //Purpose: To display all items from the list.
 // - Special case: if the list is empty, display [ empty ] ).
 // - Regular:
  ///  displays each element of the list horizontally starting from Front in [ ]
  //Algorithm: Have a pointer point to the front of the list, go through a while loop
 // and display each number from the node and go on to the next until you reach the end.
  //Local variable: Node* p
 */
  void displayAll();
  
  /*
  Purpose: To add a new Node to the front of the linked list.
  Algorithm: will add a new node to the front of the list. Count is updated.
  (special case: if this is going to be the very first node, you must
  create a new node and make Front and Rear point to it.)
  Local Variable: Node* newN
  */
  void addFront(el_t NewNum);
 
  /*
 Purpose: Add a node to the rear end of the linked list.
 Algorthim: adds a new node at the rear and puts NewNum in the Elem field
 of this new node. Count is updated.
 (special case: if this is going to be the very first node, you must
 create a new node and make Front and Rear point to it.)
 Local variables: Node* p, Node* newN
 */
  void addRear(el_t NewNum);
  
 /*
 Purpose: To delete the front node from the link list.
 Algorithm: error case: if the List is empty, throw an exception.
 else give back the front node element through OldNum (pass by reference)
 and also remove the front node. Count is updated.
 (special case: if this is going to make the list empty,
 make sure both Front and Rear become NULL).
 Local variable: Node* p
 */ 
  void deleteFront(el_t& OldNum);
 
 /*
 Purpose: To delete the Rear of the linked list.
 Algorithm: error case: if the List is empty, throw an exception.
 else give back the front node element through OldNum (pass by reference)
 and also remove the front node. Count is updated.
 (special case: if this is going to make the list empty,
 make sure both Front and Rear become NULL).
 Local Variable: Node* p
 */ 
  void deleteRear(el_t& OldNum);
 
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
  void deleteIth(int I, el_t&OldNum);
 
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
  void addbeforeIth(int I, el_t newNum);
  };
#endif
