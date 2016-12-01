#include"Vector.h"
#include<iostream>
#include<string>
using namespace std;

void print(const Vector<string> &svec)
{
	for (auto it : svec)
		cout << it << " ";
	cout << endl;
}

Vector<string> getVec(istream &is)
{
	Vector<string>svec;
	string s;
	while (is>>s)
		svec.push_back(s);
	return svec;
}

int main()
{ 
	Vector<string>svec = getVec(cin);
	print(svec);
	cout << "copy " << svec.size() << endl;
	auto svec2 = svec;
	print(svec2);

	cout << "assign " << endl;
	Vector<string>svec3;
	svec3 = svec2;
	print(svec3);

	Vector<string>v1, v2;
	Vector<string> getVec(istream&);
	//v1 = v2;		//copy assignment
	v2 = getVec(cin);	//move assignment
	print(v2);
	system("pause");
}