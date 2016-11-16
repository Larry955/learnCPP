#include<iostream>
using std::cout; using std::endl;
#include<utility>

//template that takes a callable and two parameters
//and calls the given callable with the parameters in flip
template<typename F,typename T1,typename T2>
void flip(F f, T1 &&t1, T2 &&t2)
{
	f(std::forward<T2>(t2), std::forward<T1>(t1));
}

void f(int i, int &j)
{
	cout << i << " " << ++j << endl;
}

void g(int &&i, int &j)
{
	cout << i << " " << j << endl;
}

//flip1 is an incomplete implementation:top-level const and references are lost
template<typename F,typename T1,typename T2>
void flip1(F f, T1 t1, T2 t2)
{
	f(t2, t1);
}

template<typename F,typename T1,typename T2>
void flip2(F f, T1 &&t1, T2 &&t2)
{
	f(t2, t1);
}

int main()
{
	int i = 0, j = 0, k = 0, l = 0;
	cout << i << " " << j << " " << k << " " << l << endl;

	f(42, i);	//f changes its argument i
	flip1(f, j, 42); //f called through flip1 leaves j unchanged
	flip2(f, k, 42);	//k is changed

	g(1, i);	
	flip(g, j, 42);
	cout << i << " " << j << " " << k << " " << l << endl;	//1 0 1 0
	
	system("pause");
}