#include<stdio.h>   
#define bool int
#define true 1
#define false 0


    int reverse(int x) {
     bool isNegative = false;
     if(x<0)
      isNegative = true;
      
     int prod = 1;
     int rev=0;
     int tmp;    
     while(x)
     {
         rev = rev*10;
         tmp = x%10;
         rev +=tmp;
         x = x/10;
         printf("%d...\n",rev);   
  }
  //   printf("%d..\n",rev);
     if(isNegative == true)
      rev = rev *(-1);
     return rev; 
    }

int main()
{
  printf("%d\n",reverse(123));
  printf("%d\n",reverse(-1234));
  return 0;
} 
