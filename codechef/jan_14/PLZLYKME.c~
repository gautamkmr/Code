#include<iostream>
#include<math.h>

using namespace std;

long long unsigned power(long long unsigned x, long long unsigned y)
{
    long long unsigned temp;
    if( y == 0)
       return 1;
    temp = power(x, y/2);      
    if (y%2 == 0)
        return temp*temp;
    else
        return x*temp*temp;
} 

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    long long unsigned L,D,S,C;
    cin>>L>>D>>S>>C;
    double l=log(L);
    double res = log(S) + (D-1)*log(1+C);
    if(l<=res)
      cout<<"ALIVE AND KICKING\n";
    else
      cout<<"DEAD AND ROTTING\n";
  }
}
 
