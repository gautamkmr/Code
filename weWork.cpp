/*

Valid enclosures

Create a function that returns a boolean and validates if an input string has a valid set of enclosures. If the string is empty the function should return true.

Valid:
{}
[]
[{}]
[]{}
""
function (input) { const array = [1, 2, 3]; console.log(array); }

Invalid:
{[}]
}}{{
(){
array.map(el => { console.log('Hello world'); }


long long num = 0
{ -> 1
[ -> 2 
( -> 3

x=num %10
} x==1
]
)

num==0

num 333333333333 << max value of long long (2^64-1)
*/


#include <iostream>
#include <stack>
using namespace std;

bool isValid(const string &s)
{
   //cout<<"\n";
   int n = s.size();
   if(!n)
     return true;
   
   stack<char> st;
   
   for(int i=0; i<n; i++)
   {
      if(s[i]=='(' || s[i]=='{' || s[i] == '[')
      {
        // cout<<s[i]<<" ";
         st.push(s[i]);
      }
      else if(s[i]==')' || s[i]=='}' || s[i] == ']')
      { 
         //cout<<s[i]<<" ";
         //cout<<"\nStack size "<<st.size()<<"\n";
         
         if(st.empty())
           return false;
         else
         {
            char ch = st.top();
            st.pop();
            
            if(ch=='(')
            {
               if(s[i] != ')')
                 return false;
            }
            else if(ch=='[')
            {
               if(s[i] != ']')
                 return false;
            }           
            else if(ch=='{')
            {
               if(s[i] != '}')
                 return false;
            }           
         }
      }
     
   }
   
   //cout<<"\nStack size "<<st.size()<<"\n";
   return st.empty();
}

// To execute C++, please define "int main()"

/*
{}
[]
[{}]
[]{}

{[}]
}}{{
(){
*/
int main() {
  
  auto valid = { "function (input) { const array = [1, 2, 3]; console.log(array); }" , "{}", "[]", "[{}]", "[]{}", "{[}]", "}}{{", "(){", "array.map(el => { console.log('Hello world'); }"};
  
  for (const string& word : valid) {
    cout<<word<<" "<<isValid(word)<<"\n";
  }

  return 0;
}

