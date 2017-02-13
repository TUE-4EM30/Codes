#ifndef PQLINKEDLIST_H
#define PQLINKEDLIST_H

#include "StdItem.h"
#include <iostream>

using namespace std;

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------


class PQLinkedList
{
 public:
  
                            PQLinkedList( int nmax );

                            ~PQLinkedList();

  //-----------------------------------------------------------------------------
  // Pre:    -
  // Post:   All items in the queue are removed
  // Return: -
  //-----------------------------------------------------------------------------

  void                      clear();

  //-----------------------------------------------------------------------------
  // Pre:    -   
  // Post:   -
  // Return: returns true if queue is empty
  //-----------------------------------------------------------------------------

  bool                      isEmpty();

  //-----------------------------------------------------------------------------
  // Pre:    Item should have priority >= 0
  // Post:   Item is inserted in the queue
  // Return: -
  //-----------------------------------------------------------------------------

  void                      put

    ( STDITEM                 item );

  //-----------------------------------------------------------------------------
  // Pre:    Queue must contain at least one item
  // Post:   Item with highest priority is removed from the queue
  // Return: Item with the highest priority
  //-----------------------------------------------------------------------------

  STDITEM                   getPrio();

  //-----------------------------------------------------------------------------
  // Pre:    
  // Post:   Prints the first 10 items of the priority array and the next array.
  // Return: 
  //-----------------------------------------------------------------------------

  void                      report();

 private:

  int                       maxItems_;
  static const int          maxPrio_  = 2000;

  STDITEM                   *items_;
  int                       *next_;

  int                       count_;
  int                       free_;
  int                       first_;
};

#endif
