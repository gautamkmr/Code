#include<stdio.h>
#include<stdlib.h>
  
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
   int data;
   struct node* left;
   struct node* right;
};
 
/* Prototypes for funtions needed in printPaths() */
void printPathsRecur(struct node* node, int path[], int pathLen,int *sum);
void printArray(int ints[], int len, int *sum);
 
/*Given a binary tree, print out all of its root-to-leaf
 paths, one per line. Uses a recursive helper to do the work.*/
void printPaths(struct node* node, int *sum)
{
  int path[1000];
  printPathsRecur(node, path, 0,sum);
}
 
/* Recursive helper function -- given a node, and an array containing
 the path from the root node up to but not including this node,
 print out all the root-leaf paths.*/
void printPathsRecur(struct node* node, int path[], int pathLen, int *sum)
{
  if (node==NULL)
    return;
 
  /* append this node to the path array */
  path[pathLen] = node->data;
  pathLen++;
 
  /* it's a leaf, so print the path that led to here  */
  if (node->left==NULL && node->right==NULL)
  {
    printArray(path, pathLen,sum);
  }
  else
  {
    /* otherwise try both subtrees */
    printPathsRecur(node->left, path, pathLen,sum);
    printPathsRecur(node->right, path, pathLen,sum);
  }
}
 
 
/* UTILITY FUNCTIONS */
/* Utility that prints out an array on a line. */
void printArray(int ints[], int len, int *sum)
{
  int i;
  int res=0;
  for (i=0; i<len; i++)
  {
    res = res*10 + ints[i];
    printf("%d ", ints[i]);
  }
  *sum = *sum + res;
  printf("\n");
}   
 
/* utility that allocates a new node with the
   given data and NULL left and right pointers. */  
struct node* newnode(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  
  return(node);
}
  
int Sum(struct node *root, int sum)
{
   if(root==NULL) 
    return 0;
   
   sum = sum *10 + root->data;
   if(root->left == NULL && root->right==NULL)
    return sum;
   else
    return Sum(root->left, sum) + Sum(root->right, sum);

}
/* Driver program to test above functions*/
int main()
{
  
  /* Constructed binary tree is
            10
          /   \
        8      2
      /  \    /
    3     5  2
  */
  struct node *root = newnode(10);
  root->left        = newnode(8);
  root->right       = newnode(2);
  root->left->left  = newnode(3);
  root->left->right = newnode(5);
  root->right->left = newnode(2);
  int sum=0;
  printPaths(root, &sum);
  printf("Total Sum is %d\n",sum);
  printf("Total sum is %d\n",Sum(root, 0));
  getchar();
  return 0;
}
