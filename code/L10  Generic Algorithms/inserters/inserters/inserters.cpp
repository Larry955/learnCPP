#include<algorithm>
using std::copy;

#include<list>
using std::list;

#include<vector>
using std::vector;

#include<string>
using std::string;

#include<iostream>
using std::cout; using std::cin; using std::endl;

#include<iterator>
using std::inserter; using std::front_inserter;

void print(const string &label, const list<int>&lst)
{
	cout << label << endl;
	for (auto iter : lst)
		cout << iter << " ";
	cout << endl;
}

int main()
{
	list<int>lst = { 1, 2, 3, 4 };
	print("lst", lst);

	//after copy completes,lst2 contains 4 3 2 1
	list<int>lst2, lst3;		//empty list
	copy(lst.cbegin(), lst.cend(), front_inserter(lst2));

	//after copy completes,lst3 contains 1 2 3 4
	copy(lst.cbegin(), lst.cend(), inserter(lst3, lst3.begin()));

	print("lst2", lst2);
	print("lst3", lst3);

	vector<int>ivec = { 1, 2, 3, 4, 5 };
	list<int>new_lst = { 6, 7, 8, 9 };
	auto iter = new_lst.begin();
	copy(ivec.begin(), ivec.end(), inserter(new_lst, iter));
	print("new_lst", new_lst);
	getchar();
}