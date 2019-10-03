#include<iostream>
#include<vector>
using namespace std;

    int nthUglyNumber(int n, int a, int b, int c) {
        if(!n)
            return 1;
        
     //unsigned ugly[n+1]; // To store ugly numbers 
    unsigned i2 = 1, i3 = 1, i5 = 1; 
    unsigned next_multiple_of_2 = a; 
    unsigned next_multiple_of_3 = b; 
    unsigned next_multiple_of_5 = c; 
    unsigned next_ugly_no = 1; 
  
    //ugly[0] = 1; 
    for (int i=1; i<=n; i++) 
    { 
       next_ugly_no = min(next_multiple_of_2, 
                           min(next_multiple_of_3, 
                               next_multiple_of_5)); 
       if (next_ugly_no == next_multiple_of_2) 
       { 
           i2 = i2+1; 
           next_multiple_of_2 = i2*a; 
       } 
       if (next_ugly_no == next_multiple_of_3) 
       { 
           i3 = i3+1; 
           next_multiple_of_3 = i3*b; 
       } 
       if (next_ugly_no == next_multiple_of_5) 
       { 
           i5 = i5+1; 
           next_multiple_of_5 = i5*c; 
       } 
    } /*End of for loop (i=1; i<n; i++) */
    return next_ugly_no; 
  }

int main()
{
  cout<<nthUglyNumber(1000000000, 2, 217983653, 336916467)<<"\n";
 return 0;
}


