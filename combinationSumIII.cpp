#include <iostream>
#include <vector>
using namespace std;


    void get(vector<vector<int> > &ans, int k, int n, vector<int> tmp, int s)
    {
        if(!n)
        {
            if(tmp.size()==k)
            {
                sort(tmp.begin(), tmp.end());
                ans.push_back(tmp);
                return;
            }
        }
        
        for(int i=s; i<=9; i++)
        {
            tmp.push_back(i);
            get(ans, k, n-i, tmp, i+1);
            tmp.pop_back();
        }
    }
    
    vector<vector<int> > combinationSum3(int k, int n) {
        vector<vector<int> > ans;
        if(!k || !n)
            return ans;
        
        vector<int> tmp;
        get(ans, k, n, tmp, 1);
        return ans;
    }

int main()
{

while(1)
{ 
  int k, n;
  cin>>k>>n;  
  vector<vector<int> > ans = combinationSum3(k, n);
  for(int i=0; i<ans.size(); i++)
  {
    cout<<"[";
    for(int j=0; j<ans[i].size(); j++)
    {
        cout<<ans[i][j]<<" ";
    }
    cout<<"]\n";
  }
 }
}
