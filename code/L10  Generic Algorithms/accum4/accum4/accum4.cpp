#include<iterator>
using std::istream_iterator;

#include<numeric>
using std::accumulate;

#include<iostream>
using std::endl; using std::cin; using std::cout;

int main()
{
	istream_iterator<int>in(cin), eof;
	cout << accumulate(in, eof, 0) << endl;
	getchar();	
}