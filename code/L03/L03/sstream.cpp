#include<iostream>
#include<cstring>
#include<sstream>
using namespace std;

int main()
{
	string s = "Larry";
	s += " King";
	stringstream ss;
	ss << " is a "; //stringstream override the operator <<
	ss << " handsome";
	ss << " boy.";
	ss << "His age is ";
	ss << 21;	//stringsream object can hold almost all the basic type in Cpp
	cout << s
		<<ss.str() << endl;	//to access to stringstream object,we must call str() function  
	system("pause");
}