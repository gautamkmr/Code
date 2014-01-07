#include<stdio.h>
#include<stdlib.h>
#include<vector.h>

int bst(int n)
{
  if(n==0)  return 1;
  if(n==1 || n==2) return n;

  vector <int> a(n+1,0);   
  a[0] = 1;
  a[1] = 1;
  a[2] = 2;
  int i,j;

  for(i=3;i<=n;i++)
  {
    int res =0; 
    for(j=0;j<i;j++)
     res += a[j]*a[i-j-1]; 
  
    a[i] = res;
  }
  return a[n];
}


int main()
{

  while(1)
  {
   int n;
   scanf("%d",&n); 
   printf("number of binary search tree %d\n",bst(n)); 
  }  
  
 return 0;
}
  
 
