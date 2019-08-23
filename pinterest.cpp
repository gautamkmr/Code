/*
# Given a binary tree, find the length of the longest increasing sequence (where each node is followed by one of its children) of nodes.

         4   
        / 
       2  
      / 
     3     
    / 
   5    
  /     
 1
 
 BFS 
 h = height of tree
 1
 2
 4
 8
 16 
 
 2^(5-1) at level 5
 
 at level h 2^(h-1) nodes 

n = number of nodes 


worst case spacce O(n)
general case O(depeth) 


         4   
        / \
       2   2 
      / \
     3  1   
    / 
   5    
  / \    
  1  3    
  
  
  1,5,3,3,2,1,4,2
  

        4  (0,0)  
        / \
(0,0)  2   2 
      / \
(1,1)3   1   
    / 
   5 (2,2)    
  / \    
 1   3
(0,2) (0,2)


// 

*/

#include <iostream>
using namespace std;

struct TreeNode
{
   int val;
   struct TreeNode *left;
   struct TreeNode *right;
};

struct TreeNode* getNode(int val)
{
   struct TreeNode *r = new TreeNode();
   r->val = val;
   r->left = r->right = NULL;
   return r;
}

void get(TreeNode *r, int currLen, int &maxLen)
{
 
   if(!r)
     return;
   
   if(r->left==NULL && r->right == NULL)
   {
     maxLen = max(currLen, maxLen);
     return;
   }
  
   if(r->left)
   {
     if(r->left->val > r->val)
      {
        currLen += 1;
        maxLen = max(currLen, maxLen);
        get(r->left, currLen, maxLen);
      }
     else
     {
         get(r->left, 0, maxLen); 
     }
   }
   if(r->right)
   {
      if(r->right->val > r->val)
      {
        currLen += 1;
        maxLen = max(currLen, maxLen);
        get(r->right, currLen, maxLen);
      }
     else
     {
        get(r->right, 0, maxLen); 
     }
   } 
}

int MaximumLength(TreeNode *r)
{
   if(!r)
      return 0;
   int currLen = 0;
   int MaxLen = 0;
  
   get(r, currLen, MaxLen);
   return MaxLen + 1;
}

// To execute C++, please define "int main()"
/*
         4   
        / \
       2   2 
      / \
     3  1   
    / 
   5    
  / \    
  1  3    
*/
int main() {
  struct TreeNode *r = getNode(4);
  //cout<<MaximumLength(r)<<"\n";
  
  r->left = getNode(2);
  r->right = getNode(2);
  r->left->left = getNode(3);
  r->left->right = getNode(1);
  r->left->left->left = getNode(5);
  r->left->left->left->left = getNode(1);
  r->left->left->left->right = getNode(3);

  cout<<MaximumLength(r)<<"\n";
  
  // r->right = getNode(2);
  
  
  return 0;
}

