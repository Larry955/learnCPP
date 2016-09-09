#include"StrVec.h"

#include<iostream>
using std::cout; using std::endl;

#include<string>
using std::string;

#include<fstream>
using std::ifstream;

void print(const StrVec &svec)
{
	for (auto it = svec.beg(); it != svec.end(); ++it)
		cout << it << " ";
	cout << endl;
}

StrVec getVec(ifstream &is)
{
	StrVec svec;
	string s;
	while (is >> s)
		svec.push_back(s);
	return svec;
}

int main()
{
	StrVec sv = { "one", "two", "three" };

	if (sv[0].empty())
		cout << "None";

	ifstream in("data.txt");
	if (!in)
		std::cerr << "can't find the file!";

	StrVec svec = getVec(in);
	print(svec);
	in.close();

	cout << "copy " << svec.size() << endl;
	auto svec2 = svec;
	print(svec2);

	cout << "assign" << endl;
	StrVec svec3;
	svec3 = svec2;
	print(svec3);

	StrVec v1, v2;
	v1 = v2;

	in.open("data.txt");
	v2 = getVec(in);
	in.close();

	StrVec vec;
	string s = "some string or another";
	vec.push_back(s);
	vec.push_back("done");

	s = "the end";
	vec.emplace_back(10, 'c');
	vec.emplace_back(s);
	string s1 = "the begining", s2 = s;
	vec.emplace_back(s1 + s2);

	getchar();
}