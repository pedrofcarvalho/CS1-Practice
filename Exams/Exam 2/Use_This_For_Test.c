#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct DNode DNode;
typedef struct DoubLL DoubLL;

struct DNode
{
   int data;
   DNode * next, * prev;
};

struct DoubLL
{
   DNode * head;
   DNode * tail;
};

void printList(DoubLL * list);
DNode * createNode(int value);
void insertHead(DoubLL * list, int value); // Create this function


int main()
{
  int value = 5;
  DoubLL * list = calloc(1, sizeof(DoubLL));
  list->head = NULL;
  list->tail = NULL;

  insertHead(list, value);
  insertHead(list, 4);
  insertHead(list, 9);

  printList(list);
  printf("Your code worked if it showed 9: %d\n", list->head->next->prev->data);
  printf("\n");



  return 0;
}

DNode * createNode(int value)
{
  DNode * node = calloc(1, sizeof(DNode));

  node->data = value;
  node->next = NULL;
  node->prev = NULL;

  return node;
}

void insertHead(DoubLL * list, int value)
{
  // if list is empty
  if (list->head == NULL)
  {
    DNode * newHead = createNode(value);
    list->head = list->tail = newHead;
    return;
  }

  DNode * newHead = createNode(value);
  newHead->next = list->head;
  list->head->prev = newHead;
  list->head = newHead;

  return;
}

void printList(DoubLL * list)
{
  DNode * temp = list->head;
  while (temp != NULL)
  {
    printf("%d->", temp->data);
    temp = temp->next;
  }
}










/*

Code up inserting into the head of a non-circular, doubly, linked list using the below struct definition and function prototype.
You may assume that the create node function has been implemented.

struct DNode

{
   int data;
   DNode * next, * prev;

};

struct DoubLL {
   DNode * head;
   DNode * tail;
};
DNode * createNode(int value);

void insertHead(DoubLL * list, int value); // Create this function
*/
