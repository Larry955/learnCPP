#include<vector>
using std::vector;

#include<string>
using std::string;

#include<iostream>
using std::cout; using std::endl;

int main()
{
	string s = "some string", s2 = "some other string";
	//equivalent ways to insert all the characters from s2 at begining of s
	//insert iterator range before s.begin()
	s.insert(s.begin(), s2.begin(), s2.end());
	cout << "insert iterators version:	" << s << endl;

	s = "some string";
	s.insert(0, s2);	//insert a copy of s2 before position 0 in s
	cout << "insert string at given position:	" << s << endl;

	s = "some string";
	//insert s2.size() characters from s2 starting s2[0] before s[0]
	s.insert(0, s2, 0, s2.size());
	cout << "insert position version:	" << s << endl;

	s = "";		//s is empty now
	vector<char>c_vec(1, 'a');
	//insert characters from c_vec to s
	s.insert(s.begin(), c_vec.begin(), c_vec.end());
	s.insert(s.size(), 5, '!');		//add five exclamation points at the end of s
	cout << s << endl;

	s.erase(s.size() - 5, 5);		//erase the last five characters from s
	cout << s << endl;

	s = "";		//s is now empty
	const char *cp = "Stately,plump Buck";
	s.assign(cp, 7);		//s == "Stately"
	cout << s << endl;
	s.insert(s.size(), cp + 7);		//s == "Stately,plump Buck"
	cout << s << endl;

	s = "C++ primer";		//reset s2 and s
	s2 = s;					//to "C++ primer"
	s.insert(s.size(), " 5th Ed.");		//s == "C++ primer 5th Ed."
	s2.append(" 5th Ed.");		//equivalent:appends "5th Ed." to s2
	cout << s << " " << s2 << endl;

	//two ways to replace "5th" by "6th"
	//1.erase and insert
	s.erase(11, 3);		//s == "C++ primer Ed."
	s.insert(11, "6th");//s == "C++ primer 6th Ed."

	//2.use replace
	//erase 3 characters starting at position 11
	//and then insert "6th"
	s2.replace(11, 3, "6th");		//equivalent: s == s2
	cout << s << " " << s2 << endl;

	//two ways to replace "6th" by"Sixth"
	//1.use replace if we konw where the string we want to replace is
	s.replace(11, 3, "Sixth");	//s = "C++ primer Sixth Ed."

	//2.call find first to get position from which to replace
	auto pos = s2.find("6th");
	if (pos != string::npos)
		s2.replace(pos, 3, "Sixth");
	else
		cout << "something's wrong,s2 is: " << s2 << endl;
	cout << s << " " << s2 << endl;

	system("pause");
}