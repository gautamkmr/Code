#include<iostream>
#include<math.h>
using namespace std;

void prime(int n, bool prime[])
{
   prime[0] =  false;
   prime[1] = false;
   prime[2] = true;
   int i;
   for(i=2;i<=n;i++)
     prime[i] = true;

   int limit = sqrt(n);
   
   for(i=2;i<=limit;i++)
   { 
      if(prime[i]==true)
      { 
        int j;
        for(j=i*i;j<=n; j+=i)
          prime[j] = false;
      }
    }
} 

int main()
{
  int n;
  cin>>n;
  bool *p = new bool[n+1];
  prime(n,p);
  if(p[n]==true)
   cout<<n<<" is prime\n";
  else
   cout<<n<<" is not prime\n";
  
  return 0;
}
