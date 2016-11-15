#include<iostream>
using std::cout; using std::endl;

#include<functional>
using std::less;

#include<cstring>
using std::strcmp;

template<typename T>
int compare(const T &t1, const T &t2)
{
	cout << "compare(T)" << "\t";
	if (less<T>()(t1, t2))return -1;
	if (less<T>()(t2, t1))return 1;
	return 0;
}

template<unsigned N,unsigned M>
int compare(const char (&p1)[N], const char (&p2)[M])
{
	cout << "compare(const char arrays)" << "\t";
	return strcmp(p1, p2);
}

template<>
int compare(const char* const& p1, const char* const& p2)
{
	cout << "compare(const char* const)\t";
	return strcmp(p1, p2);
}

int main()
{
	int *p1 = new int(42);
	int *p2 = new int(45);

	//because we are comparing pointer values,the result of
	//this call may vary each time the program is run
	cout << compare(*p1, *p2) << endl;	//call compare(T)
	cout << compare(p1, p2) << endl;		//call compare(T)

	cout << strcmp("hi", "mom") << endl;
	cout << compare("hi", "mom") << endl;	//call compare(const char arrays)

	const char* cp1 = "hi";
	const char* cp2 = "mom";
	cout << compare(cp1, cp2) << endl;	//call compare(const char* const)

	system("pause");
}