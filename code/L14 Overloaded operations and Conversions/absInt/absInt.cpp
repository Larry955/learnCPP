#include<iostream>
using std::cin; using std::cout; using std::endl;

#include<iterator>
using std::back_inserter;

#include<vector>
using std::vector;

#include<algorithm>
using std::transform;

struct absInt{
	int operator()(int i)const{
		return i < 0 ? -i : i;
	}
};

int main()
{
	int i = -42;
	absInt absObj;	//object that has	a function-call operator
	unsigned ui = absObj(i);	//pass i to absObj.operator()
	cout << i << " " << ui << endl;

	//store collection of positive and negative integers in vi
	vector<int>vi;
	while (cin >> i)
		vi.push_back(i);

	//call absInt to store absolute values of those ints in vu
	vector<int>vu;
	transform(vi.begin(), vi.end(), back_inserter(vu), absInt());

	//print contents of vu using a lambda
	for_each(vu.begin(), vu.end(), [](int i){cout << i << " "; });
	cout << endl;

	vector<int>vu2;
	transform(vi.begin(), vi.end(), back_inserter(vu2),
		[](int i){return i < 0 ? -i : i; });
	if (vu == vu2)
		cout << "as expected" << endl;
	else{
		cout << "something's wrong,vectors differ" << endl;
		for_each(vu.begin(), vu.end(), [](unsigned i){cout << i << " "; });
	}
	cout << endl;
	system("pause");

}