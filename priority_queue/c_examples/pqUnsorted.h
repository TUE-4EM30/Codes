#include <stdbool.h>

#define MAXITEMS 500000
#define MAXPRIO  2000
#define MAXDATA  10


//-----------------------------------------------------------------------------

typedef struct
{
  int    prio;
  char*  data;
} ITEM;


//

typedef struct
{
  ITEM items[MAXITEMS];
  int  count;
} PQ;


//-----------------------------------------------------------------------------
// Pre:    -
// Post:   All items in the queue are removed
// Return: -
//-----------------------------------------------------------------------------

void clear( PQ *pq );


//-----------------------------------------------------------------------------
// Pre:    -
// Post:   -
// Return: returns true if queue is empty
//-----------------------------------------------------------------------------

bool isEmpty( PQ *pq );


//-----------------------------------------------------------------------------
// Pre:    Item should have priority >= 0
// Post:   Item is inserted in the queue
// Return: -
//-----------------------------------------------------------------------------

void put( PQ *pq , ITEM item );


//-----------------------------------------------------------------------------
// Pre:    Queue must contain at least one item
// Post:   Item with highest priority is removed from the queue
// Return: Item with the highest priority
//-----------------------------------------------------------------------------

ITEM getPrio( PQ *pq );

//-----------------------------------------------------------------------------
// Pre:
// Post:
// Return:
//-----------------------------------------------------------------------------

void report( PQ *pq );
