// PART A
// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
  Question 2

  Suppose we have a singly linked list implemented with the structure below.

  Write a recursive function that takes in the list and returns 1 if the list is non-empty AND all of the numbers in the list are even, and
  returns 0 if the list is empty OR contains at least one odd integer.

  (For example, the function should return 0 for an empty list, 1 for a list that contains 2 only, and 0 for a list that contains 3 only.)

*/

struct node
{
  int data;
  struct node* next;
};

// 0 bad, 1 = good
int check_all_even(struct node *head)
{
  // check if empty
  if (head == NULL)
  {
    return 0;
  }
  
  // check if the last node is even
  if (head->data % 2 == 0 && head->next == NULL)
  {
    return 1;
  }
  
  // if odd
  if (head->data % 2 != 0)
  {
    return 0;
  }
  

  return check_all_even(head->next);
}



/*
  Question 3

  Consider the circular array implementation of a queue named Q, implemented with the structure shown
  below.
  struct queue {
   int *array;
   int num_elements;
   int front;
   int capacity;
  };
  
  Suppose the queue is created with a capacity of 5 and front and num_elements are initialzed to 0. Trace
  the status of the queue by showing the valid elements in the queue and the position of front after each of
  the operations shown below. Indicate front by making bold the element at the front of the queue

*/


// PART B
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/* 
  Question 1
  
  Write a function named find_below() that takes a pointer to the root of a binary tree (root) and an integer
  value (val) and returns the greatest value in the tree that is strictly less than val. If no such value exists,
  simply return val itself. Note that the tree passed to your function will not necessarily be a binary search
  tree; it’s just a regular binary tree.
  
  You must write your solution in a single function. You cannot write any helper functions.
  The function signature and node struct are given below.

*/
typedef struct node
{
  int data;
  struct node *left;
  struct node *right;
} node;

int find_below(node *root, int val)
{
  if (root == NULL)
  {
    return val;
  }
  
  int left = find_below(root->left, val);
  int right = find_below(root->right, val);
  
  // if both left and right are NULL, then they are equal to val and we return the curr node data
  if (left == val && right == val)
  {
    return root->data;
  }
  
  // if left is = val, but right is not
  if (left == val && right != val)
  {
    if (root->data > right)
    {
      return root->data;
    }
    
    else
    {
      return right;
    }
  }
  
  // if right is = val, but left is not
  else if (right == val && left != val)
  {
    if (root->data > left)
    {
      return root->data;
    }
    
    else
    {
      return left;
    }
  }
  
  // if both right and left are not val
  else
  {
    if (root->data > right && root->data > left)
    {
      return root->data;
    }
    
    else if (left > root->data && left > right)
    {
      return left;
    }
    
    else 
    {
      return right;
    }
  }
}

  /*
  Question 3 
  
  Write a function that takes the root of a trie (root) and returns the number of strings in that trie that end
  with the letter q. The count member of the node struct indicates how many occurrences of a particular
  string have been inserted into the trie. So, a string can be represented in the trie multiple times. If a string
  ending in q occurs multiple times in the trie, all occurrences of that string should be included in the value
  returned by this function.
  The node struct and function signature are given below. You must write your solution in a single function.
  You cannot write any helper functions.

  */
  
typedef struct TrieNode
{
  // pointers to the child nodes (26 total).
  struct TrieNode *children[26];
  
  // indicates how many occurrences of a particular string are contained
  // in this trie. If none, this is set to zero (0).
  int count;
  
} TrieNode;

int ends_with_q_count(TrieNode * root)
{
  // if root is empty
  if (root == NULL)
  {
    return 0;
  }
  
  // set the index to find 'q'
  int index = 'q' - 'a';
  int sum = 0;
  
  for (int i = 0; i < 26; i++)
  {
    
    if (root->children[index] == NULL)
    {
      return 0;
    }
  }
}













// Spring 2017 

typedef struct node
{ 
  struct node * left, * right;
  char word[20];
} bsNode;

int countBefore (bsNode * root, char target[])
{
  if (root == NULL)
  {
    return 0;
  }
  
  int count = 0, targetIndex = target[0];
  
  if (root->left != NULL && root->left->word[0] < target[0])
  {
    count += countBefore(root->left, target)
  }
  
  if (root->right != NULL && root->right->word[0] < target[0])
  {
    count += countBefore(root->right, target)
  }
  
  if (root->word[0] < target[0])
  {
    count++;
  }
  
  return count;
}










typedef struct nodes
{
  int data;
  struct node * next;
  
} node;

int listyList(Node * head)
{
  if (head == NULL)
  {
    return 0;
  }
  
  int sum = 0, temp = 0;
  temp = listyList(head->next);
  sum = temp + head->data;
  
  if (temp == head->data || temp == -1)
  {
    return -1;
  }
  
  return sum;
  
}






















//
