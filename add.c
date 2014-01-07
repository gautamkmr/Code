#include<stdio.h>
int add(int x, int y)
{
 while(y)
 {
   int carry = x&y; 
   x = x^y; 
   y = carry<<1;
 }
 return x;
}

int main()
{

 printf("%d\n",add(4,3));   
 return 0;
} 
