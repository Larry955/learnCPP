#include<map>
using std::multimap;

#include<string>
using std::string;

#include<utility>
using std::pair;

#include<iostream>
using std::cout; using std::endl;

int main()
{
	//map from authors to titles,there can be multiple titles per author
	multimap<string, string>authors;

	//add data to authors
	authors.insert({ "Alain de Button", "on love" });
	authors.insert({ "Alain de Buttton", "status anxiety" });
	authors.insert({ "Alain de Button", "art of travel" });
	authors.insert({ "Alain de Button", "Architecture of Happiness" });

	string search_item("Alain de Button");	//author we will look for
	auto entries = authors.count(search_item);	//number of elements
	auto iter = authors.find(search_item);		//first entry for this author

	//look through the number of entries there are for authors
	while (entries){
		cout<<iter ->second<<endl;//print each title
		++iter;		//advance to the next title
		--entries;		//keep track of how many we've printed
	}

	//definitions of authors and search_item as above
	//beg and end denote the range of elements for this author
	for (auto beg = authors.lower_bound(search_item),
				end = authors.upper_bound(search_item);
			beg != end;	++beg){
		cout << beg->second << endl;	//print each title
	}

	//definitions of authors and search_item as above
	//pos holds iterator that denotes the range of elements for this author
	for (auto pos = authors.equal_range(search_item);
		pos.first != pos.second; ++pos.first)
		cout << pos.first->second << endl;		//print each title5
	getchar();
}