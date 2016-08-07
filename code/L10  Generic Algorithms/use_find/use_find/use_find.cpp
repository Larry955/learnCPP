#include<algorithm>
using std::find;

#include<list>
using std::list;

#include<string>
using std::string;

#include<vector>
using std::vector;

#include<iostream>
using std::cout; using std::endl;

int main()
{
	int ia[] = { 27, 210, 87, 14, 27, 83, 127 };
	int value = 83;

	//search starting from ia[0] up to but not including ia[6]
	auto result = find(ia, ia + 6, value);	
	cout << "The value " << (result == ia + 7 ? "is not present" : "is present") << endl;

	//initial the vector with some values
	vector<int>vec = { 27, 210, 87, 14, 27, 83, 127 };
	int val = 42;	//value we will look for

	//result2 will denote the element we want if it's vec
	//or vec.cend() if not
	auto result2 = find(vec.cbegin(), vec.cend(), val);
	cout << "The value " << val
		<< (result2 == vec.cend() ? " is not present" : "is present") << endl;

	//now use find to look in a list of strings
	list<string>lst = { "val1", "val2", "val3" };

	string sval = "a value";		//value we will look for
	//this call to find looks through string elements in a list
	auto result3 = find(lst.begin(), lst.end(), sval);
	cout << "The value " << sval
		<< (result3 == lst.end() ? " is not present" : "is present") << endl;

	getchar();
}