#include <stdio.h>
#include <stdlib.h>

#define MAX 20

//#define USE_REC

typedef struct Node Node;

struct Node {
  Node * next;
  int data;
};

Node * insertFront(Node*, int);
Node * removeAll(int, Node*);
void print(Node *);
Node * newNode(int);

int main(void) {
  Node * head = NULL;

  head = insertFront(head, 9);
  head = insertFront(head, 4);
  head = insertFront(head, 3);
  head = insertFront(head, 4);
  head = insertFront(head, 7);
  head = insertFront(head, 6);
  head = insertFront(head, 8);

  print(head);
  removeAll(4, head);
  print(head);

  // for(int i = 0; i <= MAX; i++)
  // {
  //   print(head);
  //   head = removeAll(i, head);
  // }

  return 0;
}

Node * insertFront(Node * head, int val)
{
  Node * newHead = newNode(val);
  newHead->next = head;
  return newHead;
}

Node * removeAll(int val, Node * head)
{
  printf("hi\n");
  if(head == NULL)
  {
    return NULL;
  }

  if(head->data == val)
  {
    Node * newHead = removeAll(val, head->next);
    free(head);
    return newHead;
  }
  head->next = removeAll(val, head->next);
  return head;
}

/*

Node * removeAll(int val, Node * head)
{
  Node * newHead = head;
  Node * prevNode;
  Node * tmp;

  while(newHead != NULL && newHead->data == val)
  {
    tmp = newHead;
    newHead = newHead->next;
    free(tmp);
  }

  prevNode = newHead;
  while(prevNode != NULL && prevNode->next != NULL)
  {
    if (prevNode->next->data == val)
    {
      tmp = prevNode->next;
      prevNode->next = tmp->next;
      free(prevNode->next);
    }
    else
    {
      prevNode = prevNode->next;
    }
  }
  return newHead;
}
*/

void print(Node * head)
{
  if(head == NULL)
  {
    printf("NULL\n");
    return;
  }
  printf("%d -> ", head->data);
  print(head->next);
}
Node * newNode(int data)
{
  Node * ret;
  ret = calloc(1, sizeof(Node));
  ret->next = NULL;
  ret->data = data;
  return ret;
}
