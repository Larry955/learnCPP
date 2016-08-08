#include<iterator>
using std::istream_iterator; using std::ostream_iterator;

#include<vector>
using std::vector;

#include<string>
using std::string;

#include<algorithm>
using std::copy; using std::sort; using std::unique_copy;

#include<fstream>
using std::ofstream;

#include<iostream>
using std::cout; using std::endl; using std::cin;

int main()
{
	istream_iterator<int>int_it(cin);		//reads ints from cin
	istream_iterator<int>int_eof;			//end iterator value
	vector<int>v(int_it, int_eof);			//initialize v by reading cin

	sort(v.begin(), v.end());
	ostream_iterator<int>out(cout, " ");		//writes ints to cout
	unique_copy(v.begin(), v.end(), out);		//write unique elements to cout
	cout << endl;							//write a newline after the output
	ofstream out_file("data");		//writes int to named file
	ostream_iterator<int>out_iter(out_file, " ");
	copy(v.begin(), v.end(), out_iter);
	out_file << endl;		//write a newline at end of the file
	getchar();
}