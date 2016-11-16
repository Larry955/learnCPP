#include<iostream>
using std::cout; using std::endl;

template<typename T>
T accum(const T&t)
{
	return t;
}

template<typename T,typename ...Args>
T accum(const T &t, Args...args)
{
	return t + accum(args...);
}

int h()
{
	return 42;
}

template<typename...Args>int h(int t, Args...args)
{
	return t + h(args...);	//sum of all the values in args plus 42
}

void f(int i = 0, int j = 0, int k = 0, int l = 0)
{
	cout << i << "+"
		<< j << "+"
		<< k << "+"
		<< l << "="
		<< i + j + k + l << endl;
}

template<typename...Args>void g(Args...args)
{
	cout << sizeof...(Args) << endl;	//number of type parameters
	cout << sizeof...(args) << endl;	//number of function parameters
	//call f passing it the arguments from args
	f(args...);	//f(a1,a2,...an)
	//call h passing it the arguments from args
	cout << h(args...) << endl;	//h(a1,a2,...an)

	//the pattern is h(x)
	//the expansion calls each h on each argument in args
	f(h(args)...);	//f(h(a1),h(a2),...h(an))

	//args is expanded in the call to h
	f(h(args...));	//f(h(a1),h(a2),...h(an))

	f(h(5, 6, 7, 8) + args...);	//f(h(5,6,7,8)+a1+h(5,6,7,8)+a2
						//+...+h(5,6,7,8)+an)
}

int main()
{
	cout << accum(1, 2, 3, 4)<<endl;
	g(1, 2, 3, 4);
	system("pause");
}
