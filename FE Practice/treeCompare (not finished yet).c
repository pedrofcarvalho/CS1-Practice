#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
  int data;
  struct node * right;
  struct node * left;
};

struct node* newNode(int data);
int check(struct node * nodeA, struct node * nodeB);
// BSTNode * insertNode(BSTNode * root, int tableNum);
// BSTNode * createNode(int tableNum);

int main()
{
  struct node *root1 = newNode(1);
  struct node *root2 = newNode(1);
  root1->left = newNode(2);
  root1->right = newNode(3);
  root1->left->left  = newNode(4);
  root1->left->right = newNode(5);

  root2->left = newNode(2);
  root2->right = newNode(3);
  root2->left->left = newNode(4);
  root2->left->right = newNode(5);

  if(check(root1, root2) == 0)
    printf("Both tree are identical.\n");
   else
    printf("Trees are not identical.\n");

  return 0;
}

struct node* newNode(int data)
{
    struct node* node = (struct node*)
                             malloc(sizeof(struct node));
    node->data  = data;
    node->left  = NULL;
    node->right = NULL;

    return(node);
}

// Node * insert(Node * root, int value)
// {
//     if (root == NULL)
//     {
//       return createNode(value);
//     }
//
//     // Don't add duplicates (optional)
//     if (root->value == value)
//     {
//       return root;
//     }
//
//     // root is smaller than our target
//     if (root->value < value)
//     {
//       root->right = insert(root->right, value);
//     }
//
//     else
//     {
//       root->left = insert(root->left, value);
//     }
//
//     return root;
// }
//
// BSTNode * createNode(int tableNum)
// {
//   BSTNode * ret = calloc(1, sizeof(BSTNode));
//
//   ret->tableNum = tableNum;
//   ret->right = NULL;
//   ret->left = NULL;
//
//   return ret;
// }

// this has to be pre-order
int check(struct node * nodeA, struct node * nodeB)
{
  if (nodeA == NULL && nodeB == NULL)
  {
    return 0;
  }

  // 0 = good, 1 = bad

  if (nodeA->data != nodeB->data)
  {
    return 1;
  }

  return check(nodeA->left, nodeB->left) && check(nodeA->right, nodeB->right);

  return 0;

}
