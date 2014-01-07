#include <stdio.h>
int binarySearch(int low, int high); // prototype
 
// Let's take an example function as f(x) = x^2 - 10*x - 20
// Note that f(x) can be any monotonocally increasing function
int f(int x) { return (x*x - 10*x - 20); }
int findFirstPositive()
{

  if(f(0)>0)  return 0;
  

  int  i=1;
   
  while(f(i) < 0) 
   i = i*2; 

  return bst(i/2,i);
}

int bst(int low, int high)
{
  if(low<=high)
  {
    int m = (low + high)/2;
    if(f(m)>0 &&((m==low) || (f(m-1)<0)))
      return m;
    else if(f(m)>0)  return bst(low, m-1);
    else return bst(m+1,high);
  }
  return -1;
}


/* Driver program to check above functions */
int main()
{
    printf("The value n where f() becomes positive first is %d",
           findFirstPositive());
    return 0;
}
