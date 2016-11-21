#ifndef DEBUG_REP_H
#define DEBUG_REP_H

#include<iostream>
using std::cout; using std::endl;

#include<string>
using std::string;

#include<sstream>
using std::ostringstream;

#include<vector>
using std::vector;

/*this file uses two preprocessor variables to control whether
we use nontemplate functions or specializations for string
data and to control whether we define versions of debug_rep
that handle character pointers.

SPECIALIZED is defined,then we define specializations for string,
			const char*,char* and do not define nontemplate
			functions that take these types

OVERCHAR only matters when SPECIALIZED is not defined.In this case
		if OVERCHAR is defined,we define we nontemplate function
		that takes a string; otherwise we define nontemplate functions
		taking char* and const char*
*/

#ifndef SPECIALIZED
string debug_rep(const string &);
#ifndef OVERCHAR
string debug_rep(const char*);
string debug_rep(char*);
#endif // !OVERCHAR
//overloaded,not specialized, function templates
template<typename T>string debug_rep(const T&);
template<typename T>string debug_rep(T*);
template<typename T>string debug_rep(T, T);
template<typename T>string debug_rep(const vector<T>&);
#endif // !SPECIALIZED

#ifdef SPECIALIZED
//specialized versions to handle strings and character pointers
//declarations for specialized versions should follow declarations for all	 overloaded templates
template<>string debug_rep(const string&);
template<>string debug_rep(const char*);
template<>string debug_rep(char*);
#endif // SPECIALIZED

//print any type we don't otherwise handle
template<typename T>string debug_rep(const T&t)
{
#ifdef DEBUG
	cout<<"const T&"<<"\t";
#endif // DEBUG
	ostringstream ret;
	ret << t;	//uses T's output operator to print a representation of t
	return ret.str();	//return a copy of string to which ret is bound
}

template<typename T>string debug_rep(T *p)
{
#ifdef DEBUG
	cout<<"T*"<<"\t";
#endif // DEBUG
	ostringstream ret;
	ret << "pointer: " << p;	//print the pointer's own value
	if (p)
		ret << *p;		//print the value to which p points
	else
		ret << "nullptr!";
	return ret.str();
}

#ifndef SPECIALIZED
string debug_rep(const string &s)
#else
template<>string debug_rep(const string &s)
#endif // !SPECIALIZED
{
#ifdef DEBUG
	cout << "const string&"<<"\t";
#endif // DEBUG
	return " " + s + " ";
}

#ifndef OVERCHAR
string debug_rep(const char *p)
{
	return debug_rep(string(p));
}
string debug_rep(char *p)
{
	return debug_rep(string(p));
}
#endif // !OVERCHAR
#ifdef SPECIALIZED
template<>string debug_rep(const char *p)
{
	return debug_rep(string(p));
}
template<>string debug_rep(char *p)
{
	return debug_rep(string(p));
}
#endif // SPECIALIZED

template<typename T>string debug_rep(T b, T e)
{
	ostringstream ret;
	for (T it = b; it != e; ++it){
		if (it != b)	
			ret << ",";	//put comma before all but the first element
		ret << debug_rep(*it);
	}
	return ret.str();
}
template<typename T>string debug_rep(const vector<T> &v)
{
	ostringstream ret;
	ret << "vector: [";
	ret << debug_rep(v.begin(), v.end());
	ret << "]";
	return ret.str();
}

#endif // !DEBUG_REP_H
