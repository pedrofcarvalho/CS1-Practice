#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct CartPoint
{
  int x;
  int y;
} CartPoint;

CartPoint * createPoints(int numPoints);

int main()
{
  srand(time(0));

  CartPoint * arr = createPoints(5);

  for (int i = 0; i < 5; i++)
  {
    printf("x of index %d is: %d", i, arr[i].x);
    printf("\n");
    printf("y of index %d is: %d", i, arr[i].y);
    printf("\n\n");
  }


  return 0;
}



/* Question 1:
  Suppose we have an array of structures containing information about Cartesian points. The
  struct shown below contains two integers, one for the x coordinate and one for the y coordinate.
  For this problem, write a function, createPoints, to create some random Cartesian points with
  each coordinate set to a random integer in between 0 and 10, inclusive.
  createPoints takes in the number of points to be created, numPoints. Your function should
  dynamically allocate an array of numPoints CartPoints structs and set each of their x and y
  coordinates with pseudorandom integer values in between 0 to 10, inclusive. You may assume
  that the random number generator has been seeded already. Your function should return a pointer
  to the array that was created and initialized. (Foundation Exam May 18, 2019)
*/
typedef struct CartPoint
{
  int x;
  int y;
} CartPoint;

// allocate numPoints of memory and return that array
// each element created must be set a random number from 0 - 10, inclusive
CartPoint * createPoints(int numPoints)
{
  int i;
  CartPoint * ret = calloc(numPoints, sizeof(CartPoint));

  for (i = 0; i < numPoints; i++)
  {
    ret[i].x = (rand() % 11);
    ret[i].y = (rand() % 11);
  }

  return ret;
}


// ------------------------------------------------------------------------------------------------------------------------------------------------ //


/*
  Question 2
  Suppose we have a queue implemented as a doubly linked list using the structures shown
  below with head pointing to node at the front of the queue and tail pointing to the node at the end
  of the queue. (FE May 18, 2019)
*/

  typedef struct node
  {
   int data;
   struct node *next, *prev;
  } node;

  typedef struct queue
  {
   int size;
   node *head, *tail;
  } queue;

/*
  Write an enqueue function for this queue. If the queue is already full, return 0 and take no other
  action. If the queue has not been created yet, return 0 and take no other action. If the queue isn’t
  full, enqueue the integer item into the queue, make the necessary adjustments, and return 1. Since
  there is no fixed size, the queue will be considered full if a new node can’t be allocated.
*/

int enqueue(queue *thisQ, int item)
{
  // if queue had not been created, return 0
  if (!thisQ)
  {
    return 0;
  }

  // allocte memory for new node
  node * newNode = calloc(1, sizeof(node));

  // if queue is full / we can't allocate for new node, return 0
  if (newNode == NULL)
  {
    return 0;
  }

  newNode->data = item;
  newNode->next = NULL;
  newNode->prev = NULL;
  thisQ->size++;

  // if queue is empty, create it and return 1
  if (!thisQ->head == NULL && thisQ->tail == NULL)
  {
    thisQ->head = thisQ->tail = newNode;
    return 1;
  }

  // enqueue process
  thisQ->tail->next = newNode;
  newNode->prev = thisQ->tail;
  thisQ->tail = newNode;

  return 1;
}


/*
  Question 5
  Write an insertion function for a trie defined by the struct below. The function will take in the
  root of the trie and a string and will return the root of the node. Note: the only valid characters
  allowed in the string are alphabetical one (letters, a-z, A-Z), so check for this.
  */
  typedef struct TrieNode
  {
    struct TrieNode *children[26];
    int flag; // Asserted (1) if string present, deasserted (0) otherwise
  } TrieNode;

TrieNode * insert(TrieNode *root, char *str)
{
  // if the list is empty, create from scratch
  if (root == NULL)
  {

  }

  int index, length = strlen(str), i, j;

  for (i = 0; i < length; ++i)
  {
    // gets the index we will be using from the letter of each iteration
    index = str[i] - 'a';

    // if that index is empty (most of the time will)
    // if yes, create memory and set everything to NULL afterwards
    if (root->children[index] == NULL)
    {
      // create memory
      root->children[index] = calloc(1, sizeof(TrieNode));
      root->children[index]->flag = 0;

      // set everything inside that new level to NULL
      for (j = 0; j < 26; j++)
      {
        root->children[index]->children[j] = NULL;
      }
    }

    
  }

}



















//
