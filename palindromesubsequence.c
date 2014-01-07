#include<stdio.h>
#include<string.h>
 
// A utility function to get max of two integers
int max (int x, int y) { return (x > y)? x : y; }
 
int lpsrecurse(char *str,int i, int j)
{
  if(i==j)
   return 1;

  if(j==i+1)  return (1 + (str[i]==str[j]));
  
  if(str[i]==str[j])
    return 2 + lpsrecurse(str,i+1,j-1);
  else
   return max(lps(str,i+1,j), lps(str, i, j-1));
}
// Returns the length of the longest palindromic subsequence in seq
int lps(char *str)
{
   int n = strlen(str);
   int i, j, cl;
   int L[n][n];  // Create a table to store results of subproblems
   
   for(i=0;i<n;i++)
    L[i][i] = 1;
 
   // Strings of length 1 are palindrome of lentgh 1
   
    // Build the table. Note that the lower diagonal values of table are
    // useless and not filled in the process. The values are filled in a
    // manner similar to Matrix Chain Multiplication DP solution (See
    // http://www.geeksforgeeks.org/archives/15553). cl is length of
    // substring
    for(cl=2; cl<=n; cl++)
    {
      for(i=0;i<n-cl+1;i++)
      {
         j=i+cl-1;
         if(str[i]==str[j] && cl==2)
           L[i][j] = 2;
         else if(str[i]==str[j])
           L[i][j] = L[i+1][j-1] + 2;
         else
           L[i][j] = max(L[i+1][j], L[i][j-1]);
       }          
    }

    return L[0][n-1];
}
 
/* Driver program to test above functions */
int main()
{
    char seq[] = "GEEKS FOR GEEKS";
    int n = strlen(seq);
    printf ("The lnegth of the LPS is %d %d", lps(seq),lpsrecurse(seq,0,n-1));
    getchar();
    return 0;
}
