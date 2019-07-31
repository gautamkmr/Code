// set::lower_bound/upper_bound
#include <iostream>
#include <set>
using namespace std;

int main ()
{
  std::set<int> myset;
  std::set<int>::iterator itlow,itup;

  for (int i=1; i<10; i++) { 
      myset.insert(i*10); // 10 20 30 40 50 60 70 80 90
      cout<<i*10<<" ";
  }
  cout<<"\n";

  itlow=myset.lower_bound (30);             
  itup=myset.upper_bound (30);             

  cout<<"lower_bound(30)"<<*itlow<<"\n";
  cout<<"upper_bound(30)"<<*itup<<"\n";

  itlow=myset.lower_bound (45);                
  itup=myset.upper_bound (45);                 

  cout<<"lower_bound(45)"<<*itlow<<"\n";
  cout<<"upper_bound(45)"<<*itup<<"\n";

  cout<<"lower bound of x is val which satisfy x<=val \n";
  cout<<"upper bound of x is val which satisfy x<val \n";
  
  return 0;
}
