/*
 Wrong code doesn't print 0, try to fix it.
*/

#include<stdio.h>
void putlong(unsigned long n) {
  if (n == 0)
    return;
  putlong(n / 10);
  putchar(n % 10 + '0');
}
int main()
{

 unsigned long n = 7;
 putlong(n); 
 printf("\n");
 putlong(0); 
 return 0;
}
