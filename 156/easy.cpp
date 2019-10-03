#include<iostream>
#include<vector>
using namespace std;

    int maxSunAtMostK(vector<int> &arr, int k)
    {
        int n = arr.size();
        int cnt = 0, maxcnt =0;
        int sum = 0;
        for(int i=0;i<n; i++)
        {
            if(sum + arr[i]<=k)
            {
                sum += arr[i];
                cnt++;
            }
            else if(sum !=0)
            {
                sum = sum - arr[i-cnt] + arr[i];
            }
            maxcnt = max(maxcnt, cnt);
        }
        return maxcnt;    
    }
    
    int equalSubstring(string s, string t, int maxCost) {
        vector<int> diff;
        for(int i=0; i<s.size(); i++)
        {
            diff.push_back(abs(s[i] - t[i]));
        }
        return maxSunAtMostK(diff, maxCost);
        //sort(diff.begin(), diff.end());

    }


int main()
{

  cout<<equalSubstring("abcd", "acde", 0)<<"\n";
  return 0;
}
