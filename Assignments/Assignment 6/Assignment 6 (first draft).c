#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BSTNode BSTNode;

struct BSTNode
{
  int skillVictor;
  int tableNum;
  BSTNode * right;
  BSTNode * left;
};

// functions
BSTNode * insertNode(BSTNode * root, int tableNum);
BSTNode * createNode(int tableNum);
void simulate(BSTNode * current, int * skillArray);
int greaterVal(int left, int right);

// global variables
long long int excitement = 0;   // variable for excitement
int position = 0;               // variable for skillArray index

int main()
{
  // variable declaration
  BSTNode * root = NULL;
  int numPlayers, numTables, i, j, position = 0;

  // scann the number of players (n)
  scanf("%d", &numPlayers);
  numTables = numPlayers - 1; // (n- 1)

  if (numPlayers == 0)
  {
    printf("\nExcitement is: %lld\n", excitement);
    return 0;
  }

  int * tableOrder = calloc(numTables, sizeof(int));
  int * playerSkills = calloc(numPlayers, sizeof(int));

  // inserting input for tables
  for(i = 0; i < numTables; ++i)
  {
    scanf("%d", &tableOrder[i]);
  }
  printf("\n");

  // inserting input for player skills array
  for(i = 0; i < numPlayers; ++i)
  {
    scanf("%d", &playerSkills[i]);
  }
  printf("\n");

  // inverse for loop - creates the tree
  for (i = numTables - 1; i >= 0; --i)
  {
    root = insertNode(root, tableOrder[i]);
  }

  // calls simulate function
  simulate(root, playerSkills);

  // prints the excitement value
  printf("\nExcitement is: %lld\n", excitement);

  return 0;
}

// creates a node
BSTNode * createNode(int tableNum)
{
  BSTNode * ret = calloc(1, sizeof(BSTNode));

  ret->tableNum = tableNum;
  ret->right = NULL;
  ret->left = NULL;

  return ret;
}


// inserts node into the tree
BSTNode * insertNode(BSTNode * root, int tableNum)
{
  // if tree is empty OR gets to an empty spot, add node
  if (root == NULL)
  {
    return createNode(tableNum);
  }

  if (tableNum < root->tableNum)
  {
    root->left = insertNode(root->left, tableNum);
  }

  else if (tableNum > root->tableNum)
  {
    root->right = insertNode(root->right, tableNum);
  }

  return root;
}

// this function traverse the tree in a post-order fashion and calculates the excitement
void simulate(BSTNode * current, int * skillArray)
{
  // base case - checks for null nodes
  if(current == NULL)
  {
    position++;
    return;
  }

  // variables that will hold left and right player skill
  int leftSkill, rightSkill;

  // sets left skill for this function call to the next skillArray element
  if (current->left == NULL)
  {
    // set the left skill to the next skillArray element
    leftSkill = skillArray[position];
  }

  // traverse to the left
  simulate(current->left, skillArray);

  // sets right skill for this function call to the next skillArray element
  if (current->right == NULL)
  {
    // set the right skill to the next skillArray element
    rightSkill = skillArray[position];
  }

  // traverse to the right
  simulate(current->right, skillArray);

  // if left of curr node is NULL
  if (current->left == NULL)
  {
    // if both left and right of curr node is NULL
    if(current->right == NULL)
    {
      current->skillVictor = greaterVal(leftSkill, rightSkill); // sets current node's skillVictor to greatest value
      excitement += abs(leftSkill - rightSkill); // perform calculation
      return;
    }
    // if right is NOT NULL and left is NULL
    rightSkill = current->right->skillVictor; // gets the value from right skillVictor
    current->skillVictor = greaterVal(leftSkill, rightSkill); // sets current node's skillVictor to greatest value
    excitement += abs(leftSkill - rightSkill); // perform calculation
    return;
  }

  else if (current->left != NULL) // if current left is not NULL
  {
    // if left is not NULL and right is NULL
    if(current->right == NULL)
    {
      leftSkill = current->left->skillVictor; // gets the value from left skillVictor
      current->skillVictor = greaterVal(leftSkill, rightSkill); // sets current node's skillVictor to greatest value
      excitement += abs(leftSkill - rightSkill);  // perform calculation
      return;
    }

    else // if both left and right are NOT NULL
    {
      leftSkill = current->left->skillVictor; // gets the value from left skillVictor
      rightSkill = current->right->skillVictor; // gets the value from right skillVictor
      current->skillVictor = greaterVal(leftSkill, rightSkill); // sets current node's skillVictor to greatest value
      excitement += abs(leftSkill - rightSkill);  // perform calculation
      return;
    }
  }
  return;
}

// returns greater value
int greaterVal(int left, int right)
{
  if (left > right)
  {
    return left;
  }
  return right;
}





















//
