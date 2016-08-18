#include"QueryResult.h"
#include"TextQuery.h"
//#include"make_plural.h"

#include<cstddef>
#include<map>
#include<string>
#include<vector>
#include<set>
#include<memory>
#include<sstream>
#include<fstream>
#include<iostream>
#include<cctype>
#include<cstring>
#include<utility>

using std::size_t;
using std::map;
using std::string;
using std::vector;
using std::set;
using std::shared_ptr;
using std::istringstream;
using std::ifstream;
using std::cerr;
using std::cout;
using std::cin;
using std::ostream;
using std::endl;
using std::ispunct;
using std::tolower;
using std::strlen;
using std::pair;

string make_plural(size_t cnt, const string &word, const string &ending)
{
	return (cnt > 1) ? word + ending : word;
}

//read the input file and build the map of lines to line numbers
TextQuery::TextQuery(ifstream &is) :file(new vector<string>)
{
	string text;
	while (getline(is, text)){		//for each line in the file
		file->push_back(text);		//remember this line of text
		int n = file->size() - 1;	//the current line number
		istringstream line(text);	//separate the line into words
		string word;	
		while (line >> word){		//for each word in that line
			word = cleanup_str(word);
			//if word isn't already in wm,subscripting adds a new entry
			auto &lines = wm[word];		//lines is a shared_ptr
			if (!lines)					//that pointer is null the first time we see word
				lines.reset(new set<line_no>);//allocate a new set
			lines->insert(n);			//insert this line number
		}
	}
}

string TextQuery::cleanup_str(const string &word)
{
	string ret;
	for (auto it = word.begin(); it != word.end(); ++it)
		if (!ispunct(*it))
			ret += tolower(*it);
	return ret;
}

QueryResult
TextQuery::query(const string &sought)const
{
	//we'll return a pointer to this set if we don't find sought
	static shared_ptr<set<line_no>> nodata(new set<line_no>);
	
	//use find and not a subscript to avoid adding words to wm!
	auto loc = wm.find(cleanup_str(sought));

	if (loc == wm.end())
		return QueryResult(sought, nodata, file);		//not found
	else
		return QueryResult(sought, loc->second, file);
}

ostream &print(ostream &os, const QueryResult &qr)
{
	//if the word was found,print the count and all occureneces
	os << qr.sought << " occurs " << qr.lines->size() << " "
		<< make_plural(qr.lines->size(), "time", "s") << endl;

	//print each line in which the word appeared
	for (auto num : *qr.lines){
		cout << "\t(line: " << num + 1 << ") "
			<< *(qr.file->begin() + num) << endl;
	}
	return os;
}

void TextQuery::display_map()
{
	auto iter = wm.cbegin(), iter_end = wm.cend();

	//for each word in the map
	for (; iter != iter_end; ++iter){
		cout << "word: " << iter->first << "{";

		//fetch location vector as a const reference to avoid copying it
		auto text_locs = iter->second;
		auto loc_iter = text_locs->cbegin(),
			loc_iter_end = text_locs->cend();

		//print all line numbers for this word
		while (loc_iter != loc_iter_end){
			cout << *loc_iter;

			if (++loc_iter != loc_iter_end)
				cout << ",";
		}
		cout << "}\n";		//end list of output this word
	}
	cout << endl;		//finished printing entire map
}