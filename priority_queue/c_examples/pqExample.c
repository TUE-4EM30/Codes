/************************************************************
* (c) 2017, Joris Remmers (Mechanical Engineering, TUE)
* Example program for the different Priority Queue versions
*   which prints output (if relevant).
*************************************************************/

#include <stdio.h>
#include <time.h>
// #include "pqUnsorted.h"
// #include "pqSorted.h"
//#include "pqSortedBinary.h"
 #include "pqLinkedList.h"
//#include "pqBinaryHeap.h"

void printTime( clock_t t2 , clock_t t1, char* s )
{
  double timeSpent = (double)(t2 - t1) / CLOCKS_PER_SEC;

  printf("Time needed to %-35s : %f seconds\n", s , timeSpent);
}

int main ( void )
{
  PQ   pq;
  ITEM item;

  clear ( &pq );

  clock_t t0,t1,t2,t3,t4,t5;

  double timeSpent;
  int i;

  t0 = clock();

  for ( i = 0 ; i < 100000 ; i++ )
  {
    item.data = "TU Eindhoven, 4ME30";
    item.prio = rand()%1000;
    put( &pq , item );
  }

  t1 = clock();

  printTime( t1 , t0 , "add first batch of 100.000 items" );

//-----------------------------------------------------------------------------

  for ( i = 0 ; i < 100000 ; i++ )
  {
    item.data = "TU Eindhoven, 4ME30";
    item.prio = rand()%1000;
    put( &pq , item );
  }

  t2 = clock();

  printTime( t2 , t0 , "add second batch of 100.000 items" );

//-----------------------------------------------------------------------------

  for ( i = 0 ; i < 100000 ; i++ )
  {
    item = getPrio( &pq );
  }

  t3 = clock();

  printTime( t3 , t2 , "get 100.000 priorities" );

//-----------------------------------------------------------------------------

  for ( i = 0 ; i < 100000 ; i++ )
  {
    item.data = "TU Eindhoven, 4ME30";
    item.prio = rand()%1000;
    put( &pq , item );
  }

  t4 = clock();

  printTime( t4 , t3 , "add another batch of 100.000 items" );

//-----------------------------------------------------------------------------

  for ( i = 0 ; i < 200000 ; i++ )
  {
    item = getPrio( &pq );
  }

  t5 = clock();

  printTime( t5 , t4 , "get 200.000 priorities" );

//-----------------------------------------------------------------------------

  printTime( t5 , t0 , "for all operations" );

  return 0;
}
