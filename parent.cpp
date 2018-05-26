#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map> 
#include <set>


using namespace std;
/*
Suppose we have some input data describing a graph of relationships between parents and children over multiple generations. The data is formatted as a list of (parent, child) pairs, where each individual is assigned a unique integer identifier.

For example, in this diagram, 3 is a child of 1 and 2, and 5 is a child of 4:
            
1   2   4
 \ /   / \
  3   5   8
   \ / \   \
    6   7   9

Write a function that, for two given individuals in our dataset, returns true if and only if they share at least one ancestor.

Sample input and output:
parentChildPairs, 3, 8 => false
parentChildPairs, 5, 8 => true
parentChildPairs, 6, 8 => true


*/
// To execute C++, please define "int main()"

bool hasIntersection(set<int> &a,  set<int> &b)
{
    if(a.size() ==0 && b.size() == 0)
        return false;
    if(a.size() ==0 || b.size() == 0)
        return false;
  

    for(auto it=a.begin(); it !=a.end(); it++)
    {
      for(auto bt=b.begin(); bt !=b.end(); bt++)
      {
        if((*it) == (*bt))
            return true;
      }
    } 
    return false;
}

void printset(set<int> &a)
{
    for(auto it=a.begin(); it !=a.end(); it++)
      cout<<*it<<",";  
  cout<<"\n";
}


vector<int> rootNode(vector<pair<int, int> > &pairs, unordered_map<int, set<int> > &pm)
{
    unordered_map<int, int> mp;
    for(int i=0; i<pairs.size(); i++)
    {
       int p = pairs[i].first;
       int c = pairs[i].second;
   
       // prepare the list of children
       pm[p].insert(c);
       if(pm.find(c) == pm.end())
       {
            set<int> tmp;
            pm[c] = tmp;
       } 
       // Get the parent count 
       mp[c]++;
       if(mp.find(p) == mp.end())
         mp[p] = 0;
    }

    vector<int> ans;
    for(auto it=mp.begin(); it!=mp.end(); it++)
    { 
       if(mp[it->first] == 0)
         ans.push_back(it->first);
    }
    return ans;
}

// DFS 
void process(int r, unordered_map<int, set<int> > &mp, vector<int> &p,
                    unordered_map<int, set<int> > &mc)
{
   if(mp[r].size() == 0)
     return ;
   p.push_back(r);
   for(auto it=mp[r].begin(); it!=mp[r].end(); it++)
   {
       for(int i=0; i<p.size(); i++)
          mc[*it].insert(p[i]);
       process(*it, mp, p, mc);
   }
   p.pop_back();
}

int main() {

  vector<pair<int, int> > parent_child_pairs = {
      std::make_pair(4, 5),  
      std::make_pair(1, 3),
      std::make_pair(2, 3),
      std::make_pair(3, 6),
      std::make_pair(5, 6),
      std::make_pair(5, 7),
      std::make_pair(4, 8),
      std::make_pair(8, 9),
      //std::make_pair(4, 5),

  };

  unordered_map<int, set<int> > mp;
  unordered_map<int, set<int> > mc;

  //Get the list of orphans 
  vector<int> one = rootNode(parent_child_pairs, mp);


  for(int i=0; i<one.size(); i++) {
    set<int> z;
    mc[one[i]] = z;
    vector<int> p;
    process(one[i], mp, p, mc);
  }

  cout<<hasIntersection(mc[6], mc[8])<<"\n";   
  cout<<hasIntersection(mc[6], mc[9])<<"\n";
  cout<<hasIntersection(mc[3], mc[8])<<"\n";
 
  return 0;
}


/* 
Your previous Markdown content is preserved below:

Welcome to the Interview!
 */
