#include<stdio.h>
#define OUT 0
#define IN  1

void removeSpace(char *str)
{
   int i,j;
   i = j =0;
   while(str[i]!='\0')
   {

     if(str[i]!=' ')
     { 
       str[j++] = str[i];
     }
     i++;
   }
   str[j] = '\0';
}
int wc(char *str)
{
  int state;
  state = OUT;
  int i,wc;
  i=0;
  wc = 0;
  while(str[i]!='\0')
  {
     if(str[i]==' ')
       state = OUT;
     else if(state == OUT)
     {
        wc++;
        state = IN;
     }
    i++;
  }
  return wc;
}
int main()
{
  char str[] ="   Gautam Kumar   I love my india            ";
  printf("%s  word count:  %d\n", str, wc(str));
  removeSpace(str);
  printf("%s  word count:  %d\n", str, wc(str));
  return 0;
}
