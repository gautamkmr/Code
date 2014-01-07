#include<stdio.h>
int main()
{

int x;  // we want to find the minimum of x and y
int y;   
int r;  // the result goes here 

x = 3;
y = 6;

r = y ^ ((x ^ y) & -(x < y)); // min(x, y)

printf("%d",-(x<y));

return 0;
}


