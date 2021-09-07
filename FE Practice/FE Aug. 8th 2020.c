


// Question 1

#include <string.h>
#include <stdlib.h>

struct juice_case 
{
  char name[128];
  int num_bottles;
};

struct juice_case* create_case(char * new_name, int new_number) 
{
  struct juice_case * ret = calloc(1, sizeof(struct juice_case));
  
  strcmp(str->name, new_name);
  
  ret->num_bottles = new_number;
  
  return ret;
}
















// Question 2
typedef struct node 
{
  int data;
  struct node* next;
} node;


node * addValue3(node* head) 
{
  if (head == NULL || head->data > 3) 
  {
    // tmp becomes new head
    
    node* tmp = malloc(sizeof(node));
    tmp->data = 3;
    tmp->next = head;
    return tmp;
  }
  
  if (head->data == 3)
    return head;
 
  node* iter = head;
 
  // loop until find the last node or a node with data = 3
  while (iter->next != NULL && iter->data != 3)
    iter = iter->next;
 
  if (iter->data == 3 && _____________________)
    return head;
 
  node* tmp = malloc(sizeof(node));
  tmp->data = 3;
 
  tmp->next = iter->next;
  
  iter->next = tmp;
  
  return head;
}



// Question 3

typedef struct node 
{
  int num;
  struct node* next;
} node;

typedef struct stack 
{
  struct node *top;
  int size;
} stack;


// Returns the value stored at the top of the stack pointed to by s. If stack pointed to by s is empty, a
// random value is returned.
int peek(stack *s);
// Returns 1 if the stack pointed to by s is empty, and 0 otherwise.
int isEmpty(stack *s);

                    // stack * towers
void printValidMoves(stack towers[], int numTowers) 
{                     
  for (int i = 0; i < numTowers; i++) 
  {
    for (int j = 0; j < numTowers; j++) 
    {
      if ( _________________________ ) continue;
      
      if ( ____________ || _________________________________ )
        printf("Valid move from tower %d to tower %d.\n", i, j);
    }
  }
}


























//
