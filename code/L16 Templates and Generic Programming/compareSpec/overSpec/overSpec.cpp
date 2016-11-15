#include<iostream>
using std::cout; using std::endl;

#include<cstring>
using std::strcmp;

//first version: can compare any two types
template<typename T> int compare(const T&, const T&);

//second version to handle string literals
template<unsigned N, unsigned M>
int compare(const char(&)[N], const char(&)[M]);

//specialized version of the first template,handles character arrays
template<>
int compare(const char* const&, const char* const&);

template<typename T>
int compare(const T &v1, const T &v2)
{
	cout << "base template " << endl;
	if (v1 < v2)return -1;
	if (v2 < v1)return 1;
	return 0;
}

template<unsigned N, unsigned M>
int compare(const char(&p1)[N], const char(&p2)[M])
{
	cout << "array template" << endl;
	return strcmp(p1, p2);
}

template<>
int compare(const char* const& p1, const char* const& p2)
{
	cout << "specialized template" << endl;
	return strcmp(p1, p2);
}

int main()
{
	const char* p1 = "hi";
	const char* p2 = "mom";
	cout<<compare("hi", "mom")<<endl;	//array template: call compare(const char(&)[N],const char(&)[M])
	cout << compare(p1, p2) << endl;		//specialized template: call compare(const char* const&,const char* consr&)
	system("pause");
}