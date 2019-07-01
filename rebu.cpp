#include <iostream>
#include <string>
#include <vector>
//#include <pair> 
 
using namespace std;
 
 
/*
Input: 
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
 
Output: 4
 
 
 
1 0 1 0 0
1 0 1 1 1
1 1 1 2 1
1 0 0 1 0
 
 
if(A[i][j] == 1)
{
    A[i][j]  = A[i][j] +  min(A[i][j-1], A[i-1][j-1], A[i-1][j])
}
 
 
*/
 
//Time, space R*C
 
int maxSquare(vector<vector<int> > A)
{
    int R = A.size();
    if(!R)
      return 0;
    
    int C = A[0].size();
    
    for(int i=1; i<R; i++)
    {
        for(int j=1; j<C; j++)
        {
            if(A[i][j]==1)
            {
                A[i][j] += min(A[i][j-1], min(A[i-1][j-1], A[i-1][j]));
            }
        }
    }
    
    
    int ans = 0;
    for(int i=0; i<R; i++)
    {
        for(int j=0; j<C; j++)
        {
            if(A[i][j]>ans)
             ans = A[i][j];
        }
    }
    
    return ans*ans;
}
 
 
 
// input:
// 1st vector: [0, 2], [5, 10], [16, 20]
// 2nd vector: [1, 5], [10, 18], [20, 23]
 
// AND
// Result: [1, 2], [16, 18]
 
// OR 
// Result: [0, 23]
 
// l1 [0,2] 
// l2 [2,5]
// OR : [0,5]
 
// and:  []
 
bool Overlap(pair<int, int> &p1, pair<int, int> &p2)
{
    bool NoOverlap = false;
    if(p1.second < p2.first || p1.first > p2.second)
      NoOverlap = true;
    
    return !NoOverlap;  
}
 
void merge(vector<pair<int, int> > &ans, pair<int, int> &p)
{
    if(ans.size()==0)
    {
        ans.push_back(p);
        return;
    }
    else
    {
        if(Overlap(ans[ans.size()-1], p))
          {
            ans[ans.size()-1].first = min(p.first, ans[ans.size()-1].first);
            ans[ans.size()-1].second = max(p.second, ans[ans.size()-1].second);
            return;
          }
        else
        {
            ans.push_back(p);
            return;
        }
    }
}
 
vector<pair<int, int> > OR(vector<pair<int, int> > &L1, vector<pair<int, int> > &L2)
{
    if(L1.size()==0)
      return L2;
    if(L2.size() ==0)
      return L1;
      
    vector<pair<int, int> > ans;
    int i=0, j=0;
    while(i<L1.size()&&j<L2.size())
    {
        pair<int, int> P1 = L1[i];
        pair<int, int> P2 = L2[j];
        pair<int, int> tmp;
        if(Overlap(P1, P2))
        {
           tmp.first = min(P1.first, P2.first);
           tmp.second = max(P1.second, P2.second);
           merge(ans, tmp);
           i++;
           j++;
        }
        else
        {
            if(P1.second < P2.second)
              {
                  merge(ans, P1);
                  i++;
              }
            else
            {
                merge(ans, P2);
                j++;
            }
        }
    }
    while(i<L1.size())
    {
        merge(ans, L1[i++]);
    }
    while(j<L2.size())
    {
        merge(ans, L2[j++]);
    }   
    return ans;
}
 
vector<pair<int, int> > AND(vector<pair<int, int> > &L1, vector<pair<int, int> > &L2)
{
    vector<pair<int, int> > ans;
    
    if(L1.size() ==0 || L2.size()==0)
      return ans; 
    int i=0, j=0;
    
    
// 1st vector: [0, 2], [5, 10], [16, 20]
// 2nd vector: [1, 5], [10, 18], [20, 23]
// Result: [1, 2], [16, 18]
 
 
// 1st vector: [0, 2], [5, 10], [16, 20]
// 2nd vector: [1, 8], [10, 18], [20, 23]
//AND
//  [1,2] , [5, 8], [16, 18]
 
// AND
// Result: [1, 2], [16, 18]
 
    while(i<L1.size()&&j<L2.size())
    {
        pair<int, int> P1 = L1[i];
        pair<int, int> P2 = L2[j];
        pair<int, int> tmp;  
        if(!Overlap(P1, P2))
        {
            if(P1.first < P2.first)
              i++;
            else
              j++;
        }
        else
        {
            tmp.first = max(P1.first, P2.first);
            tmp.second = min(P1.second, P2.second);
            
            if(tmp.first != tmp.second) {
                ans.push_back(tmp);
            }
            
            if(tmp.second==P1.second)
              i++;
            else
              j++;
        }
    }
    return ans;
}
 
 
int main() {
    // 1st vector: [0, 2], [5, 10], [16, 20]
    // 2nd vector: [1, 5], [10, 18], [20, 23] 
    
    
        
// 1st vector: [0, 2], [5, 10], [16, 20]
// 2nd vector: [1, 5], [10, 18], [20, 23]
// Result: [1, 2], [16, 18]
 
    vector<pair<int, int> > l1 = {make_pair(0, 2), make_pair(5, 10), make_pair(16, 20)};
    vector<pair<int, int> > l2 = {make_pair(1,5), make_pair(10, 18), make_pair(20, 23)};
    
    vector<pair<int, int> > ans = AND(l1, l2);
    
    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i].first<<", "<<ans[i].second<<"\n";
    }
    
    
    return 0;
}
 
 
