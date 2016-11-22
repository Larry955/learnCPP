#include<cstddef>
using std::size_t;

#include<iostream>
using std::cout; using std::endl;

#include<string>
using std::string;

#include<memory>
using std::shared_ptr; using std::unique_ptr;

#include"DebugDelete.h"

int main()
{
	double *p = new double;
	DebugDelete d("plain pointer");
	d(p);		//calls DebugDelete::operator(double*),which deletes p

	int *ip = new int;
	//calls operator(int*) on a temporary DebugDelete object
	DebugDelete("plain pointer")(ip);

	//destroying the object to which upi points
	//instantiates DebugDelete::operator()<int>(int*)
	unique_ptr<int, DebugDelete>upi(new int, DebugDelete());

	//destroying the object to which ups points
	//instantiates DebugDelete::operator()<string>(string*)
	unique_ptr<string, DebugDelete>ups(new string, DebugDelete());

	//illustrate other types using DebugDelete as their deleter
	shared_ptr<int>sps(new int(42), DebugDelete("shared_ptr"));

	system("pause");
}