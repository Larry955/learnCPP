#include<iterator>
using std::istream_iterator; using std::ostream_iterator;

#include<vector>
using std::vector;

#include<iostream>
using std::cin; using std::cout; using std::endl;

int main()
{
	vector<int>vec;
	istream_iterator<int>in_iter(cin), eof;		//read ints from cin
	while (in_iter != eof)
		vec.push_back(*in_iter++);
	ostream_iterator<int>out_iter(cout, " ");
	for (auto e : vec)
		out_iter = e;		//the assignment writes this element to cout
	cout << endl;
	getchar();
}