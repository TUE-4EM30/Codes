#ifndef PQUNSORTED_H
#define PQUNSORTED_H

#include "StdItem.h"

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------


class PQUnsorted
{
 public:
  
                            PQUnsorted( int maxItems );

                            ~PQUnsorted();

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

 private:

  int                       maxItems_;
  static const int          maxPrio_  = 2000;

  STDITEM                   *items_;

  int                       count_;
};

#endif
