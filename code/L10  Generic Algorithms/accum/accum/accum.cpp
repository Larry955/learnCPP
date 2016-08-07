#include<vector>
using std::vector;

#include<string>
using std::string;

#include<algorithm>
using std::fill; using std::fill_n;

#include<numeric>
using std::accumulate;

#include<iterator>
using std::back_inserter;

#include<iostream>
using std::cout; using std::cin; using std::endl;

int main()
{
	vector<int>ivec(10);		//default initialized to 0
	fill(ivec.begin(), ivec.end(), 1);		//reset each element to 1

	//print elements in ivec
	auto iter = ivec.begin();
	while (iter != ivec.end())
		cout << *iter++ << " ";
	cout << endl;
	//sum the elements in ivec starting the summation with the value 0
	int sum = accumulate(ivec.begin(), ivec.end(), 0);
	cout << sum << endl;

	//set a subsequence of the container to 10
	fill(ivec.begin(), ivec.begin() + ivec.size() / 2, 10);
	cout << accumulate(ivec.begin(), ivec.end(), 0) << endl;

	//reset the same subsequence to 0
	fill_n(ivec.begin(), ivec.size() / 2, 0);
	cout << accumulate(ivec.begin(), ivec.end(), 0) << endl;

	//concatenates elements	in a vector of strings and store in sum
	vector<string>v;
	string s;
	while (cin >> s)
		v.push_back(s);
	string concat = accumulate(v.begin(), v.end(), string(""));
	cout << concat << endl;
	getchar();
}