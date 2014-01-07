#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void computeLps(char *patt, int n, int *lps)
{
   int len=0;
   lps[0] = 0;
   int i=1;
   while(i<n)
   {
      if(patt[i] == patt[len])
      {
         len++;
         lps[i] = len;
         i++;
      }
      else
      {
        if(len!=0)
          len = lps[len-1];
        else
        {
          lps[i] = 0;
          i++;
        }
      }
    }
}

void kmp(char *text, char *patt)
{
   int m = strlen(text);
   int n = strlen(patt);
   
   int *lps = (int *)malloc(sizeof(n+1));

   computeLps(patt, n, lps);
   
   int i=0,j=0;
   while(i<m)
   {
     if(text[i] == patt[j])
     {
       i++;
       j++;
     }
     if(j==n)  // pattern matched
     {
        printf("Match found at %d %s\n",i-j, (text+ i-j));
     }
     else if(text[i] != patt[j]) 
     {
       if(j!=0)  //we have hope to match more from the lps 
        j = lps[j-1];
       else    //there won't be any match so move on 
        i++; 
     }
   }
   free(lps);
}
int main()
{
  char text[] = "i love my india";
  char patt[] = "india";
  
  kmp(text,patt);
  return 0;
}
