#include<stdio.h>
int noOfSetBits(int n)
{
  int c=0;
  while(n)
  {
    c++;
    n = n&(n-1);
  }
  return c;
}

void printBinary(int n)
{
  if(n==0)
   return ;
 
  printBinary(n/2);
  
  printf("%d",n%2);
}

int main()
{
  int n;
  while(1) {
  scanf("%d",&n);
  printBinary(n);
  printf("\n");
  printf("No of set Bits %d\n",noOfSetBits(n));
  }
 
  return 0;
}
