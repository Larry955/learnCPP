#include<iostream>
#include<cstring>
#include<list>
#include<map>
using namespace std;
int main()
{
	list<string> l;
	l.push_back("Hello");
	l.push_back("Larry");
	for (list<string>::iterator iter = l.begin(); iter != l.end(); ++iter)
		cout << (*iter).c_str()<<"\n";			//c_str是string类中的一个成员函数，它返回一个C风格的字符串  


	//map
	map<string, string>m;
	m.insert(pair<string, string>("Hello", "Larry King"));
	map<string, int>mi;
	mi.insert(pair<string, int>("difftype", 10));
	cout<<m.at("Hello").c_str()<<"\n";
	cout << mi.at("difftype") << "\n";
	
	map<char, string>mymap;
	mymap['a'] = "an element";
	mymap['b'] = "another element";
	mymap['c'] = "another element";
	
	cout << "mymap['a'] is " << mymap['a'].c_str() << "\n";
	cout << "mymap['b'] is " << mymap['b'].c_str() << "\n";
	cout << "mymap['c'] is " << mymap['c'].c_str() << "\n";
	cout << "mymap['d'] is " << mymap['d'].c_str() << "\n";
	cout << "mymap now contains " << mymap.size() << " elements" << "\n";
	system("pause");
}