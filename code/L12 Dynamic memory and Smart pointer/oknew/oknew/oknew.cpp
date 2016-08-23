#include<vector>
using std::vector;

#include<string>
using std::string;

#include<cstddef>
using std::size_t;

#include<iostream>
using std::endl; using std::cout;

#include<new>
using std::nothrow;

size_t get_size(){ return 42; }

int main()
{
	//if allocation fails,new returns a null pointer
	int *p1 = new int;	//if allocation fails,new throws std::bad_alloc
	int *p2 = new (nothrow)int;		//if alloction fails,new returns a null pointer

	int i0;		//named,uninitialized int variable

	int *p0 = new int;		//p0 points to a dynamically allocated
							//unmamed,uninitialized int
	delete p0;				//frees the memory to which p0 points

	//named initialized variables
	int i(1024);		//variable i is 1024
	string s(10, '9');	//variable s is "9999999999"
	vector<int> v = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	//unnamed,initialized dynamically allocated objects
	int *pi = new int(1024);		//object to which *pi points is 1024
	string *ps = new string(10, '9');	//object to which *pv points is "9999999999"
	//vector with 10 elements with values from 0 to 9
	vector<int> *pv = new vector < int > { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	cout << "*pi: " << *pi
		<< "\ti: " << i << endl
		<< "*ps: " << *ps
		<< "\ts: " << s << endl;

	for (auto b = pv->cbegin(); b != pv->cend(); ++b)
		cout << *b << " ";
	cout << endl;

	//when we are done using the memory must delete the pointers
	delete pi;
	delete ps;
	delete pv;

	//call get_size() to determine how many ints to allocate
	int *pia = new int[get_size()];		//*pia points to the first of these ints
	delete[]pia;	//brackets used to delete pointer to element in an array
	typedef int arrT[42];	//arrT names the type array of 42 ints
	int *p = new arrT;		//alloctes an array of 42 ints;p points to the first one
	delete[]p;				//brackets are necessary because we allocate an array
	
	getchar();
}