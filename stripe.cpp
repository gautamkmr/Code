// For this interview, imagine that we are working with a simple database. Each row
// associates column names (strings) with integer values (for example: 5, 0, -3,
// and so on). Here's a table with three rows:
 
//  a   b   c   d
// ---------------
//  1   0   0   0
//  0   2   3   0
//  0   0   0   4
 
// We can choose to represent a database table in JSON as an array of objects. For
// example, the previous table could be written as:
 
// [ {"a": 1, "b": 0, "c": 0, "d": 0},
//   {"a": 0, "b": 2, "c": 3, "d": 0},
//   {"a": 0, "b": 0, "c": 0, "d": 4} ]







 
// (There is no need to use JSON in your solutions -- the notation is just used to
// introduce and explain the problems.)
 
// Write a function minByColumn that takes a database table (as above), along with a
// column, and returns the row that contains the minimum value for the given column.
// If a row doesn't have any value for the column, it should behave as though the
// value for that column was zero.
 
// In addition to writing this function, you should use tests to demonstrate that it's
// correct, either via an existing testing system or one you create.
 
// ## Examples
 
// table1 = [
//   {"a": 1},
//   {"a": 2},
//   {"a": 3}
// ]
// minByColumn(table1, "a") returns {"a": 1}
 
// table2 = [
//   {"a": 1, "b": 2},
//   {"a": 3, "b": 0}
// ]
// minByColumn(table2, "b") returns {"a": 3, "b": 0}
 
// table3 = [
//   {"a": 1, "b": -2},
//   {"a": 3}
// ]
// minByColumn(table3, "b") returns {"a": 1, "b": -2}



// In part 1 you may have noticed that it's possible for two rows to be "tied",
// meaning that either would be an acceptable return value from minByColumn.
// Consider:
 
// table4 = [
//   {"a": 1, "b": 2},
//   {"a": 1, "b": 3},
//   {"a": 1, "b": 4}
// ]
// minByColumn(table4, "a") returns ???
 
// Since all three rows have the same value for a, all three rows are acceptable
// candidates to be returned by minByColumn(table, "a").
 
// In these cases it would be nice if users could specify additional columns (e.g. "b")
// to use as tie-breakers. A tie-breaker would only apply in cases where multiple rows
// share the same minimum value. In `table4` above, the row {"a": 1, "b": 2} is
// tied for the smallest "a" value (1) and of all the tied candidates, it has the
// smallest "b" value (2). If two records had equal values for "a" and also for "b" then
// another tie-breaker (e.g. "c") could be used. When records are tied with respect to
// all columns, either record may be considered the minimum.
 
// Write a function minByOrder that takes a database table and a list of columns, and
// returns the row with the minimum column values using the tie-breaking logic above.
// If only one column is provided, then the behavior of minByOrder is identical to
// passing that column to minByColumn:
 
// minByOrder(table, [column]) is equal to minByColumn(table, column)
 
// As in Part 1, you should use tests to demonstrate that it's correct, either via an
// existing testing system or one you create.
 
// ## Examples
 
// table5 = [
//   {"x": 1, "y": 3},
//   {"x": 1, "y": 0}
// ]
// minByOrder(table5, ["x", "y"]) returns {"x": 1, "y": 0}
 
// table6 = [
//   {"x": 2, "y": 3},
//   {"x": 2, "y": 1},
//   {"x": 1, "y": 10}
// ]
// minByOrder(table6, ["x", "y"]) returns {"x": 1, "y": 10}
 
// table7 = [
//   {"x": 3, "y": -1, "z": 0},
//   {"x": 1, "y": 10, "z": 1},
//   {"x": 1, "y": 10, "z": 0}
// ]
// minByOrder(table7, ["x", "y", "z"]) returns {"x": 1, "y": 10, "z": 0}
 
// table8 = [
//   {"x": 1, "y": 2, "z": 3},
//   {"x": 2, "y": 2, "z": 2}
// ]
// minByOrder(table8, ["x", "y", "z"]) returns {"x": 1, "y": 2, "z": 3}



#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;


