
#include<iostream>
#include<unordered_map>
#include<vector> 
using namespace std;



    
    vector<string> generatesValid(string &s, unordered_map<string, bool> &dead, unordered_map<string, bool> &visit )
    {
        vector<string> ans;
        //+1
        for(int i=0; i<4; i++)
        {
            string tmp = s;
            tmp[i] = char((((tmp[i]-'0') + 1)%10) + '0');
            if((dead.find(tmp) == dead.end()) && (visit.find(tmp)==visit.end()))
                ans.push_back(tmp);
            cout<<tmp<<"\n";
        }
        //-1
        for(int i=0; i<4; i++)
        {
            string tmp = s;
            tmp[i] = (tmp[i]=='0'?'9': char((((tmp[i]-'0') - 1)%10) + '0'));
            if((dead.find(tmp) == dead.end()) && (visit.find(tmp)==visit.end()))
                ans.push_back(tmp);  
            cout<<tmp<<"\n";
            
        }
        return ans;
    }


 int main()
{

}