#include<stdio.h>
#include<stdlib.h>
int main()
{
 int *ptr =  (int *)malloc(sizeof(int));
 int *tmp;
 ptr= NULL;
 free(tmp); 
 printf("Free successful\n");  
 return 0;
}
