#include<iostream>
#include<map>
using namespace std;


class MyCalendarThree {
    map<int, int> timeline;
public:
    int book(int s, int e) {
        timeline[s]++; // 1 new event will be starting at [s]
        timeline[e]--; // 1 new event will be ending at [e];
        int ongoing = 0, k = 0;
        cout<<"book:"<<timeline.size()<<"\n";
        for (auto t: timeline){
            k = max(k, ongoing += t.second);
            cout<<"ongoing"<<ongoing<<"\n";
        }
        return k;
    }
};

int main()
{
	MyCalendarThree obj;
   cout<<obj.book(10, 20)<<"\n"; // returns 1
   cout<<obj.book(50, 60)<<"\n"; // returns 1
   // MyCalendarThree.book(10, 40); // returns 2
   // MyCalendarThree.book(5, 15); // returns 3
   // MyCalendarThree.book(5, 10); // returns 3
   // MyCalendarThree.book(25, 55); // returns 3
   return 0;
}
