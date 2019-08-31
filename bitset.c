#include<string.h>
#include<iostream>
#include<vector>
using namespace std;

int main()
{

        vector<int> nums;
        nums.push_back(1); 
        nums.push_back(3);
        nums.push_back(6);
      
        bitset<15> bits(1);
        for (auto n : nums)
        {
          cout<<bits<<" ";
          bits |= bits << n;
          cout<<bits<<"\n";
        }
        return 0;// !(sum & 1) && bits[sum >> 1];
}
