#include<iostream>
using namespace std;
 
class Test
{
private:
    int data;
public:
    Test() { data = 0; }
    int getData() { return data; }
};
 
int main()
{
    Test t;
    int* ptr = (int*)&t;
    *ptr = 10;
    cout << t.getData();
    return 0;
}
