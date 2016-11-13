#include"TextQuery.h"
#include"make_plural.h"

#include<cctype>
using std::ispunct; using std::tolower;

#include<utility>
using std::pair; using std::find;

#include<cstring>
using std::strlen;

#include<iostream>
using std::cerr;

//read the input file and build the map of lines to line numbers
TextQuery::TextQuery(ifstream &is) :file(new vector<string>)
{
	string text;
	string word;
	while (getline(is, text)){		//for each line in the file
		file->push_back(text);	//remember this line of text
		int n = file->size() - 1;//the current line number
		stringstream line(text);	//separate the line into words
		while (line >> word){	//for each word in that line
			word = clearup_str(word);
			//if word isn't already in wm,subscripting adds a new entry
			auto &lines = wm[word];	//lines is a shared_ptr
			if (!lines)	//that pointer is null the first time we see the word
				lines.reset(new set<line_no>);	//allocate a new set
			lines->insert(n);//insert this line number
		}
	}
}

//removes punctuations and converts all the text into lowercase
string TextQuery::clearup_str(const string &word)
{
	string ret;
	for (auto it = word.begin(); it != word.end(); ++it){
		if (!ispunct(*it))
			ret += tolower(*it);
	}
	return ret;
}

QueryResult TextQuery::query(const string &sought)const
{
	//return a pointer to the set if we don't find sought
	static shared_ptr<set<line_no>>nodata(new set<line_no>);

	//uses fiind instead of subscript to avoid adding words to wm
	auto loc = wm.find(clearup_str(sought));

	if (loc == wm.end())
		return QueryResult(sought, nodata, file);	//not found
	else
		return QueryResult(sought, loc->second, file);
}

ostream &operator<<(ostream &os, const QueryResult &qr)
{
	//if the word was found,print the count and all the occurences
	os << qr.sought << " occurs " << qr.lines->size()
		<< make_plural(qr.lines->size(), " time", "s") << endl;
	//print each line in which the word appears
	for (auto num : *qr.lines){	//for every element in the set
		os << "\t(line " << num + 1 << ") "
			<< *(qr.file->begin() + num) << endl;
	}
	return os;
}

//debugging routine
void TextQuery::display_map()
{
	auto iter = wm.begin(), iter_end = wm.end();

	//for each word in the map
	for (; iter != iter_end; ++iter){
		cout << "word: " << iter->first << " { ";
		
		//fecth location vector as a const reference to avoid copying it
		auto text_locs = iter->second;
		auto	loc_iter = text_locs->cbegin(),
			loc_iter_end = text_locs->cend();

		//print all line numbers for this word
		while (loc_iter != loc_iter_end){
			cout << *loc_iter;
			if (++loc_iter != loc_iter_end)
				cout << ", ";
		}
		cout << "}\n";
	}
	cout << endl;
}