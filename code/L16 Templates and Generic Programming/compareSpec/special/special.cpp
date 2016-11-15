#include<iostream>
using std::cout; using std::endl;

//declarations before definitions
template<typename T>void f(T);
template<typename T>void f(const T*);

template<typename T>void g(T);
template<typename T>void g(T*);

//definitions
template<typename T> void f(T)
{
	cout << "f(T)" << endl;
}
template<typename T>void f(const T*)
{
	cout << "f(const T*)" << endl;
}
template<typename T>void g(T)
{
	cout << "g(T)" << endl;
}
template<typename T>void g(T*)
{
	cout << "g(T*)" << endl;
}

int main()
{
	int i = 42;
	f(i);	//calls f(T),f(const T*) isn't viable
	
	f(&i);	//calls f(T),which is a exact match
		//f(const T*) requires a conversion

	g(i);	//calls g(T),g(T*) isn't viable
	
	g(&i);	//calls g(T*),both templates are viable
		//but g(T*) is more specialized
	int *p = &i;
	const int ci = 0, *p2 = &ci;
	g(42);//g(T)
	g(p);//g(T*)
	g(ci);//g(T)
	g(p2);//g(T*)

	f(42);//f(T)
	f(p);//f(T)
	f(ci);//f(T)
	f(p2);//f(constT*)

	system("pause");
}