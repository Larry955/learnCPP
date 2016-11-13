#include"Query.h"
#include"TextQuery.h"

#include<memory>
using std::shared_ptr; using std::make_shared;

#include<algorithm>
using std::set_intersection;

#include<cstddef>
using std::size_t;

#include<iostream>
using std::ostream;

#include<set>
using std::set;

#include<iterator>
using std::inserter;

//returns the lines not in the operand's set
QueryResult
NotQuery::eval(const TextQuery &text)const
{
	//virtual to eval through Query operand
	auto result = query.eval(text);

	//start out with an empty set
	auto ret_lines = make_shared<set<line_no>>();

	//we have to interate through the lines on which our operand appears
	auto beg = result.begin(), end = result.end();

	//for each line in the input file,if that line is not in the result
	//add that line number to ret_lines
	auto sz = result.get_file()->size();
	for (auto n = 0; n != sz; ++n){
		//if we haven't processed all the lines in the result
		//check whether this line is present
		if (beg != end || *beg != n){
			ret_lines->insert(n);	//if not in result,add this file
		}
		else if (beg != end)
			++beg;	//otherwise get the next line number in the result
	}
	return QueryResult(rep(), ret_lines, result.get_file());
}

//returns the intersection of its operands' result sets
QueryResult
AndQuery::eval(const TextQuery &text)const
{
	//virtual call through the Query operands to get result sets for the operands
	auto left = lhs.eval(text), right = rhs.eval(text);

	//set the hold to intersaction of left and right
	auto ret_lines = make_shared<set<line_no>>();

	//wirtes the intersections of two ranges to a destination iterator
	//destination iterator in this call adds elements to ret_lines
	set_intersection(left.begin(), right.end(),
		right.begin(), right.end(),
		inserter(*ret_lines, ret_lines->begin()));
	return QueryResult(rep(), ret_lines, left.get_file());
}

//returns the union of its operands' result sets
QueryResult
OrQuery::eval(const TextQuery &text)const
{
	//virtual calls through the Query's members,lhs and rhs
	//the calls to eval returns the QueryResult for each operand
	auto left = lhs.eval(text), right = rhs.eval(text);

	//copy the line numbers from the left-hand operand into the result set
	auto ret_lines = make_shared<set<line_no>>(left.begin(), right.end());
	//insert lines from right-hand operand
	ret_lines = make_shared<set<line_no>>(right.begin(), right.end());
	//return the new result representing the union of lhs and rhs
	return QueryResult(rep(), ret_lines, left.get_file());
}