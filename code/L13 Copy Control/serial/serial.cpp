#include<iostream>
using std::endl; using std::cout;

#include<cstddef>
using std::size_t;

struct  numbered
{
	static size_t sn;
	numbered() :mysn(sn++){}
	numbered(const numbered&) :mysn(sn++){}
	numbered& operator=(const numbered &) { return *this; }
	size_t mysn;
};

size_t numbered::sn = 0;

void f(numbered s){ cout << s.mysn<< endl; }
int main()
{
	numbered a, b = a, c = b;
	f(a); f(b); f(c);	//why print 3 4 5?
	getchar();
}