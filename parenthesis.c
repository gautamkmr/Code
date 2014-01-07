#include<stdio.h>
void parenthesis(int n, int l, int r, int pos)
{
 
  static char s[10000];
  if(r==n)
   {
     int i;
     for(i=0;i<pos;i++) 
        printf("%c",s[i]);
     printf("\n");
   }
   else
   {
      if(r<l)
       {
         s[pos] = ')';
         parenthesis(n,l,r+1,pos+1);
       }
      if(l<n)
       {
         s[pos] = '(';
         parenthesis(n,l+1,r,pos+1);
       }
   }     
}

int main()
{
  int n;
  scanf("%d",&n);
  int l=0,r=0,pos=0;
  parenthesis(n,l,r,pos);
  return 0;
}

