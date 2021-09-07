#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Big Oh's: (for doubly linked lists, with head and tail)
- add to end:   O(1)
- add to head:  O(1)
- remove head   O(1)
- remove tail   O(1)    // to remove the last node, we want to have access to the 2nd to last node

*/


typedef struct Node Node;
typedef struct List List;

// Node struct
struct Node
{
  int data;
  Node * prev;  // holds
  Node * next;
};

// doubly linked list (with head and tail)
// doubly linked list means it keeps a pointer for prev and next
// struct to hold head and tail
// struct name: wrapper struct
struct List
{
  // storing the first and last node
  // makes accessing last element easier and faster (prevent traversing the whole list)
  Node * head;
  Node * tail;
};

Node * createNode(int value);
void addToHead(int value, List * listy);
void addToTail(int value, List * listy);
void printList(Node * head);

int main()
{
  // create list
  List * listy = calloc(1, sizeof(List));
  listy->head = listy->tail = NULL;   // same as spaced out 'equal to' line

  int valueHead = 56;
  //int valueTail = 13;

  // create node
  listy->head = createNode(valueHead);
  listy->tail = listy->head;

  addToHead(49, listy);
  addToHead(1, listy);
  addToHead(798, listy);
  addToTail(1234, listy);

  printList(listy->head);



  return 0;
}



Node * createNode(int value)
{
  Node * ret = calloc(1, sizeof(Node));

  ret->data = value;
  ret->next = ret->prev = NULL;

  return ret;
}

void addToTail(int value, List * listy)
{
  // if the list is empty
  if (listy->head == NULL)
  {
    Node * newNode = createNode(value);
    listy->head = listy->tail = newNode;
    return;
  }

  // if list is NOT empty
  Node * newNode = createNode(value);
  listy->tail->next = newNode;
  newNode->prev = listy->tail;
  listy->tail = newNode;

  return;
}




void addToHead(int value, List * listy)
{
  // check if list is empty
  if (listy->head == NULL)
  {
    // at this point, the list will have only one element
    listy->head = createNode(value);
    listy->tail = listy->head;
    return;
  }

  Node * temp = createNode(value);

  temp->next = listy->head;
  listy->head = temp;
  temp = temp->next;
  temp->prev = listy->head;
  listy->head->prev = NULL;

  return;
}


void printList(Node * head)
{
  printf("[");
  while (head != NULL)
  {
    printf("%d ", head->data);
    head = head->next;
  }

  printf("]\n");
}





//
