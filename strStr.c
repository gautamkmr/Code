#include<stdio.h>

char* strStr(char *str, char *target)
{
   if(!*target)  return str;
  
   char *p1, *p2, *p1Begin, *p1Adv;
   p1 = str;
   p2 = target;
   p1Adv = str;
   while(*p2)
   {
     p2++;
     p1Adv++;
   }
   p2 = str;
   while(*p1Adv)
   {
     p1Begin = p1;
     p2 = target;
     while(*p1==*p2)
     { 
       p1++;
       p2++;
     }
     if(!(*p2))
       return p1Begin;
     p1 = p1Begin+1;
     p1Adv++;
   }
  return NULL;
}

int main()
{

  char str[] = "I love my india very much";
  char target[] = "india";
  if(strStr(str, target))
   printf("%s \n",strStr(str,target)); 
  else
   printf("Target not found !!!\n");
  return 0;
}
