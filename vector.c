/*
	Suppose that we want to input an unknown number of numbers and then
	print them out forwards and then backwards, using a vector. We will
	push ints onto the back of a vector called v. We will then print 
	each item in v in turn. Finally we will print the vector backwards.
	You can download the code from [ Vector.cpp ] but here are the 
	highlights. First we must declare the facilities we want to use
*/
#include <iostream>
#include <vector>
using namespace std;
void print( const vector<int>& ) ;//utility function outputs a vector of ints
void print_backwards( const vector<int> &);

/*Then we describe the main program: */
int main()
{
	vector<int> v;
	int number;

	cout <<"Input some numbers and then end the input\n";
	while(cin>>number){
		v.push_back(number);
	}//while(more)

	print(v);
	print_backwards(v);

}//main

/* Finally the two procedures that print out the data: */
void print_backwards( const vector<int> &a)
{
	for(int i=a.size()-1; i>=0; --i)
		cout << a[i] << " ";

	cout << endl;
	cout << "----------------"<<endl;

}//print_backwards
void print( const vector<int>& a)
{
	for(int i=0; i<a.size(); ++i)
		cout << a[i] << " ";

	cout << endl;
	cout << "----------------"<<endl;

}//print


