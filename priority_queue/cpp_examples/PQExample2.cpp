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
#include "PQUnsorted.h"
//#include "PQSorted.h"
//#include "PQSortedBinary.h"
#include "PQBinaryHeap.h"

using namespace std;// std::cout;

void printTime( clock_t t2 , clock_t t1 ,  char* s )

{
  double timeSpent = (double)(t2 - t1) / CLOCKS_PER_SEC;

  cout << "Time needed to " << setfill('.') << setw(35) << left << s << ": " << timeSpent << " seconds.\n";
}




int main ( void ) 
{
  PQBinaryHeap       pq(100000);
  STDITEM            item;

  pq.clear ();

  clock_t t0,t1,t2,t3,t4,t5;
  
  double timeSpent;
  int i;
  

  t0 = clock();


  item.data = "Star Wars: Rogue One";
  item.prio = 10;
  pq.put( item );
 
  item.prio = 42;
  pq.put( item );

  item.prio = 7;
  pq.put( item );

  item.prio = 99;
  pq.put( item );

  item.prio = 15;
  pq.put( item );

  pq.getPrio();
  pq.getPrio();
  
  item.prio = 31;
  pq.put( item );

  item.prio = 18;
  pq.put( item );

  item.prio = 45;
  pq.put( item );

  item.prio = 1;
  pq.put( item );

  item.prio = 106;
  pq.put( item );

  item.prio = 3;
  pq.put( item );

  item.prio = 1;
  pq.put( item );

  item.prio = 4;
  pq.put( item );

  item.prio = 15;
  pq.put( item );

  item.prio = 16;
  pq.put( item );

  item.prio = 15;
  pq.put( item );

  item.prio = 15;
  pq.put( item );

  item.prio = 41;
  pq.put( item );

  item.prio = 11;
  pq.put( item );

  item.prio = 21;
  pq.put( item );

  while( !pq.isEmpty() )
  {
    pq.getPrio();
    pq.report();
  }

  return 0;
}
