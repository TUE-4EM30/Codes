#include "PQLinkedList.h"


//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------

PQLinkedList::PQLinkedList
 
  ( int      maxItems )

{
  maxItems_ = maxItems;

  items_ = new STDITEM[maxItems];
  next_  = new int[maxItems];
  
  clear();
}


//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------


PQLinkedList::~PQLinkedList()

{
}


//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------


void PQLinkedList::clear()

{
  count_ =  0;
  first_ = -1;
  free_  = -1;
}


//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------


bool PQLinkedList::isEmpty()

{
  return count_ == 0;
}


//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------


void PQLinkedList::put

  ( STDITEM                 item )

{
  int newPos; 
  
  if ( free_ == -1 ) 
  { 
    newPos = count_;               // No free space, append to array
  } 
  else 
  { 
    newPos = free_;                // Use first free space.
    free_  = next_[ free_ ];
  }

  items_[ newPos ] = item;
  
  if ( first_ == -1 || item.prio < items_[ first_ ].prio ) 
  {
    next_ [ newPos ] = first_;
    first_ = newPos;
  } 
  else 
  { 
    int i;

    for ( i = first_ ; next_[i] != -1 && items_[ next_[i] ].prio <= item.prio; i = next_[i] ); // empty loop body!
  
    next_ [ newPos ] = next_ [ i ];
    next_ [ i ] = newPos;
  }

  count_++;
}


//
//
//


STDITEM PQLinkedList::getPrio()

{
  STDITEM prio;
  int     newFirst;

  prio     = items_[first_];
  newFirst = next_ [first_];

  if ( free_ == -1 )
  {
    free_         = first_;
    next_[first_] = -1;
  }
  else
  {
    next_[first_ ] = free_;
    free_ = first_;
  }

  first_ = newFirst;
  count_--;

  return prio;
}


//
//
//


void PQLinkedList::report()

{
  cout << "----------------------------------------------------------\n";
  cout << "  Number of items in Priority Queue: " << count_ << '\n';
  cout << "----------------------------------------------------------\n";
  cout << "    First : " << first_ << '\n';
  cout << "    Free  : " << free_  << '\n';
  cout << "----------------------------------------------------------\n\n";

  cout << "  Prio : ";

  for ( int j = 0 ; j < 10 ; j++ )
  {
    cout << ' ' << items_[j].prio;
  }

  cout << "\n  Next : ";

  for ( int j = 0 ; j < 10 ; j++ )
  {
    cout << ' ' << next_[j];
  }

  cout << "\n";
}
