#include<algorithm>
using std::find; using std::find_if; using std::for_each;
using std::remove_copy_if; using std::reverse_copy;
using std::reverse;

#include<vector>
using std::vector;

#include<iterator>
using std::back_inserter;

#include<iostream>
using std::endl; using std::cout;

int main()
{
	vector<int>v1 = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	vector<int>v2;
	vector<int>v3 = v1;

	find(v1.begin(), v1.end(), 42);		//find first element equals to 42
	find_if(v1.begin(), v1.end(),			//find first odd element
		[](int i){return i % 2; });	

	//puts elements in v1 into reverse order
	reverse(v1.begin(), v1.end());
	v1 = v3;		//restore original data

	//copies elements from v1 into v2 in reverse order,v1 is unchanged;
	reverse_copy(v1.begin(), v1.end(), back_inserter(v2));

	for (auto i : v1)		//prints 0 ...9
 		cout << i << " ";
	cout << endl;

	for (auto i : v2)		//prints 9...0
		cout << i << " ";
	cout << endl;

	//remove odd elements from v1
	auto it = remove_if(v1.begin(), v1.end(),
		[](int i){return i % 2; });

	//prints 0 2 4 6 8
	for_each(v1.begin(), v1.end(),
		[](int i){cout << i << " "; });
	cout << endl;

	v1 = v3;		//restore original data
	v2.clear();		//make v2 empty again

	//copies only even the elements from v1 into v2;v1 is unchanged
	remove_copy_if(v1.begin(), v1.end(), back_inserter(v2),
		[](int i){return i % 2; });
	for (auto i : v2)
		cout << i << " ";		//prints 0 2 4 6 8
	cout << endl;
	for (auto i : v1)
		cout << i << " ";		//prints 0 ...9
	cout << endl;
	getchar();
}