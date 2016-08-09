#include<algorithm>
using std::copy;

#include<iterator>
using std::istream_iterator; using std::ostream_iterator;

#include<vector>
using std::vector;

#include<iostream>
using std::cin; using std::cout; using std::endl;

int main()
{
	vector<int>ivec;
	istream_iterator<int>in_iter(cin), eof;		//read ints from cin
	ostream_iterator<int>out_iter(cout, " ");	//we will use this iterator to print the content of ivec
	
	//use in_iter to read cin storing what we read in ivec
	while (in_iter != eof)						//while there are vaild input to read
		ivec.push_back(*in_iter++);
		//postfix increment reads the stream and
		//returns the old vaule of the iterator
		//we deference that iterator to get
		//that previous value read from the stream
	copy(ivec.begin(), ivec.end(), out_iter);		
	cout << endl;

	//alternative way to print the ceontents of ivec
	for (auto e : ivec)
		*out_iter++ = e;		//the assignment writes element to cout,equivalent to "out_iter = e;"
	cout << endl;
	getchar();
}