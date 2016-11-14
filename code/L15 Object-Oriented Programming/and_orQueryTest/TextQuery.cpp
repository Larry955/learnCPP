#include"TextQuery.h"
#include"make_plural.h"
#include<sstream>
#include<cstddef>
#include<iostream>
#include<cctype>
#include<utility>
#include<fstream>

using std::size_t;
using std::istringstream;
using std::cerr; using std::cout;
using std::cin; using std::endl;
using std::pair;
using std::ispunct; using std::tolower;
using std::ifstream;

TextQuery::TextQuery(ifstream &is) :file(new vector<string>)
{
	string text;
	while (getline(is, text)){		//for each line in the file
		file->push_back(text);	//remember this line of text
		int n = file->size() - 1;//the current line number
		string word;
		istringstream line(text);	//separate the line into words
		while (line >> word){	//for each word in the line
			word = cleanup_str(word);
			//if the word isn't in the map,subscripting adds a new entry
			auto &lines = wm[word];	//lines is a shared_ptr
			if (!lines)	//the first time we see the word,the pointer is a nullptr	
				lines.reset(new set<line_no>);	//so allocate a new set
			lines->insert(n);	//insert this line number
		}
	}
}

//removes the punctuation and converts all text to lower case so that
//the queries operations in a case insenstive manner
string TextQuery::cleanup_str(const string &word)
{
	string ret;
	for (auto it = word.begin(); it != word.end(); ++it){
		if (!ispunct(*it)){
			ret += tolower(*it);
		}
	}
	return ret;
}

QueryResult
TextQuery::query(const string &sought)const
{
	//we'll return a pointer to this set if we	 don't find the data
	static shared_ptr<set<line_no>>nodata(new set<line_no>);

	//use find instead of a subscript to avoid adding word to wm
	auto loc = wm.find(cleanup_str(sought));
	if (loc == wm.end())
		return QueryResult(sought, nodata, file);	//not found
	return QueryResult(sought, loc->second,file);
}

ostream& operator<<(ostream &os, const QueryResult &qr)
{
	//if the word is found,print the count and all the occurences
	os << qr.sought << " occurs " << qr.size()
		<< make_plural(qr.size(), " time", "s") << endl;
	//print each line in which the word appeared
	for (auto num : *qr.lines){
		os << "\t(line " << num + 1 << ") "
			<< *(qr.file->begin() + num) << endl;
	}
	return os;
}

void TextQuery::display_map()
{
	auto iter = wm.begin(), iter_end = wm.end();
	//for each word in the map
	while (iter != iter_end){
		cout << "word: " << iter->first << "{";

		//fetch location vector as a const reference to avoid copying it
		auto text_locs = iter->second;
		auto loc_iter = text_locs->cbegin(),
			loc_iter_end = text_locs->cend();
		while (loc_iter != loc_iter_end){
			cout << *loc_iter;
			if (loc_iter != loc_iter_end)
				cout << ",";
		}
		cout << "}\n";//end list of output of this word
		++iter;
	}
	cout << endl;	
}