#ifndef QUERY_H
#define QUERY_H

#include"TextQuery.h"
#include<iostream>
using std::ostream;
#include<string>
using std::string;
#include<set>
using std::set;
#include<vector>
using std::vector;
#include<fstream>
using std::ifstream;
#include<memory>
using std::shared_ptr; using std::make_shared;

class Query_base{
	friend class Query;
protected:
	using line_no = TextQuery::line_no;	//used in the eval functions
	virtual ~Query_base() = default;
private:
	//eval returns the QueryResult that matches this Query
	virtual QueryResult eval(const TextQuery&)const = 0;
	//rep is a string representation of the query
	virtual string rep()const = 0;
};

//interface class to manage the Query_base inheritance hierarchy
class Query{
	//these operators need access to the shared_ptr constructor
	friend Query operator&(const Query&, const Query&);
	friend Query operator|(const Query&, const Query&);
	friend Query operator~(const Query&);
public:
	Query(const string&);	//build a new WordQuery

	//interface functions,call the corresponding Query_base operations
	QueryResult eval(const TextQuery &text)const{
		return q->eval(text);
	}
	string rep()const{
		return q->rep();
	}
private:
	shared_ptr<Query_base>q;
	Query(shared_ptr<Query_base>query) :q(query){}
};

inline
ostream& operator<<(ostream &os, const Query &query)
{
	//Query::rep makes a virtual call through its Query_base pointer to rep() 
	return os << query.rep();
}

class WordQuery :public Query_base{
	friend class Query;	//Query uses the WordQuery constructor
	WordQuery(const string &s) :query_word(s){}
	QueryResult eval(const TextQuery &t)const{
		return t.query(query_word);
	}
	string rep()const{ return query_word; }
	string query_word;	//word for which to search
};
inline
Query::Query(const string &s) :q(new WordQuery(s)){}

class NotQuery :public Query_base{
	friend Query operator~(const Query&);
	NotQuery(const Query &q) :query(q){}

	string rep()const{ return "~(" + query.rep() + ")"; }
	QueryResult eval(const TextQuery&)const;
	Query query;
};

class BinaryQuery :public Query_base{
protected:
	BinaryQuery(const Query &l,const Query &r,string s):
		lhs(l), rhs(r), opSym(s){}
	string rep()const{
		return "(" + lhs.rep() + " " + opSym +
			" " + rhs.rep() + ")";
	}
	Query lhs, rhs;
	string opSym;	//name of the operator
};

class AndQuery :public BinaryQuery{
	friend Query operator&(const Query&, const Query&);
	AndQuery(const Query &left, const Query &right):
		BinaryQuery(left, right, "&"){}
	QueryResult eval(const TextQuery&)const;
};

class OrQuery :public BinaryQuery{
	friend Query operator|(const Query&, const Query&);
	OrQuery(const Query &left,const Query &right):
		BinaryQuery(left, right, "|"){}

	QueryResult eval(const TextQuery&)const;
};

inline
Query operator&(const Query &lhs, const Query &rhs)
{
	return shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}
inline
Query operator|(const Query &lhs, const Query &rhs)
{
	return shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}
inline
Query operator~(const Query &operand)
{
	return shared_ptr<Query_base>(new NotQuery(operand));
}

ifstream& open_file(ifstream&, const string&);
TextQuery get_file(int, char**);
bool get_word(string&);
bool get_words(string&, string&);
#endif