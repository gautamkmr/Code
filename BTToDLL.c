// A simple inorder traversal based program to convert a Binary Tree to DLL
#include<stdio.h>
#include<stdlib.h>
 
// A tree node
struct node
{
    int data;
    struct node *left, *right;
};
 
// A utility function to create a new tree node
struct node *newNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = node->right = NULL;
    return(node);
}
 
// Standard Inorder traversal of tree
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("\t%d",root->data);
        inorder(root->right);
    }
}
 
// Changes left pointers to work as previous pointers in converted DLL
// The function simply does inorder traversal of Binary Tree and updates
// left pointer using previously visited node
void fixPrevPtr(struct node *root)
{
    static struct node *pre = NULL;
 
    if (root != NULL)
    {
        fixPrevPtr(root->left);
        root->left = pre;
        pre = root;
        fixPrevPtr(root->right);
    }
}
 
// Changes right pointers to work as next pointers in converted DLL
struct node *fixNextPtr(struct node *root)
{
    struct node *prev = NULL;
 
    // Find the right most node in BT or last node in DLL
    while (root && root->right != NULL)
        root = root->right;
 
    // Start from the rightmost node, traverse back using left pointers.
    // While traversing, change right pointer of nodes.
    while (root && root->left != NULL)
    {
        prev = root;
        root = root->left;
        root->right = prev;
    }
 
    // The leftmost node is head of linked list, return it
    return (root);
}
 
// The main function that converts BST to DLL and returns head of DLL
void BTToDLL(struct node *root, struct node **head, struct node **tail)
{
  if(root==NULL) return ;
  
  if(root->left)
    BTToDLL(root->left,head,tail);
 
  root->left = *tail; 

  if(*tail)
   (*tail)->right = root;
  else
    *head = root;

  *tail = root;

  if(root->right)
    BTToDLL(root->right,head,tail);
/*  // Set the previous pointer
    fixPrevPtr(root);
 
    // Set the next pointer and return head of DLL
    return fixNextPtr(root);
*/
}
 
// Traverses the DLL from left tor right
void printList(struct node *root)
{
    while (root != NULL)
    {
        printf("\t%d", root->data);
        root = root->right;
    }
}
 
// Driver program to test above functions
int main(void)
{
    // Let us create the tree shown in above diagram
    struct node *root = newNode(10);
    root->left        = newNode(12);
    root->right       = newNode(15);
    root->left->left  = newNode(25);
    root->left->right = newNode(30);
    root->right->left = newNode(36);
 
    printf("\n\t\tInorder Tree Traversal\n\n");
    inorder(root);
    struct node *head=NULL;
    struct node *tail=NULL;
    BTToDLL(root,&head,&tail);
 
    printf("\n\n\t\tDLL Traversal\n\n");
    printList(head);
    printf("\n");
    return 0;
}
