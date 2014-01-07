#include<stdio.h>   
int isdigit(int i)
{
 printf("%d ..............",i);
  if(i>=0 && i<=9)
    return 1;
 else 
  return -123;

}

int main()
{

  int i;
  for(i=0;i<=9;i++)
{
   int j;
   j = isdigit(i);  
    printf("%d is digit? %d\n",i,j);
}
/*  char ch;
  for(ch ='a';ch<='z';ch++)  
   printf("%c is digit? %d\n",ch,isdigit(ch)); 
*/ 
 return 0; 
}



 
