#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node node;

struct node
{
  int data;
  node * next;
};

void doTheThing(node *head, node *current);
node * addToHead(node * head, int value);
node * createNode(int value);
void printList(node * head);

int main()
{
  node * head = createNode(4);
  head = addToHead(head, 9);
  head = addToHead(head, 5);
  head = addToHead(head, 4);

  printf("The list is:\n");
  printList(head);
  printf("\n");

  doTheThing(head, head);


  return 0;
}



void doTheThing (node *head, node *current)
{
  if (current == NULL)
    return;

  else if (current == head->next)
  {
    if (current->data == head->next->next->data)
      doTheThing (head, head->next->next->next);

    else if (current->data == head->next->next->data + 1)
      doTheThing (head, head->next->next->next->next);

    else if (current->data == head->next->next->data + 5)
      doTheThing (head, current->next->next->next);

    else if (current->data == head->next->next->data + 10)
      doTheThing (head, head->next);

    else
      doTheThing (head, current->next);
  }

  else
    doTheThing (head, current->next);
}


node * addToHead(node * head, int value)
{
  if (head == NULL)
  {
    return createNode(value);
  }

  node * newNode = createNode(value);
  newNode->next = head;

  return newNode;
}


node * createNode(int value)
{
  node * ret = calloc(1, sizeof(node));
  ret->data = value;
  ret->next = NULL;

  return ret;
}

void printList(node * head)
{
  if (head == NULL)
  {
    return;
  }
  
  printf("%d->", head->data);
  printList(head->next);
}















//
