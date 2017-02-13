/************************************************************
* (c) 2017, Joris Remmers (Mechanical Engineering, TUE)
* Example program for the different Priority Queue versions
*   which prints output (if relevant).
*************************************************************/

#include <stdio.h>
// #include "pqUnsorted.h"
// #include "pqSorted.h"
// #include "pqLinkedList.h"
#include "pqBinaryHeap.h"

int main ( void )
{
  PQ   pq;
  ITEM item;

  clear ( &pq );

  item.data = "TU Eindhoven, 4ME30";
  item.prio = 10;
  put( &pq , item );

  item.prio = 42;
  put( &pq , item );

  item.prio = 7;
  put( &pq , item );

  item.prio = 99;
  put( &pq , item );

  item.prio = 15;
  put( &pq , item );

  item = getPrio( &pq );
  item = getPrio( &pq );

  item.prio = 31;
  put( &pq , item );

  item.prio = 18;
  put( &pq , item );

  item.prio = 45;
  put( &pq , item );

  item.prio = 1;
  put( &pq , item );

  item.prio = 106;
  put( &pq , item );

  item.prio = 3;
  put( &pq , item );

  item.prio = 1;
  put( &pq , item );

  item.prio = 4;
  put( &pq , item );

  item.prio = 15;
  put( &pq , item );

  item.prio = 16;
  put( &pq , item );

  item.prio = 15;
  put( &pq , item );

  item.prio = 15;
  put( &pq , item );

  item.prio = 41;
  put( &pq , item );

  item.prio = 11;
  put( &pq , item );

  item.prio = 21;
  put( &pq , item );

  while( !isEmpty( &pq ) )
  {
    item = getPrio( &pq );
    report( &pq );
  }

  return 0;
}
