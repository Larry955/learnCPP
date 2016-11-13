#ifndef QUERY_H
#define QUERY_H

#include<iostream>
using std::ostream; using std::istream;

#include<fstream>
using std::ifstream;

#include<set>
using std::set;

#include<map>
using std::map;

#include<memory>
using std::make_shared; using std::shared_ptr;

#include<vector>
using std::vector;

#include<string>
using std::string;

#include"TextQuery.h"

//abstract class acts as a base class for concrete query types,all members are private
class Query_base{
	friend class Query;
protected:
	using line_no = TextQuery::line_no;		//uses in the eval function
	virtual ~Query_base() = default;
private:
	//eval returns the QueryResult that matches this query
	virtual QueryResult eval(const TextQuery&)const = 0;
	//rep is a string representation of the query
	virtual string rep()const = 0;
};

//interface class to manage the Query_base inheritance hierarchy
class Query{
	//these operators need to access the shared_ptr constructor
	friend Query operator&(const Query&, const Query&);
	friend Query operator|(const Query&, const Query&);
	friend Query operator~(const Query&);
public:
	Query(const string&);	//builds a new WordQuery
	//interface functions:call the corresponding Query_base operations
	QueryResult eval(const TextQuery &t)const{
		return q->eval(t);
	}
	string rep()const{
		return q->rep();
	}
private:
	Query(shared_ptr<Query_base> query) :q(query){}
	shared_ptr<Query_base>q;
};
inline
ostream &operator<<(ostream &os, const Query &query)
{
	//Query::rep makes a virtual call through its Query_base pointer to rep()
	os << query.rep();
	return os;
}


class WordQuery :public Query_base{
	friend class Query;	//Query uses the WordQuery constructor
	WordQuery(const string &s) :query_word(s){}

	//concrete class: WordQuery defines all the inherited pure virtual functions
	QueryResult eval(const TextQuery &t)const{
		return t.query(query_word);
	}
	string rep()const{
		return query_word;
	}
	string query_word;	//word for which to query
};
inline
Query::Query(const string &s) :q(new WordQuery(s)) {}

class NotQuery :public Query_base{
	friend Query operator~(const Query&);
	NotQuery(const Query &q) :query(q){}
	//concrete class:NotQuery defines all the inherited pure virtual functions 
	string rep()const{
		return "~(" + query.rep() + ")";
	}
	QueryResult eval(const TextQuery&)const;
	Query query;
};
inline Query operator~(const Query &q)
{
	return shared_ptr<Query_base>(new NotQuery(q));
}
class BinaryQuery:public Query_base{
protected:
	BinaryQuery(const Query &l, const Query &r, const string &s) :
		lhs(l), rhs(r), opSym(s){}
	//abstract class:BinaryQuery doesn't define eval
	string rep()const{
		return "(" + lhs.rep() + " " +
			opSym + " " + rhs.rep() + ")";
	}
	Query lhs, rhs;	//right- and left-hand operands
	string opSym;	//name of the operator
};

class AndQuery :public BinaryQuery{
	friend Query operator&(const Query&, const Query&);
	AndQuery(const Query &left,const Query &rhs):
		BinaryQuery(left, rhs, "&"){}
	//concrete class: AndQuery inherits rep and defines other pure virtual functions
	QueryResult eval(const TextQuery&)const;
};
inline Query operator&(const Query &lhs, const Query &rhs)
{
	return shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

class OrQuery :public BinaryQuery{
	friend Query operator|(const Query&, const Query&);
	OrQuery(const Query &lhs,const Query &rhs):
		BinaryQuery(lhs, rhs, "|"){}
	QueryResult eval(const TextQuery&)const;
};
inline Query operator|(const Query &lhs, const Query &rhs)
{
	return shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

ifstream& open_file(ifstream&, const string&);
TextQuery get_file(int, char**);
bool get_word(string&);
bool get_words(string&, string&);
ostream& print(ostream&, const QueryResult&);

#endif
