#include<iostream>
#include<vector>
using namespace std;
/*
    void get(string &s, int k, string &t)
    {
        if(s.size() < k)
            return;
        else if (s.size()==k)
            return;
        int i,j;
        for(i=0; i<s.size(); i++)
        {
            j=i+1;
            int c = 1;
            while(j<s.size() &&  c<k && s[i]==s[j])
            {
                j++;
                c++;
            }
            if(c==k)
            {
                break;
            }
        }
        if(i==s.size()) {
            return;
        else
        {
            //remove that character k times and recurse
            string newstr = s.substr(0, i) + s.substr(i+k+1);
            t=newstr;
            cout<<newstr<<"\n";
            get(newstr, k, t);
        }
    }
  */  
    string removeDuplicates(string S, int k) {
        //cout<<S<<":";
        if(S.size() < k)
            return S;
        int i,j;
        for( i=0; i<S.size(); i++)
        {
             j=i+1;
             while(j<S.size() && S[i]==S[j])
                j++;
            if((j-i + 1) >k) {
                //cout<<"("<<j<<","<<i<<")";
                break;
             }
        }
        if(i!=S.size())
        {
            string  S1=S.substr(0, i);
            string  S2=S.substr(i+k);
            //cout<<S1<<"+"<<S2<<"\n";
            return removeDuplicates(S1+S2, k);
        }
        else
            return S;
     
    }

int main()
{

  //cout<<equalSubstring("abcd", "acde", 0)<<"\n";
  cout<<removeDuplicates("abcd", 2)<<"\n";
  return 0;
}
