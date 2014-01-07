#include<stdio.h>
void* Memset(void *ptr, int c, int n)
{
  unsigned char *s=ptr;
  while(n--)
   *s++ = (unsigned char)c;
  
  return ptr;
} 
int main()
{
  char a[35];
  
  Memset(a,'\0',100);
  return 0;

}
