#include<iostream>
using std::cerr; using std::cin; using std::endl;	using std::cout;
using std::istream; using std::ostream;

#include<vector>
using std::vector;

#include<string>
using std::string;

#include<algorithm>
using std::for_each;

class PrintString{
public:
	PrintString(ostream &o = cout, char c = ' ') :
		os(o), sep(c){}
	void operator()(string &s){ os << s << sep; }
private:
	ostream &os;	//stream on which to write
	char sep;		//character to print after each output
};

class ReadLine{
public:
	ReadLine() = delete;
	ReadLine(istream &i) :is(i){ }
	bool operator()(string &s)const{
		//return getline(is, s);
	}
private:
	istream &is;
};

int main()
{
	vector<string>vs;
	ReadLine rl(cin);
	string s;
	while (getline(cin,s)){
		vs.push_back(s);
	}
	cout << "read: " << vs.size() << " elements" << endl;
	PrintString printer;	//uses the defaults,print to cout
	printer(s);

	PrintString errors(cerr, '\n');
	errors(s);	//prints s followed by a newline on cerr

	cerr << "for_each printing to cerr" << endl;
	for_each(vs.begin(), vs.end(), PrintString(cerr, '\n'));
	system("pause");
}
