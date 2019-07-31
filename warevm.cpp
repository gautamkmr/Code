#include <iostream>
#include <string>
#include <vector>

using namespace std;

//write multithreaded matrix multiplication
vector<vector<int> > matrixMultiplication(vector<vector<int> > &A, vector<vector<int> > &B)
{
    int m = A.size();
    int p = B.size();
    
    if(!m)
    {
       if(!p)
        return vector<vector<int> >{{}};
       else
         {
             cout<<"Not possible to multiply with empty matrix\n";
             return vector<vector<int> >{{}};
         }
    }
    if(!p)
    {
       if(!m)
        return vector<vector<int> >{{}};
       else
         {
             cout<<"Not possible to multiply with empty matrix\n";
             return vector<vector<int> >{{}};
         }
    }   
    
    int n = A[0].size();
    int q = B[0].size();
    vector<vector<int> > C(m, vector<int>(q, 0));
    
    if(n != p)
    {
        cout<<"Dimension mismatch";
        return C;
    }
    
    // m, n * p, q ==> m*q
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<q; j++)
        {
          int total = 0;
          for(int k=0; k<n; k++)
          {
            //lock_acquire();  
            total += A[i][k]*B[k][j];
            //lock_release();  

          }
         // lock_acquire();          
          C[i][j] = total;
         // lock_release();
        }
    }
    return C;
}

int main() {
    vector<vector<int> > A = {{1,2,3}, {4,5,6},{7,8,9}};
    vector<vector<int> > B = {{1,4,7,10}, {2,5,8,11},{3,6,9,12}};
    
    vector<vector<int> > C = matrixMultiplication(A, B);
    for(int i=0; i<C.size(); i++)
    {
        for(int j=0; j<C[i].size(); j++)
          cout<<C[i][j]<<" ";
        cout<<"\n";  
    }
    
    return 0;
}

