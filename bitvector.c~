#include<stdio.h>
#include<string.h>
/*
  print all characters from s2 which are not present in s1
*/
int main()
{
 char s1[] = "gautam";
 char s2[] = "kumar";
 int val = 0;
 int i;
 for(i=0;i<strlen(s1);i++)
 {
   int c = s1[i] - 'a';
    val |= 1<<c;   // set all the bits corresponing the s1
 }
 printf("S1 %s, S2 %s\n",s1,s2);
 printf("S2 - S1: ");
 for(i=0;i<strlen(s2);i++)
 {
   int c = s2[i] - 'a';
   if(val & 1<<c) continue;
   else printf("%c",s2[i]);
 }
 printf("\n");
 return 0;
}
