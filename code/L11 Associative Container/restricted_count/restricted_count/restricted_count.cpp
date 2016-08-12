#include<map>
using std::map;

#include<set>
using std::set;

#include<string>
using std::string;

#include<iostream>
using std::cin; using std::cout; using std::endl;

int main()
{
	//count the number of times each word occurs in the input
	map<string, size_t>word_count;		//empty map from string to size_t
	set<string> exclude = {"the","a","and","but","or","an",
						  "The","A","And","But","Or","An"};

	string word;
	while (cin >> word)
	{
		//count words that only ont in exclude
		if (exclude.find(word) == exclude.end())
			++word_count[word];		//fetch and increment the counter for word
	}
	for (const auto &w : word_count){		//for each element in word_count
		//print the results
		cout << w.first << " occurs " << w.second
			<< ((w.second > 1) ? " times " : " time ") << endl;
	}
	getchar();
}
