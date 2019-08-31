// erasing from multiset
#include <iostream>
#include <set>

int main ()
{
  std::multiset<int> mymultiset;
  std::multiset<int>::iterator it;

  // insert some values:
  mymultiset.insert (40);                            // 40
  for (int i=1; i<7; i++) mymultiset.insert(i*10);   // 10 20 30 40 40 50 60

  std::cout << "mymultiset contains:";
  for (it=mymultiset.begin(); it!=mymultiset.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  mymultiset.erase(mymultiset.find(40));

  std::cout << "mymultiset contains:";
  for (it=mymultiset.begin(); it!=mymultiset.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
