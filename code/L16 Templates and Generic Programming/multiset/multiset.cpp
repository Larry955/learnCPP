#include"Sales_data.h"

#include<unordered_set>
using std::unordered_multiset;

#include<functional>
using std::hash;

#include<iostream>
using std::cout; using std::endl; using std::cin;

#include<string>
using std::string;

#include<cstddef>
using std::size_t;

int main()
{
	unordered_multiset<Sales_data>sd;
	Sales_data item;
	while (cin >> item)
		sd.insert(item);
	cout << sd.size() << endl;
	for (auto iter = sd.cbegin(); iter != sd.cend(); ++iter)
		cout << *iter << endl;
	system("pause");
}