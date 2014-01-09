#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include<iostream>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
 
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct node* newNode(int data)
{
  struct node* node = (struct node*)
                      malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
 
  return(node);
}

/* returns -1 if the tree is not bst otherwise returns size of largest bst.*/
int largestBSTUtil(struct node* p, int &min, int &max,
                            int &max_size, struct node *&largestBST)
{
 
  /* Base Case */
  if (p == NULL)
  {
     return 0;    // Size of the BST is 0
  }
  bool isbst = true; 
  int left = largestBSTUtil(p->left,min,max,max_size,largestBST);
  int currmin = (left==0) ? p->data:min;
  if(left==-1 || (left!=0 && p->data < max))
   isbst = false; 
 
  int right = largestBSTUtil(p->right,min,max,max_size,largestBST);
  int currmax = (right==0) ? p->data:max;
  if(right==-1 || (right!=0 && p->data > min))
   isbst = false; 
 
  if(isbst)
  {
     min = currmin;
     max = currmax;
     int totalnodes = left + right + 1;
     if(totalnodes > max_size) {
        max_size = totalnodes;
         largestBST = p;
      }   
   return totalnodes;
  }
  else 
    return -1;
}
 
int findLargestBSTSubtree(struct node *p, int &min, int &max,
                   int &maxNodes, struct node *& largestBST) {
  if (!p) return 0;
  bool isBST = true;
  int leftNodes = findLargestBSTSubtree(p->left, min, max, maxNodes, largestBST);
  int currMin = (leftNodes == 0) ? p->data : min;
  if (leftNodes == -1 ||
     (leftNodes != 0 && p->data <= max))
    isBST = false;
  int rightNodes = findLargestBSTSubtree(p->right, min, max, maxNodes, largestBST);
  int currMax = (rightNodes == 0) ? p->data : max;
  if (rightNodes == -1 ||
     (rightNodes != 0 && p->data >= min))
    isBST = false;
  if (isBST) {
    min = currMin;
    max = currMax;
    int totalNodes = leftNodes + rightNodes + 1;
    if (totalNodes > maxNodes) {
      maxNodes = totalNodes;
      largestBST = p;
    }
    return totalNodes;
  } else {
    return -1;   // This subtree is not a BST
  }
}
 
struct node * findLargestBSTSubtree(struct node *root) {
  struct node *largestBST = NULL;
  int min = INT_MIN, max =INT_MAX;
  int maxNodes = INT_MIN;
  largestBSTUtil(root, min, max, maxNodes, largestBST);
  //findLargestBSTSubtree(root, min, max, maxNodes, largestBST);
  printf("Size of largest BST %d\n", maxNodes);
  return largestBST;
}
/* Driver program to test above functions*/
int main()
{
    /* Let us construct the following Tree
          50
       /      \
     10        60
    /  \       /  \
   5   20    55    70
            /     /  \
          45     65    80
  */
 
  struct node *root = newNode(50);
  root->left        = newNode(10);
  root->right       = newNode(60);
  root->left->left  = newNode(5);
  root->left->right = newNode(20);
  root->right->left  = newNode(55);
  root->right->left->left  = newNode(45);
  root->right->right = newNode(70);
  root->right->right->left = newNode(65);
  root->right->right->right = newNode(80);
 
  /* The complete tree is not BST as 45 is in right subtree of 50.
     The following subtree is the largest BST
        60
      /  \
    55    70
   /     /  \
  5     65    80
  */
  printf(" Size of the largest BST is %d", (findLargestBSTSubtree(root))->data);
 
  getchar();
  return 0;
}
