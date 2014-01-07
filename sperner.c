/*
Codechef September Long Challenge
Problem : Project Spoon
Author : Vivek Hamirwasia (viv001)
*/

#include<cstdio>
using namespace std;
long long int C[100];
// Precomputing (N)C(N/2)
void precompute()
{
  C[0] = 1;
  C[1] = 0;
  C[2] = 1;
  long long int prev = 1;
  for(long long int i=3;i<=64;i++)
  {
    C[i]=C[i-1];
    if(i%2==1)
    {
      C[i]/=prev;
      C[i]*=i;
    }
    else
    {
      C[i]*=2;
      prev = i/2 + 1;
    }
  }
}

int main()
{
  precompute();
    int t;
   long long int n;
   scanf("%d",&t);
   int ans;
   while(t--)
   {
     scanf("%lld",&n);
     if(n==2)
     {
	 printf("2\n");
	 continue;
     }
     // Finding the minimum number of cities required to meet the requirement.
     for(int i=1;i<=64;i++)
       if(C[i]>=n)
      {
         ans = i;
         break;
      }
     printf("%d\n",ans);
   }
  return 0;
}
