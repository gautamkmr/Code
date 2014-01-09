/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

*/
#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

bool validParenthesis(string str)
{
  long res=0;
  for(int i=0;i<str.length();i++)
  {

    char ch=str[i];
    int var = 0;
    switch(ch)
    {
      case '(':  var=1; break;
      case ')':  var=-1; break;
      case '{':  var=2; break;
      case '}':  var=-2; break;
      case '[':  var=3; break;
      case ']':  var=-3; break;
    }
   if(var>0)
     res = res*10 + var;
   else if(var<0)
    {
      if(res%10 + var==0)
        res=res/10;
      else
        return false;
    }
    else
      return false;
   }
   return res==0;
}

/*
Put some test case 
*/
int main()
{
   printf("%d\n",validParenthesis("(){[]}"));
   return 0;

}
