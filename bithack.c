#include<stdio.h>
int main()
{
 int x = 110;
 printf("%d\n",x&-x);
 printf("%d\n",x&~(x-1));
 return 0;
}
