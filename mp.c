#include<stdio.h>
#include<stdlib.h>
int main()
{
  int t;
 
  long long n,i,a;
  scanf("%d",&t);
  while(t--)
  {
    scanf("%lld",&n);
    for(i=0;i<n;i++)
     scanf("%lld",&a);
   
    printf("%lld\n",(n*(n-1LL))/2LL);
      
  }
  return 0;
}
