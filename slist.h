#ifndef SLIST_H
#define SLIST_H

#include "llist.h"
#include <iostream>
using namespace std;
//==============================
//HW#:HW3P2 slist
//Name: Chris Morikawa
//Complier: g++
//File Type: slist header file
//==============================

class slist : public llist//Inherit all the methods from llist class 
{

 public:
 slist();//default contructor for slist.
//~slist();
 int search(el_t); //Search the postion of the number from the list.
 void replace(el_t, int);//Replace the Ith Node
 slist(const slist& Original);
 slist& operator=(const slist& OtherOne);
 bool operator==(const slist& OtherOne2) const;
}; 
#endif

