#include<iostream>
using std::cout; using std::endl;

#include<string>
using std::string;

#include<stdexcept>
using std::out_of_range;

int main()
{
	try{
		string s("hello world");
		string s2 = s.substr(0, 5);
		cout << s2 << endl;		//prints hello
		cout << s.substr(6) << endl;		//prints world
		cout << s.substr(6, 11) << endl;	//prints world
		cout << s.substr(12) << endl;		//throws out_of_range
	}
	catch (out_of_range){ cout << "caught out_of_range" << endl; }

	system("pause");
}
