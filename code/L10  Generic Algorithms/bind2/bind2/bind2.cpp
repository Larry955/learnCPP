#include<algorithm>
using std::for_each;

#include<functional>
using std::bind; using std::ref;
using namespace std::placeholders;

#include<iterator>
using std::istream_iterator;

#include<vector>
using std::vector;

#include<string>
using std::string;

#include<iostream>
using std::cout; using std::cin; using std::endl;
using std::ostream;

#include<fstream>
using std::ifstream; using std::ofstream;


ostream &print(ostream &os, const string &s, char c)
{
	return os << s << c;
}

int main()
{
	string s;
	vector<string>words;
	while (cin >> s)
		words.push_back(s);

	for_each(words.begin(), words.end(),
		bind(print, ref(cout), _1, ' '));
	cout << endl;

	ofstream os("outFile1");
	for_each(words.begin(), words.end(),
		bind(print, ref(os), _1, ' '));
	os << endl;

	ifstream is("outFile1");
	istream_iterator<string>in(is), eof;
	for_each(in, eof, bind(print, ref(cout), _1, '\n'));
	cout << endl; 
	getchar();
}