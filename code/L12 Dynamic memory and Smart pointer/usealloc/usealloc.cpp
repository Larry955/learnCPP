#include<cstddef>
using std::size_t;

#include<string>
using std::string;

#include<memory>
using std::allocator;

#include<iostream>
using std::cout; using std::endl;

#include<fstream>
using std::ifstream;

int main()
{
	const size_t n = 100;
	allocator<string>alloc;		//object that can allocate strings
	auto p = alloc.allocate(n);		//allocate n unconstructed strings

	auto q = p;		//q will point to one past last constructed element
	alloc.construct(q++);		//*q is the empty string
	cout << *(q - 1) << endl;

	alloc.construct(q++, 10, 'c');		//*q is cccccccccc
	cout << *(q - 1) << endl;

	alloc.construct(q++, "hi!");		//*q is hi!
	cout << *(q - 1) << endl;

	cout << *p << endl;		//ok:use the string operator
	while (q != p)
		alloc.destroy(--q);		//free the strings we actually allocated

	alloc.deallocate(p,n);		//return the memory we returned

	p = alloc.allocate(n);		//allocate n unconstructed strings
	string s;
	q = p;						//q points to the memory for first string
	ifstream in("data.txt");		
	while (in >> s && q != p + n)
		alloc.construct(q++, s);		//construct only as many strings as we need
	size_t size = q - p;				//remember how many strings we read

	cout << "read " << size << " strings" << endl;

	for (q = p + size - 1; q != p; --q)
		alloc.destroy(q);		//fred the strings we allocated
	alloc.deallocate(p, n);		//return the memeory we allocated 

	in.close();
	
	//use the array

	in.open("data.txt");
	p = new string[n];		//construct n empty strings
	q = p;					//q points to the first string
	while (in >> s && q != p + n)
		*q++ = s;			//assign a new value to *q
	size = q - p;

	cout << "read " << size << " strings" << endl;
	
	//use the array

	delete[] p;
	getchar();
}