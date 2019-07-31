#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
/*
 Return count of list of all pairs where their difference is equal to k

*/


int count(vector<int> &A, int k)
{
    unordered_map<int, int> mp;
    
    for(int i=0; i<A.size(); i++)
      mp[A[i]]++;
      
    int ans = 0;  
    for(int i=0; i<A.size(); i++)
    {
        int x = A[i];
        if(mp.find(x-k) != mp.end())
         {
              ans += mp[x]*mp[x-k];
         }
        if(mp.find(x+k) != mp.end())
        {
            ans+=mp[x]*mp[x+k];
        }
        mp.erase(x);
    }
    return ans;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT 
       (1,5)
       (4,8)
       (5,9)
    */
    
    vector<int> in{1,4,5,7,8,9};
    cout<<count(in, 4);
    
    return 0;
}





/*
(1,1, 2,2)
k=1
1,2
1,2
1,2
1,2
 a + k = 
 a - k  = b 

 b + k 
 b - a 
  
 abs(a - b ) == k
 a - k  
 a + k 

*/
