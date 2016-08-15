#include<map>
using std::map;

#include<string>
using std::string;

#include<iostream>
using std::endl; using std::cout; using std::cin;

int main()
{
	map<string, size_t>word_count;		//empty map from string to size_t
	string word;
	while (cin >> word)
		++word_count[word];

	string remove_word = "the";

	//two ways to remove entry from a map
	//1.by a key
	//erase on a key returns the number of element removed
	if (word_count.erase(remove_word)){
		cout << "ok: " << remove_word << " removed" << endl;
	}
	else
		cout << "oops: " << remove_word << " not found" << endl;

	//2.by removing the iterator to the element we want removed
	remove_word = "The";		//strings are keys sensitive
	map<string, size_t>::iterator where;
	where = word_count.find(remove_word);
	if (where == word_count.end())
		cout << "oops: " << remove_word << " not found" << endl;
	else{
		word_count.erase(where);		//erase iterator returns void
		cout << "ok: " << remove_word << " removed" << endl;
	}
	getchar();
}