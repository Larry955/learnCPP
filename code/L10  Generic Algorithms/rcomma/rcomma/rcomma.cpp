#include<string>
using std::string; 

#include<algorithm>
using std::find;

#include<iostream>
using std::endl; using std::cout; using std::cin;

int main()
{
	string line;
	getline(cin, line);

	//find the first element in a comma-separated list
	auto comma = find(line.cbegin(), line.cend(), ',');
	cout << string(line.cbegin(), comma)<<endl;

	//find the last element in a comma-separated list
	auto rcomma = find(line.crbegin(), line.crend(), ',');

	//WRONG : will generate the word in reverse word
	cout << string(line.crbegin(), rcomma)<<endl;

	//ok : get a forward iterator and read to the end of line
	cout << string(rcomma.base(), line.cend())<<endl;
	getchar();
}