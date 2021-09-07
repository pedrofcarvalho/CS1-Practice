#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LENGTH 20 + 1

// typedefs
typedef struct Node Node;
typedef struct PlayerStack PlayerStack;
typedef struct MVP MVP;

// Node struct
struct Node
{
  long int money;   // money amount for each player
  char * name;      // player name
  int nameSize;     // name length
  int MVP;          // MVP number at that moment in time
  Node * next;      // next Node pointer
};

// PlayerStack struct only contains the head inside it
struct PlayerStack
{
  Node * head;
};

// function protypes
Node * createPlayer(long int moneyAmount, char * name, int nameSize);
Node * addToHead(Node * head, char * name, long int money, int nameSize);
void destroyNode(Node * node);
Node * removeHead(Node * head);
void checkMVP(Node * head);
PlayerStack * createPlayerStack();
void pop(PlayerStack * players);
void push(PlayerStack * players, int money, char * name, int nameSize);
void freeStack(PlayerStack * stack);

int main()
{
  // variable declaration / initialization
  int decision, i, moneyAmount, nameSize;
  char * name = calloc(NAME_LENGTH, sizeof(char));

  // reads in input 't'
  scanf("%d", &decision);

  // creates Players PlayerStack
  PlayerStack * players = createPlayerStack();

  // loop while 't' is not 0
  while (decision != 0)
  {
    if (decision == 1)
    {
      scanf("%d", &moneyAmount);
      scanf("%s", name);
      nameSize = strlen(name);
      push(players, moneyAmount, name, nameSize);
    }

    else if (decision == 2)
    {
      pop(players);
    }

    else // if (decision == 3)
    {
      // checks for MVP and print it
      checkMVP(players->head);
    }

    // request for user input, regarding decision (t)
    scanf("%d", &decision);
  }

  // frees allocated memory
  freeStack(players);
  free(name);

  return 0;
}

// creates a player
Node * createPlayer(long int moneyAmount, char * name, int nameSize)
{
  Node * ret = calloc(1, sizeof(Node));

  // initialize values
  ret->money = moneyAmount;
  ret->name = calloc(nameSize, sizeof(char));
  strcpy(ret->name, name);
  ret->next = NULL;

  // return ret
  return ret;
}

// addToHead = add player to arcade
Node * addToHead(Node * head, char * name, long int newMoney, int nameSize)
{
  // if PlayerStack is empty
  if (head == NULL)
  {
    Node * newPlayer = createPlayer(newMoney, name, nameSize);
    newPlayer->MVP = newPlayer->money;

    return newPlayer;
  }

  // create new player and make new player become the head
  Node * newPlayer = createPlayer(newMoney, name, nameSize);
  newPlayer->next = head;

  // if the current MVP value is less than the new value, assign that value to Node's MVP
  if (head->MVP < newMoney)
  {
    newPlayer->MVP = newMoney;
  }

  // otherwise, assign the same value to
  else
  {
    newPlayer->MVP = head->MVP;
  }

  // return newPlayer
  return newPlayer;
}

// add player to the top of the stack
void push(PlayerStack * players, int money, char * name, int nameSize)
{
  Node * oldHead = players->head;
  Node * newPlayer = addToHead(players->head, name, money, nameSize);
  players->head = newPlayer;

  return;
}

// removes the head
Node * removeHead(Node * head)
{
  // checks if list is empty
  if (head == NULL)
  {
    printf("The list is empty!\n");
    return NULL;
  }

  Node * newHead = head->next;
  destroyNode(head);

  return newHead;
}

// (destroys) frees a node
void destroyNode(Node * node)
{
  // checks if list is empty
  if (node == NULL)
  {
    printf("Node already is empty\n");
    return;
  }

  // frees name
  free(node->name);

  // frees the head
  free(node);
}

// remove the player at the top of the stack
void pop(PlayerStack * players)
{
  Node * oldHead = players->head;
  Node * newHead = removeHead(oldHead); // removeHead returns the newHead
  players->head = newHead;

  return;
}

// create a PlayerStack
PlayerStack * createPlayerStack()
{
  PlayerStack * ret = calloc(1, sizeof(PlayerStack));
  ret->head = NULL;

  return ret;
}

// checks for MVP and prints name
void checkMVP(Node * head)  // head from normal PlayerStack (PlayerStack->head)
{
  int MVPAmount = head->MVP;

  while (head != NULL)
  {
    if (MVPAmount == head->money)
    {
      printf("%s\n", head->name);
      return;
    }
    head = head->next;
  }

  return;
}

// frees stack
void freeStack(PlayerStack * stack)
{
  // create two Node pointers
  Node * head = stack->head;
  Node * temp = head;

  // remove until head == NULL
  while (head != NULL)
  {
    removeHead(temp);
    head = head->next;
    temp = head;
  }

  // free stack
  free(stack);
}
