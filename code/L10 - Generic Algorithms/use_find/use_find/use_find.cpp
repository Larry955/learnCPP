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
	int *result = find(begin(ia), end(ia), value);
}