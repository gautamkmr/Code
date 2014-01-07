#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

int main()
{
  int t;
  char S[600001];
  cin>>t;
  while(t--)
  {
    cin>>S;
    //cout<<S;
    char *ptr1 = strstr(S,"010");
    char *ptr2 = strstr(S,"101");
    if(ptr1 || ptr2) 
     cout<<"Good\n";
    else
     cout<<"Bad\n";
  }
}
