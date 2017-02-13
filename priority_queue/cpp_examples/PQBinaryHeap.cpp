#include "PQBinaryHeap.h"


//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------


PQBinaryHeap::PQBinaryHeap
 
  ( int      maxItems )

{
  maxItems_ = maxItems;

  items_ = new STDITEM[maxItems];
  
  clear();
}


//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------


PQBinaryHeap::~PQBinaryHeap()

{
}


//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------


void PQBinaryHeap::clear()

{
  count_ =  0;
}


//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------


bool PQBinaryHeap::isEmpty()

{
  return count_ == 0;
}


//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------


void PQBinaryHeap::put

  ( STDITEM                 item )

{
  items_[count_] = item;

  if( count_ == 0 )
  {
    count_++;

    return;
  }
    
  int now    = count_;
  int parent = (now-1)/2;

  while( items_[parent].prio > item.prio && now > 0 	)
  {
    items_[now] = items_[parent];
    now         = parent;
    parent      = (now-1)/2;

  }

  items_[now] = item;
  count_++;
}


//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------


STDITEM PQBinaryHeap::getPrio()

{
  STDITEM minItem, lastItem;
  int     child,   now;
  
  minItem = items_[0];

  lastItem = items_[count_-1];

  /* now refers to the index at which we are now */

  for( now = 0 ; 2*(now+1) < count_ ; now = child )
  {
    /* child is the index of the element which is minimum among both the children */ 
    /* Indexes of children are i*2 and i*2 + 1*/
    
    child = 2*now+1;
                
    /*child!=heapSize beacuse heap[heapSize+1] does not exist, which means it has only one 
                  child */

    if( child != count_+1 && items_[child+1].prio < items_[child].prio ) 
    {
      child++;
    }

    /* To check if the last element fits ot not it suffices to check if the last element
       is less than the minimum element among both the children*/
            
    if( lastItem.prio > items_[child].prio )
    {
      items_[now] = items_[child];
    }
    else /* It fits there */
    {
      break;
    }
  }

  items_[now] = lastItem;

  count_--;

  return minItem;
}


//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------


void PQBinaryHeap::report()

{
  cout << "----------------------------------------------------------\n";
  cout << "  Number of items in Priority Queue: " << count_ << '\n';
  cout << "----------------------------------------------------------\n";
  
  int i = 0;
  int j;

  while ( i < count_ && i < 15 )
  {
    if ( i == 0 )
    {
      cout << "\n  Level 0 :";
    }
    else if ( i == 1 )
    {
      cout << "\n\n  Level 1 :";
    }
    else if ( i == 3 )
    {
      cout << "\n\n  Level 2 :";
    }
    else if ( i == 7 )
    {
      cout << "\n\n  Level 3 : ";
    }

    if ( i == 0 )
    {
      cout << std::string(24, ' ');
    }
    else if ( i < 3 )
    {
      cout << std::string(15, ' ');
    }
    else if ( i < 7 )
    {
      cout << std::string(8, ' ');
    }
    else
    {
      cout << std::string(3, ' ');
    }

    cout << items_[i].prio;
    i++;
  }
 
  cout << "\n\n";
}
