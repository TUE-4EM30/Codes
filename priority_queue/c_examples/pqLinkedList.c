#include <stdio.h>
#include "pqLinkedList.h"

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------

void clear( PQ *pq )
{
  pq->count = 0;
  pq->first = -1;
  pq->free  = -1;
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
  int newPos;

  if ( pq->free == -1 )
  { // No free space, append to array
    newPos = pq->count;
  }
  else
  { // Use first free space.
    newPos = pq->free;
    pq->free = pq->next[ pq->free ];
  }

  pq->items[ newPos ] = item;

  if ( pq->first == -1 || item.prio < pq->items[ pq->first ].prio )
  {
    pq->next [ newPos ] = pq->first;
    pq->first = newPos;
  }
  else
  {
    int i;
    for ( i = pq->first; pq->next[i] != -1 && pq->items[ pq->next[i] ].prio <= item.prio; i = pq->next[i] ) ; // empty loop body!

    pq->next[ newPos ] = pq->next[ i ];
    pq->next[ i ] = newPos;
  }
  pq->count = pq->count + 1;
}

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------

ITEM getPrio( PQ *pq )
{
  ITEM item;
  int newFirst;

  item     = pq->items[ pq->first ];
  newFirst = pq->next [ pq->first ];

  if ( pq->free == -1 )
  {
    pq->free            = pq->first;
    pq->next[pq->first] = -1;
  }
  else
  {
    pq->next[pq->first] = pq->free;
    pq->free            = pq->first;
  }

  pq->first = newFirst;
  pq->count = pq->count - 1;  // lower counter

  return item;
}

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------

void report( PQ *pq )
{
  int j;

  printf("%s","-----------------------------------------------------------\n");
  printf("%s %d %s","  Number of items in Priority Queue: ", pq->count, "\n");
  printf("%s","-----------------------------------------------------------\n");
  printf("    First : %d\n", pq->first );
  printf("    Free  : %d\n", pq->free );
  printf("%s","-----------------------------------------------------------\n");

  printf("  Prio : ");
  for ( j = 0 ; j < 10 ; j++ )
  {
    printf(" %4d",pq->items[j].prio);
  }

  printf("\n  Next : ");
  for ( j = 0 ; j < 10 ; j++ )
  {
    printf(" %4d",pq->next[j]);
  }

  printf("\n");
}
