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
  long int money;
  char * name;
  int nameSize;
  int MVP;
  Node * next;
};

// PlayerStack struct only contains the head inside it
struct PlayerStack
{
  Node * head;
};

// function protypes
Node * createPlayer(long int moneyAmount, char * name, int nameSize);
Node * addToHead(Node * head, char * name, long int money, int nameSize);
void printList(Node * head);
void destroyNode(Node * node);
Node * removeHead(Node * head);
void checkMVP(Node * head);
// just allocates memory
PlayerStack * createPlayerStack();
// take out
void pop(PlayerStack * players);
// put in
void push(PlayerStack * players, int money, char * name, int nameSize);
void freeStack(PlayerStack * stack);


int main()
{
  int decision, i, moneyAmount, nameSize;
  char * name = calloc(NAME_LENGTH, sizeof(char));

  //printf("Input the value for \"t\" (1 = insert, 2 = remove, 3 = print, 0 = stop)\n");
  scanf("%d", &decision);

  // creates Players PlayerStack
  PlayerStack * players = createPlayerStack();

  while (decision != 0)
  {
    if (decision == 1)
    {
      //printf("Amount of money for new player:\n");
      scanf("%d", &moneyAmount);
      //printf("New player name:\n");
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
    //printf("Input the value for \"t\" (1 = insert, 2 = remove, 3 = print, 0 = stop)\n");
    scanf("%d", &decision);
  }

  freeStack(players);
  free(name);

  return 0;
}

// creates a player
Node * createPlayer(long int moneyAmount, char * name, int nameSize)
{
  Node * ret = calloc(1, sizeof(Node));

  ret->money = moneyAmount;
  ret->name = calloc(nameSize, sizeof(char));
  strcpy(ret->name, name);
  ret->next = NULL;

  return ret;
}

// WORKS PERFECTLY FINE
// addToHead = add player to arcade
Node * addToHead(Node * head, char * name, long int newMoney, int nameSize)
{
  //int MVPAmount;

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

  if (head->MVP < newMoney)
  {
    newPlayer->MVP = newMoney;
  }

  else
  {
    newPlayer->MVP = head->MVP;
  }

  return newPlayer;
}

// add value to the top PlayerStack
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

// remove the top of the PlayerStack
void pop(PlayerStack * players)
{
  Node * oldHead = players->head;
  Node * newHead = removeHead(oldHead); // removeHead returns the newHead
  players->head = newHead;

  return;
}

// prints the list on the PlayerStack
void printList(Node * head)
{
  // checks if list empty
  if (head == NULL)
  {
    printf("List is empty");
    return;
  }

  // prints the list (if there are values on it)
  while(head != NULL)
  {
    //printf("%s, $%ld, MVP Amount = %d\n", head->name, head->money, head->MVP);
    head = head->next;
  }
}

// create a PlayerStack
PlayerStack * createPlayerStack()
{
  PlayerStack * ret = calloc(1, sizeof(PlayerStack));
  ret->head = NULL;

  return ret;
}


void checkMVP(Node * head) // head from normal PlayerStack (PlayerStack->head)
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

void freeStack(PlayerStack * stack)
{
  Node * head = stack->head;
  Node * temp = head;

  while (head != NULL)
  {
    removeHead(temp);
    head = head->next;
    temp = head;
  }

  free(stack);
}



















//
