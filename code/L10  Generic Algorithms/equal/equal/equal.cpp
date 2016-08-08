#include<iostream>
using std::cout; using std::endl;

#include<list>
using std::list;

#include<string>
using std::string;

#include<vector>
using std::vector;

int main()
{
	list<const char*>roster1;
	vector<string>roster2;
	roster2 = { "hello", "larry", "king" };
	roster1 = { "hello", "larry" };	
	auto b =
		//roster2 should have at least as many elements as roster1
		equal(roster1.cbegin(), roster2.cend(), roster2.cbegin());
	(b) ? cout << "true" : cout << "false";
	cout << endl;
	getchar();
}