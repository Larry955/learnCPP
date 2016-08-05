#include<iostream>
using std::cout; using std::endl;

#include<string>
using std::string;

int main()
{
	string name("AnnaBelle");
	auto pos1 = name.find("Anna");		//pos1 == 0
	cout << pos1 << endl;

	string lowercase("annabeele");
	pos1 = lowercase.find("Anna");		//pos1 == npos
	cout << pos1 << endl;
	system("pause");
}
