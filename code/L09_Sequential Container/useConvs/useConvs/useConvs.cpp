#include"Version_test.h"

#include<string>
using std::string;
#ifdef STRING_NUMERIC_CONVS
using std::to_string; using std::stod;
#endif
#include<iostream>
using std::cout; using std::endl;

int main()
{
	int i = 42;
	//converts int i to its character representation 
	string s = to_string(i);
	cout << "i = " << i << "s = " << s << endl;
}