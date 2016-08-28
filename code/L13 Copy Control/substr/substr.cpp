#include<string>
using std::string;

#include<iostream>
using std::cout; using std::endl;

string::size_type
position(const string& a, const string& b, const string& c)
{
	return (a + b).find(c);
}

int main()
{
	string s1 = "a value", s2 = "another";
	auto x = position(s1, s2, "val");

	if (x == string::npos)
		cout << "not found" << endl;
	else if (x < s1.size())
		cout << "val is in the first parameter" << endl;
	else
		cout << "val is in the second parameter" << endl;

	auto n = (s1 + s2).find('v');
	cout << "n = " << n << endl;
	s1 + s2 = "Wow!";
	getchar();
}