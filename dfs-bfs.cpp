#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    
    bool isSafe(int &r, int &c, int i , int j)
    {
       if(i<0 || j<0  || i>=r || j>=c)    
           return false;
       return true; 
    }
    
    void print(vector<vector<int>>& A)
    {
        for(int i=0; i<A.size(); i++)
        {
            for(int j=0; j<A[i].size(); j++)
                cout<<A[i][j]<<" ";
            cout<<"\n";
        }
    }
    
    
    bool isBorder(vector<vector<int>>& A, int &i, int &j)
    {
        int r = A.size();
        int c = A[i].size();
        
        //left 
        if(i-1>=0 && A[i-1][j]==0)
            return true;
        if(i+1<r && A[i+1][j]==0)
            return true;
        if(j-1>=0 && A[i][j-1]==0)
            return true;
        if(j+1<c && A[i][j+1]==0)
            return true;
        return false;
    }
    
    void DFS(vector<vector<int>>& A, vector<vector<bool>>& v, int i, int j, int &r, int &c)
    {
      // if(i<0 || j<0  || i>=r || j>=c)
      //     return;

        //cout<<i<<" "<<j<<"\n";
        v[i][j] = true;
        A[i][j] = 2;

        if(isSafe(r, c, i+1, j) && A[i+1][j] == 1 && v[i+1][j]==false)
          DFS(A, v, i+1, j, r, c);
        if(isSafe(r, c, i-1, j) && A[i-1][j] == 1 && v[i-1][j]==false)
          DFS(A, v, i-1, j, r, c);
        if(isSafe(r, c, i, j+1) && A[i][j+1] == 1 && v[i][j+1]==false)        
          DFS(A, v, i, j+1, r, c);
        if(isSafe(r, c, i, j-1) && A[i][j-1] == 1 && v[i][j-1]==false)        
          DFS(A, v, i, j-1, r, c);        
    }
    
    int shortestBridge(vector<vector<int>>& A) {
        //run DFS and update those entry from 1 to 2
        int r = A.size();
        if(!r)
            return 0;
        int c = A[0].size();
        bool flag = false;
        
        vector<vector<bool> > visit(r, vector<bool>(c, false));
        
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                if(A[i][j]==1 && visit[i][j] == false)
                {
                    DFS(A, visit, i, j, r, c);
                    flag = true;
                    break;
                }
            }
            if(flag)
                break;
        }
        
        //print(A);
        //push all these border points 
        queue<pair<int, int> > q;
        queue<pair<int, int> > q2;

        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                if(A[i][j] == 2 && isBorder(A, i, j))
                {
                    //cout<<i<<" "<<j<<"\n";
                    q.push(make_pair(i, j));
                }
                
                else if(A[i][j] == 1 && isBorder(A, i,j)){
                    q2.push(make_pair(i, j));
                    //cout<<i <<j<<"..\n";
                }
            }
        }
        
        int val = 1;
        //start from smaller queue
        if(q2.size() < q.size()) {
          q = q2;
          val = 2; //u will be looking for 2 setup by DFS
        }
        
        int ans = -1;//setting from source
        while(q.empty()==false)
        {
           ans++;
           int sz = q.size();
           // cout<<sz<<"\n";
           while(sz--)
           {
               pair<int, int> p = q.front();
               q.pop();
               int i=p.first, j=p.second;

               if(A[i][j]==val)
                   return ans-1;//this -1 for dest
               //cout<<i<<" "<<j<<"\n";
              //cout<<A[i][j]<<"\n";
               //find all four direction and requeu
               //mark them visited
               A[i][j] = 3;
               //cout<<i<<":"<<j<<"\n";
               //requeu only valid once
               if(isSafe(r, c, i-1, j) {
                   if( A[i-1][j] == 0 ) 
                     q.push(make_pair(i-1, j));
                   if(A[i-1][j] == val)
                       return ans;
               }
               //cout<<"hello1\n";
               }
               if(isSafe(r, c, i+1, j)) {
                   if(A[i+1][j] == 0)
                   q.push(make_pair(i+1, j));
                   if(A[i+1][j] == val)
                       return ans;
                              //cout<<"hello2\n";
               }

               if(isSafe(r, c, i, j-1)){ 
                   if(A[i][j-1] == 0 )
                     q.push(make_pair(i, j-1));
                   if(A[i][j-1] == val)
                       return ans;
                            //  cout<<"hello3\n";
               }

               if(isSafe(r, c, i, j+1)){
                  if(A[i][j+1] == 0)
                   q.push(make_pair(i, j+1));   
                   if(A[i][j+1] == val)
                     return ans;
                           //   cout<<"hello4\n";
                }

           }
            
        }
        return -1;
    }
};

int main()
{

return 0;
}
