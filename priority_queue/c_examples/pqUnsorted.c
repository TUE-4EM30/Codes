#include <stdio.h>
#include "pqUnsorted.h"


//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------

void clear( PQ *pq )
{
  pq->count = 0;
}

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------

bool isEmpty( PQ *pq )
{
  if ( pq->count == 0 )
  {
    return true;
  }
  else
  {
    return false;
  }
}

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------

void put( PQ *pq , ITEM item )
{
  pq->items[pq->count] = item;
  pq->count++;
}

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------

ITEM getPrio( PQ *pq )
{
  ITEM prioItem;

  int  i_min    = MAXITEMS;  // index of minimum (initialised as maximum possible priority)
  int  min_prio = MAXPRIO;   // minimum priority up to now (initialised as maximum priority number)
  int  i;

  for ( i = 0 ; i < pq->count ; i++ )
  {
    if ( pq->items[i].prio < min_prio )
    {
      i_min = i;
      min_prio = pq->items[i].prio;
    }
  }

  prioItem = pq->items [ i_min ];

  if ( i_min < (pq->count-1) )
  {
    pq->items [ i_min ] = pq->items [ pq->count - 1 ]; // move
  }

  pq->count = pq->count - 1;  // lower counter

  return prioItem;
}

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------

void report( PQ *pq )
{
  // Empty 
}
