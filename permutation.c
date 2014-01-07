#include<stdio.h>
void swap(char *a, char *b)
{
  char tmp = *a;
  *a = *b;
  *b = tmp;
}
void permutation(char *str, int i, int n)
{
      int j;
      char tmp; 
 if(i==n)
   {
     printf("%s\n",str);
   }
  else
   {

      for(j=i;j<=n;j++)
      {
        swap(&str[i],&str[j]);
 /*       tmp =  str[i];
        str[i] =  str[j];
        str[j] = tmp; */
        permutation(str,i+1,n);
  /*      tmp =  str[i];
        str[i] =  str[j];
        str[j] = tmp; */
 
        swap(&str[i],&str[j]);
      }
   }
}
int main()
{
  char s[]="abc";
  permutation(s,0,2);
  return 0;
}
