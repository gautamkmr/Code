// A Dynamic Programming based program to test whether a given string can
// be segmented into space separated words in dictionary
#include <iostream>
#include <string.h>
using namespace std;

/* A utility function to check whether a word is present in dictionary or not.
  An array of strings is used for dictionary.  Using array of strings for
  dictionary is definitely not a good idea. We have used for simplicity of
  the program*/
int dictionaryContains(string word)
{
    string dictionary[] = {"mobile","samsung","sam","sung","man","mango",
                           "icecream","and","go","i","like","ice","cream"};
    int size = sizeof(dictionary)/sizeof(dictionary[0]);
    int i;
    for ( i = 0; i < size; i++)
        if (dictionary[i].compare(word) == 0)
           return true;
    return false;
}


bool wordBreak(string str)
{
      int size = str.size();
      if(size == 0)  return true; 

    // Create the DP table to store results of subroblems. The value wb[i]
    // will be true if str[0..i-1] can be segmented into dictionary words,
    // otherwise false.
    bool wb[size+1];
    memset(wb, 0, sizeof(wb)); // Initialize all values as false.

    int i;
    for(i=1; i<=size; i++)
    {
       if(wb[i]==false && dictionaryContains(str.substr(0,i)))
         wb[i] =  true;
       
       if(wb[i]==true)
       {
          if(i>=size) return true;
          int j;
          for(j=i+1; j<=size; j++)
          { 
             if(wb[j]==false && dictionaryContains(str.substr(i,j-i)))
               wb[j] =  true;
             
             if(j==size && wb[j]==true)
               return true;
          }
       }
    }   
    return false; 
}



// Driver program to test above functions
int main()
{
    wordBreak("ilikesamsung")? cout <<"Yes\n": cout << "No\n";
    wordBreak("iiiiiiii")? cout <<"Yes\n": cout << "No\n";
    wordBreak("")? cout <<"Yes\n": cout << "No\n";
    wordBreak("ilikelikeimangoiii")? cout <<"Yes\n": cout << "No\n";
    wordBreak("samsungandmango")? cout <<"Yes\n": cout << "No\n";
    wordBreak("samsungandmangok")? cout <<"Yes\n": cout << "No\n";
    return 0;
}


