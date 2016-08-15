#include<vector>
using std::vector;

#include<string>
using std::string;

#include<map>
using std::map;

#include<set>
using std::set; using std::multiset;

#include<iostream>
using std::cout; using std::endl;

int main()
{
	//defines a vector with 20 elements
	//hold two copies of each number from 0 to 9
	vector<int>ivec;
	for (vector<int>::size_type ix = 0; ix != 10; ++ix){
		ivec.push_back(ix);
		ivec.push_back(ix);		//duplicate copies of each number
	}

	//iset holds unique elements from ivec,miset holds all 20 elements
	set<int>iset(ivec.cbegin(), ivec.cend());
	multiset<int>miset(ivec.cbegin(), ivec.cend());

	cout << ivec.size() << endl;	//print 20
	cout << iset.size() << endl;	//print 10
	cout << miset.size() << endl;	//print 20

	iset.find(1);	//returns an iterator that refers to the element with key == 1
	iset.find(11);	//return the iterator == iset.end()
	iset.count(1);	//return 1
	iset.count(11);	//return 0

	//returns an iterator to the first element with key == 1
	miset.find(1);
	miset.find(11);	//returns the iterator == miset.end()
	miset.count(1);	//returns 2
	miset.count(11);	//returns 0

	set<string>set1;	//empty set
	set1.insert("the");		//set1 now has one element
	set1.insert("and");		//set1 now has two element

	ivec = { 2, 4, 6, 8, 2, 4, 6, 8 };		//ivec now has eight element
	set<int>set2;	//empty set
	set2.insert(ivec.cbegin(), ivec.cend());	//set2 now has four elements
	set2.insert({ 1, 3, 5, 7, 1, 3, 5, 7 });		//set2 now has eight elements
	getchar();
}