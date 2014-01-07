/*
  unit length encoding
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_RLEN 50


char *encode(char *s)
{
 int len = strlen(s);
 int newlen = 2*len + 1;
 char *dest = (char *)malloc(newlen);
 char count[MAX_RLEN];
 int i=0;
 int j=0; 
 int k;
 int c;
 while(i<len)
 {
   dest[j++] = s[i++];
   c=1;
   while((i+1)<len && s[i]==s[i+1])
    {  c++; i++; }
  
  sprintf(count,"%d",c);
  for(k=0;count[k]!='\0';k++)
   dest[j++] = count[k];
 }
 dest[j] = '\0';
 return dest;
}

int main()
{
  char str[] = "geeksforgeeks";   
  char *res = encode(str);
  printf("%s", res);
  getchar();
}
