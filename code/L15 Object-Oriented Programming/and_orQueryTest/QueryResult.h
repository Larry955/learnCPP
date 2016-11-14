#ifndef QUERY_RESULT_H
#define QUERY_RESULT_H

#include<string>
using std::string;

#include<vector>
using std::vector;

#include<iostream>
using std::ostream;

#include<set>
using std::set;

#include<memory>
using std::shared_ptr;

class QueryResult{
	friend ostream& operator<<(ostream&, const QueryResult&);
public:
	typedef vector<string>::size_type line_no;
	typedef set<line_no>::const_iterator line_it;
	QueryResult(string s,
		shared_ptr<set<line_no>>p,
		shared_ptr<vector<string>>f):
		sought(s), lines(p), file(f){}
	line_it begin()const{ return lines->cbegin(); }
	line_it end()const{ return lines->cend(); }
	set<line_no>::size_type size()const { return lines->size(); }
	shared_ptr<vector<string>> get_file()const{ return file; }
private:
	string sought;	//word to serach for
	shared_ptr<set<line_no>>lines;	//lines it's on
	shared_ptr<vector<string>>file;	//input file
};
ostream& operator<<(ostream&, const QueryResult&);	

#endif