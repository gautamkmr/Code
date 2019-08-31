// Kth Largest Island
// You are traveling on the sea:

// [0, 1, 0, 0, 0]
// [1, 0, 0, 1, 1]
// [0, 0, 0, 1, 0]
// [0, 1, 1, 0, 0]

// 0 is water, 1 is land.

// Find the location of Kth largest island.

// Area of island: 1, 1, 3, 2
// k = 2, output 2nd island location (1,3)


// compile with g++ -std=c++11 robinhood-2.cpp 
  
#include <iostream>
#include <vector>
#include <queue>

using namespace std;


struct islands
{
  int area;
  int x;
  int y;
  islands(int a, int b, int c)
  {
    area = a;
    x = b;
    y = c;
  }
};

//bool compare(struct islands &a, struct islands &b)
//{
//  return a.area < b.area;
//}
struct Comp{
    bool operator()(const struct islands& a, const islands& b){
        return a.area > b.area;;
    }
};

struct islands findKthLargest(vector<struct islands>& nums, int k) {
    priority_queue<struct islands, std::vector<struct islands>, Comp> q;
    int n=nums.size();

    for (auto &v: nums)
    {
        if(q.size()<k)
        {
            q.push(v);
        }
        else {
            if(v.area > q.top().area)
            {
                q.pop();
                q.push(v);
            }
        }
    }
    return q.top();
}

//https://www.geeksforgeeks.org/map-rbegin-function-in-c-stl-2/
int DFS(vector<vector<int> > &b, int i, int j)
{
  if(i<0 || j<0 ||i >= b.size() || j >= b[0].size()||b[i][j] !=1)
    return 0;
  
  b[i][j] = -1; //mark visited
  int area = 1; // for my current position
  area = area + DFS(b, i+1, j) + DFS(b, i-1, j) + DFS(b, i, j-1) + DFS(b, i, j+1);
  return area;
}

int KthIsland(vector<vector<int> > &b, int k)
{
  vector<struct islands> isl;
  int r = b.size();
  if(!r)
    return 0;
  int c = b[0].size();
  for(int i=0; i<r; i++)
  {
    for(int j=0; j<c; j++)
    {
      if(b[i][j] == 1)
      {
         int area = DFS(b, i, j);
         cout<<i<<","<<j<<" area:"<<area<<"\n";
         isl.push_back(islands(area, i, j));
      }
    }
  }
  if(isl.size() < k) 
  {
     cout<<"There is only "<<isl.size()<<" islands\n";
     return -1;
  } 
  struct islands s = findKthLargest(isl, k);
  cout<<k<<" islands is located at "<<s.x<<","<<s.y<<" Area:"<<s.area<<"\n";
  return 0;
}  
    

int main() {
  // [0, 1, 0, 0, 0]
// [1, 0, 0, 1, 1]
// [0, 0, 0, 1, 0]
// [0, 1, 1, 0, 0]
  
  vector<vector<int> > b;
  vector<int> a = {0, 1, 0, 0, 0};
  b.push_back(a);
  a = {1, 0, 0, 1, 1};
  b.push_back(a);
  a = {0, 0, 0, 1, 0};
  b.push_back(a);
  a = {0, 1, 1, 0, 0};
  b.push_back(a);
  a = {0, 0, 0, 1, 1}; 
  b.push_back(a);
  int k = 5;
  KthIsland(b, k);
  return 0;
}

