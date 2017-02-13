/************************************************************
* (c) 2016, Joris Remmers (Mechanical Engineering, TUE)
* Example program that prints the table of multiplication
*   for a given base number.
*************************************************************/

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "StdItem.h"
//#include "PQUnsorted.h"
//#include "PQSorted.h"
//#include "PQSortedBinary.h"
//#include "PQLinkedList.h"
#include "PQBinaryHeap.h"

using namespace std;// std::cout;

void printTime( clock_t t2 , clock_t t1 ,  char* s )

{
  double timeSpent = (double)(t2 - t1) / CLOCKS_PER_SEC;

  cout << "Time needed to " << setfill('.') << setw(35) << left << s << ": " << timeSpent << " seconds.\n";
}




int main ( void ) 

{
  //PQUnsorted       pq(500000);  
  //PQSorted         pq(500000);  
  //PQSortedBinary   pq(500000);  
  //PQLinkedList     pq(500000);  
  PQBinaryHeap     pq(500000);  
 
  STDITEM            item;

  pq.clear ();

  clock_t t0,t1,t2,t3,t4,t5;
  
  double timeSpent;
  int i;
  

  t0 = clock();

  for ( i = 0 ; i < 100000 ; i++ )
  {
    item.data = "TU Eindhoven, 4ME30";
    item.prio = rand()%1000;
    pq.put( item );
  }

  t1 = clock();

  printTime( t1 , t0 , "add first batch of 100000 items" );

  for ( i = 0 ; i < 100000 ; i++ )
  {
    item.data = "TU Eindhoven, 4ME30";
    item.prio = rand()%1000;
    pq.put( item );
  }

  t2 = clock();

  printTime( t2 , t1 , "add second batch of 100000 items" );

  for ( i = 0 ; i < 100000 ; i++ )
  {
    item = pq.getPrio();
  }

  t3 = clock();

  printTime( t3 , t2 , "get 100000 priorities" );

  for ( i = 0 ; i < 100000 ; i++ )
  {
    item.data = "TU Eindhoven, 4ME30";
    item.prio = rand()%1000;
    pq.put( item );
  }

  t4 = clock();

  printTime( t4 , t3 , "add another batch of 100000 items" );

  for ( i = 0 ; i < 200000 ; i++ )
  {
    item = pq.getPrio();
  }

  t5 = clock();

  printTime( t5 , t4 , "get 200000 priorities" );
 
  printTime( t5 , t0 , "for all operations" );

  return 0;
}
