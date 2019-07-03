#include <iostream>
#include <vector>
#include <string>
using namespace std;


/* 
Your previous Plain Text content is preserved below:

# Question:
# Given a string, write a function to return the index spans, i.e [start, end] index, of all longest consecutive repeating character substrings. 
#   
# Example,
# Input : str = "aapppPpple"
# Output : [(2,7)]
#   
# Input : str = "iphonexxxxssss"
# Output : [(6,9), (10, 13)]
#   
# Ignore case 
# 
# Enjoy your interview!
# 
# 
 */


/*
   aapppPpple
   i=0
   j=2
   curr = 2-0 = 2
   ans(0,1)
   max=2
   
   
   i=2
   j=8
   curr=6
   max=6
   ans(2, 7)
   
   i=8
   j=9
   curr=1
   i=9
   j=10
   curr=1
   
   
   //
   ab
   i=0
   j=1
   curr = 1;
   ans(0, 0)
   max=1
   
   i=1;
   j=2
   curr=1;
   
   ans((0,0), (1,1))
*/
vector<pair<int, int> > lcr(const string &s)
{
  vector<pair<int, int> > ans;
  int sz = s.size();
  if(sz<2)
  { 
     ans.push_back(make_pair(0, s.size()-1));
     return ans;
  }
  
  int max = 0;
  for(int i=0; i<sz; )
  {
     int j=i+1;
     while(j<sz && tolower(s[i])==tolower(s[j]))
       j++;
    
     int curr = j-i;
     if(curr>max)
     {
       ans.clear();
       ans.push_back(make_pair(i, j-1));
       max = curr;
     }
    else if(curr==max)
    {
       ans.push_back(make_pair(i, j-1));
    }
    i=j;
  }
  return ans;
}

// To execute C++, please define "int main()"
int main() {
  auto words = { "aapppPpple", "iphonexxxxssss" ,"ab", "aA"};
  

  for (const string& word : words) {
     vector<pair<int, int> > ans;
     ans = lcr(word);
     for(int i=0; i<ans.size(); i++)
     {
       cout<<" ("<<ans[i].first<<","<<ans[i].second<<"), ";
     }
     cout<<"\n";
  }
  return 0;
}


/* 
Your previous Plain Text content is preserved below:

# Question:
# Given a string, write a function to return the index spans, i.e [start, end] index, of all longest consecutive repeating character substrings. 
#   
# Example,
# Input : str = "aapppPpple"
# Output : [(2,7)]
#   
# Input : str = "iphonexxxxssss"
# Output : [(6,9), (10, 13)]
#   
# Ignore case 
# 
# Enjoy your interview!
# 
# 
 */

// *Given a stream of search counts and a window size k, find the average search counts in the last k hours. *
//     * 10, 20, 30, 40, 50, 60, …
//     * if k = 3, avg = 10, 15, n=3, avg = 20, n=4, avg = 30

/*
    10, 20, 30, 40, 50, 60
    
    i=0
    j=0+k-1;
    
    
    new_sum = sum-A[i++] + A[j++]
    avg.push_back(new_sum/k)
    sum = new_sum
*/
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      




