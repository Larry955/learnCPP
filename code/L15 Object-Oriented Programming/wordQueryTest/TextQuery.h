#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include<iostream>
using std::istream; using std::ostream;

#include<string>
using std::string;

#include<vector>
using std::vector;

#include<fstream>
using std::ifstream;

#include<sstream>
using std::stringstream;

#include<map>
using std::map;

#include"QueryResult.h"

class QueryResult;
class TextQuery{
public:
	using line_no = vector<string>::size_type;
	TextQuery(ifstream&);
	QueryResult query(const string&)const;
	void display_map();	//debuging aid: print the map;
private:
	shared_ptr<vector<string>>file;	//input file
	//maps each word to the set of the lines in which that word appears
	map<string, shared_ptr<set<line_no>>>wm;

	//removes punctuation and makes everything lower cases
	static string clearup_str(const string&);
};
#endif