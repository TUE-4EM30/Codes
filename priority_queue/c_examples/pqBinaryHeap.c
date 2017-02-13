#include "pqBinaryHeap.h"
#include <stdio.h>

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
  return pq->count == 0;
}

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------

void put( PQ *pq , ITEM item )
{
  pq->items[pq->count] = item;


  if( pq->count == 0 )
  {
    pq->count++;
    return;
  }

  int now    = pq->count;
  int parent = (now-1)/2;
  int stuck  = 0;

  while( pq->items[parent].prio > item.prio && now > 0 )
  {
    pq->items[now] = pq->items[parent];
    now    = parent;
    parent = (now-1)/2;
  }

  pq->items[now] = item;
  pq->count++;

}

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------

ITEM getPrio( PQ *pq )
{
  ITEM minItem, lastItem;
  int  child,   now;

  minItem = pq->items[0];

  lastItem = pq->items[pq->count-1];

  /* now refers to the index at which we are now */
  for( now = 0 ; 2*(now+1) < pq->count ; now = child )
  {
    /* child is the index of the element which is minimum among both the children */
    /* Indexes of children are i*2 and i*2 + 1*/

    child = 2*now+1;

    /*child!=heapSize beacuse heap[heapSize+1] does not exist, which means it has only
      one child */

    if( child != pq->count+1 && pq->items[child+1].prio < pq->items[child].prio )
    {
      child++;
    }

    /* To check if the last element fits ot not it suffices to check if the last element
       is less than the minimum element among both the children*/

    if( lastItem.prio > pq->items[child].prio )
    {
      pq->items[now] = pq->items[child];
    }
    else /* It fits there */
    {
      break;
    }
  }

  pq->items[now] = lastItem;

  pq->count--;

  return minItem;
}

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------

void report( PQ *pq )
{
  printf("%s","----------------------------------------------------------\n");
  printf("%s %d %s","  Number of items in Priority Queue: ", pq->count, "\n");
  printf("%s","----------------------------------------------------------\n");

  int i = 0;
  int j;

  while ( i < pq->count && i < 15 )
  {
    if ( i == 0 )
    {
      printf("%s","\n  Level 0 :");
    }
    else if ( i == 1 )
    {
      printf("%s","\n\n  Level 1 :");
    }
    else if ( i == 3 )
    {
      printf("%s","\n\n  Level 2 :");
    }
    else if ( i == 7 )
    {
      printf("%s","\n\n  Level 3 : ");
    }

    if ( i == 0 )
    {
      printf("%24s","");
    }
    else if ( i < 3 )
    {
      printf("%15s","");
    }
    else if ( i < 7 )
    {
      printf("%8s","");
    }
    else
    {
      printf("%3s","");
    }

    printf("%d",pq->items[i].prio);
    i++;
  }

  printf("%s","\n\n");

}
