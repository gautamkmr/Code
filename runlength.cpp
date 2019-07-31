#include<iostream>
using namespace std;

/*

aaabbccc -> a3b2c3 do it inplace 
*/

void runLengthEncoding(string &s)
{
	if(s.size()<2)
		 return;

    for(int i=0, j=0; j<s.size(); j++)
    {
    	int c = 1;
    	char ch = s[j];
    	int k = j+1;
    	while(k<s.size() && s[k] == s[j])
    		k++;
    	
    }		
}