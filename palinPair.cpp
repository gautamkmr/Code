/*
// ex. 'bob' -> true
// ex. 'hello' -> false
// ex. 'rattar' -> true

*/

//m words, n 

//m^2*n
/*
["gab", "cat", "cbag", "alpha"] -> [["gab", "bag"], ["bag", "gab"]]
 -> ["gabbag", "baggab"]
 
 ["gab, "caacbag"]
 ["gab", "cabbag", "cabbagaaaa" , B , C]
 gab+cabbag
 

abs(len(a)-len(b)) <=1 and their character set should differe by at most 1.
gab bcag
*/


#include <iostream>
#include <string>
#include <vector> 
#include <algorithm>
using namespace std;

bool isPalin(const string &s)
{
  
  int sz = s.size();
  if(sz<=1)
    return true;
  
  int i=0, j=sz-1;
  
  while(i<j)
  {
    if(s[i] != s[j])
      return false;
    
    i++;
    j--;
  }
  
  return true;
}



vector<vector<string> > palinList(vector<string> &words)
{
  vector<vector<string> > ans;
  
  int n = words.size();
  if(n==0)
    return ans;
  
  for(int i=0; i<n; i++)
  {
    for(int j=i+1; j<n; j++)
    {
      string rev = words[i];  
      reverse(rev.begin(), rev.end());
      
      size_t found = words[j].find(rev); //O(n)
      if(found != string::npos)
      {
        string AB = words[i] + words[j];
        if(isPalin(AB))   //O(n)
        {
           vector<string> tmp; 
           tmp.push_back(words[i]);
           tmp.push_back(words[j]);
           ans.push_back(tmp);
        }
        string BA = words[j] + words[i];
        if(isPalin(BA))
        {
          vector<string> tmp;
          tmp.push_back(words[j]);
          tmp.push_back(words[i]);
          ans.push_back(tmp);
        }
      }
    }
  }
  return ans;
}






// To execute C++, please define "int main()"
int main() {
  vector<vector<string> > ans;
 
  //Fix the below initialization
  vector<std::string> words = { "gab", "cat", "caacbag", "alpha", "bob"}; 
  ans = palinList(words);
  
  for (int i=0; i<ans.size(); i++) {
    for(int j=0; j<ans[i].size(); j++)
    {
      
       cout << ans[i][j]<<",";
    }
    cout<<"\n";
  }
  
  return 0;
}

