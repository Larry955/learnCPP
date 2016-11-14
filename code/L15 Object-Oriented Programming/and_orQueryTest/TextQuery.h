#ifndef TEXTQUERY_H
#define TEXTQUERY_H
#include"QueryResult.h"
#include<vector>
using std::vector;

#include<string>
using std::string;

#include<set>
using std::set;

#include<map>
using std::map;

#include<memory>
using std::shared_ptr;

#include<fstream>
using std::ifstream;

class QueryResult;	//declaration needed for return type in the query function
class TextQuery{
public:
	using line_no = vector<string>::size_type;
	TextQuery(ifstream&);
	QueryResult query(const string&)const;
	void display_map();	//debug aid: print the map
private:
	shared_ptr<vector<string>>file;	//input file
	//maps each word to the set of the lines in which that word appears
	map < string,
		shared_ptr<set<line_no>>>wm;
	//remove punctuation and make everything lower case
	static string cleanup_str(const string&);
};
#endif