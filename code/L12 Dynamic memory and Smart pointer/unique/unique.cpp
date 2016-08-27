#include<memory>
using std::shared_ptr;

#include<string>
using std::string;

#include<iostream>
using std::endl; using std::cout;

int main()
{
	shared_ptr<string>p(new string("Larry"));
	shared_ptr<string>p2(p);		//two use of the allocated string
	string newVal("King");
	if (!p.unique())
		p.reset(new string(*p));		//we are not alone,allocate a new copy
	*p += newVal;	//now that we know that we are the only pointer,okay to change this pointer
	cout << *p << " " << *p2 << endl;
	getchar();
}