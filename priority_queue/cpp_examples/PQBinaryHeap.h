#ifndef PQBINARYHEAP_H
#define PQBINARYHEAP_H

#include "StdItem.h"
#include <iostream>

using namespace std;

//-----------------------------------------------------------------------------
//  PQBinaryHeap   
//    Priority Queue implementation using a binary heap
//-----------------------------------------------------------------------------


class PQBinaryHeap
{
 public:
  
                            PQBinaryHeap( int nmax );

                            ~PQBinaryHeap();

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
  // Post:   Writes the first 4 layers (0-3) of the tree to the console
  // Return: 
  //-----------------------------------------------------------------------------
   
  void                      report();

 private:

  int                       maxItems_;

  STDITEM                   *items_;

  int                       count_;
};

#endif
