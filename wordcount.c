#include<stdio.h>

//represent the state whether it is inside or outside of the state
#define OUT 0
#define IN  1
int countWords(char *str)
{
  char *tmp = str;
  int wc = 0;
  int STATE = OUT;
  while(*tmp)
  {

   if((*tmp==' ' || *tmp=='\n' || *tmp=='\b')  )
     STATE = OUT;
   else if(STATE == OUT)
   {
     wc++;
     STATE = IN;
   }
   tmp++;
  }
  return wc;
}

// Driver program to tes above functions
int main(void)
{
    char str[] = "One two          three\n  four\nfive  ";
    printf("No of words: %u\n", countWords(str));
    return 0;
}
