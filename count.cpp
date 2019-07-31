#include <iostream>
#include <vector>

using namespace std;



/*
 * Complete the 'beautifulSubarrays' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY a
 *  2. INTEGER m
 */

long beautifulSubarrays(int a[], int n, int m) {
    int count = 0; 
    //int prefix[n] = { 0 }; 
    vector<int> prefix(n, 0);
    int odd = 0; 
  
    // traverse in the array 
    for (int i = 0; i < n; i++)  
    { 
  
        prefix[odd]++; 
  
        // if array element is odd 
        if (a[i] & 1) 
            odd++; 
  
        // when number of odd elements>=M 
        if (odd >= m) 
            count += prefix[odd - m]; 
    } 
  
    return count; 

    //int sz = a.size();
    //if(sz < m)
    //  return 0;

    //long ans = 0;
    //int count = 0;
    //for(int i=0, j=0; j<sz; j++)
    //{
    //    if(a[j]%2)
    //     count++;

    //    if(count == m)
    //     ans++;

    //    if(count > m)
    //    {
    //        while(i<j && a[i]%2==0) 
    //        {
    //           i++;
    //           ans++;
    //        }   
    //        if(i<j && a[i]%2)
    //        {
    //            i++;
    //            ans++;
    //        }
    //    }
    //}  
    //return ans;
}

int main()
{
  int a[] = {2,5,4,9};
  int m = 1;
  cout<<beautifulSubarrays(a,4, m);
  return 0; 
}
