#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BSTNode BSTNode;

struct BSTNode
{
  int data;
  BSTNode * right;
  BSTNode * left;
  BSTNode * parent;
};

BSTNode * createNode(int value);
BSTNode * insertNode(BSTNode * root, int value);
void invertTree(BSTNode * root);
void preOrder(BSTNode * root);

int main()
{
  int inputSize, i;

  BSTNode * root = NULL;
  scanf("%d", &inputSize);

  int * input = calloc(inputSize, sizeof(int));

  for (i = 0; i < inputSize; ++i)
  {
    scanf("%d", &input[i]);
    root = insertNode(root, input[i]);
  }

  invertTree(root);
  preOrder(root);
  printf("\n");

  return 0;
}

BSTNode * createNode(int value)
{
  BSTNode * ret = calloc(1, sizeof(BSTNode));
  ret->data = value;
  ret->right = NULL;
  ret->left = NULL;
  ret->parent = NULL;

  return ret;
}


BSTNode * insertNode(BSTNode * root, int value)
{
  // base case
  if (root == NULL)
  {
    return createNode(value);
  }

  if (value < root->data)
  {
    root->left = insertNode(root->left, value);
  }

  if (value > root->data)
  {
    root->right = insertNode(root->right, value);
  }

  return root;
}

// inverts tree
void invertTree(BSTNode * root)
{
  if (root == NULL)
  {
    return;
  }

  invertTree(root->left);
  invertTree(root->right);

  if(root->left != NULL && root->right != NULL)
  {
    BSTNode * temp;
    BSTNode * temp2;
    temp = root->right;
    root->right = root->left;
    root->left = temp;
  }

  return;
}


void preOrder(BSTNode * root)
{
  if (root == NULL)
  {
    return;
  }

  printf("%d-> ", root->data);
  preOrder(root->left);
  preOrder(root->right);
}













//
