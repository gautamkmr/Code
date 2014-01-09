#include<stdio.h>
#include<string.h>
#include<limits.h>

#define  bool int

bool minWindow(const char* s, const char *t,
               int &minWindowBegin, int &minWindowEnd)
{
  int slen = strlen(s);
  int tlen = strlen(t);
  int c = 0;
  int hasFound[256], needToFind[256];  
  int i;
  for(i=0;i<256;i++)
  {
    hasFound[i] = 0;
    needToFind[i] = 0;
  }
  for(i=0;i<slen;i++)
    needToFind[t[i]]++;
  int begin, end;
  int minWin = INT_MAX;
  for(begin=0, end=0; end<slen; end++)
  {
    //this character is not present in the pattern
    if(needToFind[s[end]]==0) continue;
    
    //got one
    hasFound[s[end]]++;
    //increase the counter only when it matters i.e. this character needs to be in window otherwise don't increase the counter
    if(hasFound[s[end]] <= needToFind[s[end]])
       c++;

    if(c==tlen)
    {
       //try to shrink the window by moving the begin pointer
       while(needToFind[s[begin]]==0 || hasFound[s[begin]] > needToFind[s[begin]])
        {
            if(hasFound[s[begin]] > needToFind[s[begin]])
              hasFound[s[begin]]--;

            begin++;
        }

        if(end - begin + 1 < minWin)
        {
           minWin = end - begin + 1;
           minWindowBegin = begin;
           minWindowEnd = end;
        }
     }
   }
   
   return c==tlen;
}



int main()
{
 char s[]="acbbaca";
 char t[]="aba";
 
 int start, end;
 if(minWindow(s, t, start, end))
  {
    printf("smallest window length is %d\n", end - start + 1);
    int i;
    for(i = start; i<=end; i++)
      printf("%c",s[i]);
    printf("\n");
  }
 else 
   printf("Window not present\n");
 return 0;
}

