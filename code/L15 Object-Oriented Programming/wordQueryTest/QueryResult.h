#ifndef QUERYRESULT_H
#define QUERYRESULT_H

#include<iostream>
using std::istream; using std::ostream;

#include<string>
using std::string;

#include<vector>
using std::vector;

#include<set>
using std::set;

#include<memory>
using std::shared_ptr;

class QueryResult{
	friend ostream& operator<<(ostream&, const QueryResult&);
public:
	typedef vector<string>::size_type line_no;
	typedef set<line_no>::const_iterator line_it;

	QueryResult(string s, shared_ptr<set<line_no>>l,
		shared_ptr<vector<string>>inputfile) :
		sought(s), lines(l), file(inputfile){}

	set<line_no>::size_type size()const{ return lines->size(); }
	line_it begin()const{ return lines->cbegin(); }
	line_it end()const{ return lines->cend(); }
	shared_ptr<vector<string>> get_file(){ return file; }
private:
	string sought;	//word this query represents
	shared_ptr<set<line_no>>lines;	//lines it's on
	shared_ptr<vector<string>>file;	//input file
};

ostream &operator<<(ostream&, const QueryResult&);
#endif