unordered_map<string, int> getMin(vector<unordered_map<string, int> > mp, string col, int &row)
{
  cout<<"getMin1\n";
   
   int r = -1;
   int val = INT_MAX;
   unordered_map<string, int> ans;
   
   for(int i=0; i<mp.size(); i++)
   {
  cout<<"getMin3\n";

      for(auto it: mp[i])
      {
      	  cout<<"getMin4\n";

          if(it.first.compare(col)==0)
          {
          	  cout<<"getMin5\n";

             if(it.second < val)
             {
               val = it.second; 
               r = i;
             }  
          }
      }
   }
  cout<<"getMin2\n";

   row = r;
  cout<<"getMin6\n";

   if(r ==-1)
      return ans;
  cout<<"getMin8\n";

   for(auto it:mp[r])
   {
   	  cout<<"getMin7\n";

      ans[it.first] = it.second; 
   }
   return ans;
}
  



unordered_map<string, int> getMinOrder(vector<unordered_map<string, int> > &mp, vector<string> &col)
{
  unordered_map<string, int> ans;
  int r;
  
  
  if(col.size()==0)
    return ans;
  if(col.size()==1)
    return getMin(mp, col[0],r);
 
  cout<<"getMinOrder\n";
  for(int i=0; i<col.size(); i++)
  {
      cout<<col[i]<<"\n";
      ans = getMin(mp, col[i], r);
      if(r==-1)
         return ans;
    
      bool flag = false;
      vector<int> new_row;
      //formulate new row
     int sz = mp.size(); 

      for(int j=0; j<sz; j++)
      {
         if(mp[j][col[i]] == ans[col[i]] && j !=r) 
         {
            flag = true;
            new_row.push_back(j);
         }
      }
      cout<<"flag:"<<flag<<"\n";
      if(!flag)
        return ans;
      //if we have found duplicate
      // add the last row
      new_row.push_back(r);
      vector<unordered_map<string, int> > new_mp;
      for(int j=0; j<new_row.size(); j++)
      {
            cout<<new_row[j]<<"\n";      	
      	new_mp.push_back(mp[new_row[j]]);
      }
      mp.clear();
      mp = new_mp;
  }
  return ans;
}
  
  



// To execute C++, please define "int main()"
int main() {
  //auto words = { "Hello, ", "World!", "\n" };
  // for (const string& word : words) {
  //   cout << word;
  // }
vector<unordered_map<string, int> > table1;  
//
  //   {"a": 1, "b": 2},
//   {"a": 3, "b": 0}
  
  /*
  // table5 = [
//   {"x": 1, "y": 3},
//   {"x": 1, "y": 0}
// ]
// minByOrder(table5, ["x", "y"]) returns {"x": 1, "y": 0}
  */

// table6 = [
//   {"x": 2, "y": 3},
//   {"x": 2, "y": 1},
//   {"x": 1, "y": 10}
// ]
// minByOrder(table6, ["x", "y"]) returns {"x": 1, "y": 10}
 
// table7 = [
//   {"x": 3, "y": -1, "z": 0},
//   {"x": 1, "y": 10, "z": 1},
//   {"x": 1, "y": 10, "z": 0}
// ]
// minByOrder(table7, ["x", "y", "z"]) returns {"x": 1, "y": 10, "z": 0}
 
// table8 = [
//   {"x": 1, "y": 2, "z": 3},
//   {"x": 2, "y": 2, "z": 2}
// ]
// minByOrder(table8, ["x", "y", "z"]) returns {"x": 1, "y": 2, "z": 3}

   unordered_map<string, int> mp;
   mp["x"] = 1;
   mp["y"] = 2;
   mp["z"] = 3;

   table1.push_back(mp); 
   mp.clear();
   mp["x"] = 2;
   mp["y"] = 2;
   mp["z"] = 2;   
   table1.push_back(mp);  

   // mp.clear();
   // mp["x"] = 1;
   // mp["y"] = 10;
   // mp["z"] = 0;

   // table1.push_back(mp);    

  unordered_map<string, int> ans;

  vector<string> colmns;
  colmns.push_back("x");
  colmns.push_back("y");
  colmns.push_back("z");
  
  ans = getMinOrder(table1, colmns);
  
  for(auto it: ans)
    cout<<it.first<<":"<<it.second<<"\n";  
  
  return 0;
}
