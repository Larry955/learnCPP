#include<algorithm>
using std::sort; using std::for_each;

#include<functional>
using std::bind;
using namespace std::placeholders;

#include<string>
using std::string;

#include<vector>
using std::vector;

#include<iostream>
using std::cout; using std::cin; using std::endl;


//comparison function to be used to sort by word length
bool isShorter(const string &s1, const string &s2)
{
	return s1.size() < s2.size();
}

bool LT(const string &s1, const string &s2)
{
	return s1 < s2;
}

void print(const vector<string>&words)
{
	for_each(words.cbegin(), words.cend(),
		[](const string &s){cout << s << " "; });
	cout << endl;
}
int main()
{
	vector<string>words;
	
	//copy contents of each book into a single vector
	string next_word;
	while (cin >> next_word)
		words.push_back(next_word);		//insert next book's contents at end of words
	print(words);

	vector<string>cpy = words;		//save the original string

	//uses string < to compare elements
	//sort and print the vector
	sort(words.begin(), words.end());

	words = cpy;		//return to the original string
	//uses the LT function to compare elements
	//should have the same output as the previous sort
	sort(words.begin(), words.end(), LT);
	print(words);

	words = cpy;		//return to the original string

	//eliminate duplicates
	sort(words.begin(), words.end());
	auto it = unique(words.begin(), words.end());
	words.erase(it, words.end());

	//sort by length using a function
	stable_sort(words.begin(), words.end(), isShorter);
	print(words);

	words = cpy;		//return to the original string
	//sort the original input on word length,shortest to longest
	sort(words.begin(), words.end(), isShorter);
	print(words);

	//use bind to invert isShorter to sort longest to shortest
	sort(words.begin(), words.end(), bind(isShorter,_2,_1));
	print(words);
	getchar();
}