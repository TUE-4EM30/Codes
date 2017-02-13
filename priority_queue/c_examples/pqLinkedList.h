#include <stdbool.h>

#define MAXITEMS 400000


//-----------------------------------------------------------------------------

typedef struct
{
  int    prio;
  char*  data;
} ITEM;

typedef struct
{
  ITEM items[MAXITEMS];
  int next[MAXITEMS];
  int first;
  int free;
  int count;
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

// void getPrio( PQ *pq , ITEM *ITEM );
ITEM getPrio( PQ *pq );

//-----------------------------------------------------------------------------
// Pre:
// Post:   Prints the first 10 items of the priority array and the next array.
// Return:
//-----------------------------------------------------------------------------

void report( PQ *pq );
