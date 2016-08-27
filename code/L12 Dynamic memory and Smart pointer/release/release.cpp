#include<memory>
using std::unique_ptr;

#include<string>
using std::string;

#include<iostream>
using std::endl; using std::cout;

int main()
{
	unique_ptr<string>p1(new string("Larry"));

	//transfers ownership from p1(which points to Larry) to p2
	unique_ptr<string>p2(p1.release());	//release makes p1 null
	cout << *p2 << endl;		//prints Larry

	unique_ptr<string>p3(new string("King"));

	//release deletes the memory to which p2 had pointed
	//and transfers owner from p3 to p2
	p2.reset(p3.release());	
	cout << *p2 << endl;	//p2 prints King

	//p1 and p3 is null
	if (p1)
		cout << "p1 is not null?" << endl;
	if (p3)
		cout << "p3 is not null?" << endl;
	cout << *p2 << endl;
	getchar();
}
