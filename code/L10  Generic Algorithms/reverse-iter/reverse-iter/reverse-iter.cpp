#include<algorithm>
using std::copy; using std::sort;

#include<vector>
using std::vector;

#include<iterator>
using std::istream_iterator; using std::ostream_iterator;

#include<iostream>
using std::cout; using std::cin; using std::endl;

int main()
{
	vector<int>vec;
	istream_iterator<int>in(cin), eof;
	copy(in, eof, back_inserter(vec));

	sort(vec.begin(), vec.end());	//sort vec in normal order
	vector<int>vec2(vec);			//vec2 is a copy of vec

	//sorts in reverse:puts the smallest element at the end of vec
	sort(vec.rbegin(), vec.rend());

	//prints vec
	ostream_iterator<int>out(cout, " ");
	copy(vec.begin(), vec.end(), out);	//reverse sort
	cout << endl;

	//pritns vec2
	copy(vec2.begin(), vec2.end(), out);	//forward sort
	cout << endl;

	//it refers to the first value in vec
	auto it = vec.begin();

	//rev_it refers one before the first value in vec
	vector<int>::reverse_iterator rev_it(it);
	cout << *(rev_it.base()) << endl;	//prints first element in vec

	//ways to print value at beginning of vec through it and rev_it
	cout << *it << endl;
	cout << *(rev_it.base())<<endl;
	cout << *(rev_it - 1) << endl;
	getchar();
}