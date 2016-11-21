#include"debug_rep.h"

int main()
{
	vector<int>v = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	string s("hello");
	cout << debug_rep(v)<<endl;
	cout << debug_rep(s) << endl;		//string debug_rep(const string&)
	cout << debug_rep("hi") << endl;		//string debug_rep(const char*)
	cout << debug_rep(&v[0]) << endl;		//string debug_rep(T*)
	cout << debug_rep(&s) << endl;		//string debug_rep(T*)

	const string *sp = &s;
	cout << debug_rep(sp)<<endl;			//string debug_rep(T*),need a convert from nonconst to const 

	char carr[] = "larry";				//calls pointer versions if no overloads
	cout << debug_rep(carr)<<endl;		//string debug_rep(char*)
	vector<string>handsome = { "Larry", "King" };
	cout << debug_rep(handsome) << endl;	//string debug_rep(const vector<T>&)
	vector<const char*>handsome2 = { "Larry", "King" };
	cout << debug_rep(handsome2) << endl;//string debug_rep(const vector<T>&)
	cout << debug_rep(s) << endl;
	s += "larry";
	cout << debug_rep(s) << endl;		//string debug_rep(const string&)
	s += "\\king\"xixi";
	cout << debug_rep(s) << endl;		//string debug_rep(const string&)

	cout << debug_rep("hello,dear larry") << endl;//string debug_rep(const char*)

	s = "hi";
	const char *cp = "Larry";
	char arr[] = "King";

	cout << debug_rep(s) << endl;
	cout << debug_rep(cp) << endl;
	cout << debug_rep(arr) << endl;
	cout << debug_rep(&s) << endl;

	system("pause");
}