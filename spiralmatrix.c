#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;

    vector<vector<int> > generateMatrix(int n) {
        vector< vector<int> > vec(n, vector<int>(n));
int i,k,l;
k=0;   //starting row
l=0;   //starting column
int x=1;
int m=n;  //m rows
while(k<m && l<n)
{
  //assign on top row
  for(i=l;i<n;i++)
    vec[k][i] = x++;
  k++;

  //assign last column
  for(i=k;i<m;i++)
    vec[i][n-1]=x++; 
  n--;

  //assign at the bottom row
  if(k<m) {
    for(i=n-1; i>=l; i--)
      vec[m-1][i] = x++;
    m--;
  }
 
  //assign the leftmost column
  if(l<n) {
    for(i=m-1; i>=k; i--)
      vec[i][l] =x++;
    l++;
  }
 }
 return vec;
    }
void print( vector< vector<int> > m, int n)
{
   int i,j;
   for(i=0;i<n;i++)
   {
     for(j=0;j<n;j++)
       printf("%d ",m[i][j]);
     printf("\n");
   }
}

int main()
{
   while(1) {
   int n;
   scanf("%d",&n);    
   vector< vector<int> > vec =generateMatrix(n);
   print(vec,n);
   printf("****************************************************\n");
   }   
  return 0;
}















