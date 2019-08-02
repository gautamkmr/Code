/* Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string. */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool same(vector<int> &a, vector<int> &b)
{
    if(a.size() != b.size())
      return false; 
    for(int i=0; i<a.size(); i++)
    {
        
        if(a[i] != b[i])
         return false;
    }
    return true;
}

bool isPermutation(string &s1, string &s2)
{
    int ls1 = s1.size();
    int ls2 = s2.size();
    int i=0; 
    
    if(ls2<ls1)
     return false;
    
    // vector<int> s1c{256, 0};
    // vector<int> s2c{256, 0};
    
    vector<int> s1c(256, 0);
    vector<int> s2c(256, 0);
    
    // for(int i=0; i<s1c.size(); i++)
    //   cout<<s1c[i]<<" "<<s2c[i];
    // cout<<"\n";
    
    for(int i=0; i<ls1; i++)
      s1c[s1[i]]++;
    
    for(i=0; i<ls1; i++)
        s2c[s2[i]]++;
    
    if(same(s1c, s2c)){
      cout<<"First window match\n";        
      return true;
      
    }
    
    for(int j=i, prev=0; j<ls2-ls1+1; j++, prev++)
    {
        cout<<"Before\n";
        cout<<s2[j]<<":"<<s2c[s2[j]]<<"\n";
        cout<<s2[prev]<<":"<<s2c[s2[prev]]<<"\n";
        
        s2c[s2[j]]++;
        s2c[s2[prev]]--;
        cout<<"After\n";
        cout<<s2[j]<<":"<<s2c[s2[j]]<<"\n";
        cout<<s2[prev]<<":"<<s2c[s2[prev]]<<"\n";        
        if(same(s1c, s2c))
         return true;
    }
    return false;  
}

int main() {
    string s1 = "AAAAA";
   // string s2 = "XYCBAZA";
    string s2 = "XYAAACBZA";
    cout<<"ans: "<<isPermutation(s1, s2)<<"\n";
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
