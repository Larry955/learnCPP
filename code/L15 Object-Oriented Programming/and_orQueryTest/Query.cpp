#include"Query.h"
#include"TextQuery.h"
#include<algorithm>
using std::set_intersection;

#include<memory>
using std::shared_ptr; using std::make_shared;

#include<iterator>
using std::inserter;

//return the lines not in its operand's result set
QueryResult
NotQuery::eval(const TextQuery &text)const
{
	auto result = query.eval(text);
	//start out with an empty result set
	auto ret_lines = make_shared<set<line_no>>();
	//we have to iterate through the lines on which our operand appears
	auto beg = result.begin(), end = result.end();
	//for each line in the input file,if that line is not in the result
	//add that line number to ret_lines
	auto sz = result.get_file()->size();
	for (size_t n = 0; n != sz; ++n){
		if (beg == end || *beg != n)
			ret_lines->insert(n);	//if not in result,add this line
		else if (beg != end)
			++beg;	//otherwise get the next line number in result
	}
	return QueryResult(rep(), ret_lines, result.get_file());
}

QueryResult
AndQuery::eval(const TextQuery &text)const
{
	auto left = lhs.eval(text);
	auto right = rhs.eval(text);
	//set to hold the intersection of left and right
	auto ret_lines = make_shared<set<line_no>>();
	//wirtes the intersection of two ranges to a destination iterator
	//destination in this call adds element to ret_lines
	set_intersection(left.begin(), left.begin(),
		right.begin(), right.end(),
		inserter(*ret_lines, ret_lines->begin()));
	return QueryResult(rep(), ret_lines, left.get_file());
}

//returns the union of its operands'result sets
QueryResult
OrQuery::eval(const TextQuery &text)const
{
	auto left = lhs.eval(text), right = rhs.eval(text);

	auto ret_lines = make_shared<set<line_no>>(left.begin(), right.end());
	ret_lines = make_shared<set<line_no>>(right.begin(), right.end());
	return QueryResult(rep(), ret_lines, left.get_file());
}

