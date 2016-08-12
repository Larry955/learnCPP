#include<map>
using std::map;

#include<string>
using std::string;

#include<utility>
using std::pair;

#include<iostream>
using std::cin; using std::cout; using std::endl;

int main()
{
	//count the number of each word occurs in the input
	map<string, size_t>word_count;		//empty map from string to size_t
	
	string word;
	while (cin >> word)
		++word_count[word];

	for (const auto &w : word_count)
		cout << w.first << " occurs " << w.second
		<<" times "<< endl;

	//get an iterator positioned on the first element
	auto map_it = word_count.cbegin();
	//compare the current iterator to the off_the_end iterator
	while (map_it != word_count.cend())
	{
		//deferences the iterator to print the element key-value pairs
		cout << map_it->first << " occurs "
			<< map_it->second << " times" << endl;
		++map_it;		//increment to the iterator to denote the next element
	}
	getchar();
}