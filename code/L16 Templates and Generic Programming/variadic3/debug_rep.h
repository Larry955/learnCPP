#ifndef DEBUG_REP_H
#define DEBUG_REP_H

#include<iostream>
#include<string>
#include<vector>
#include<sstream>

/*This file uses two preprocessor variables to control whether
we use nontemplate functions or specializations for string
data and to control whether we define versions of debug_rep
that handle character pointers

SPECIALIZED is defined,then we define specializations
			for string,const char*,char* and do not
			define nontemplate functions taking these types

OVERCHAR	 only matters if SPECIALIZED is not defined.In this case if 
		OVERCHAR is defined,we define a nontemplate function that
		takes a string,otherwise we define nontemplate functions that
		take const char* and char*
			
*/
#ifndef SPECIALIZED
std::string debug_rep(const std::string&);
#ifndef OVERCHAR
std::string debug_rep(const char*);
std::string debug_rep(char*);
#endif
#endif
//overloaded,not specialized,function templates
template<typename T>std::string debug_rep(const T&);
template<typename T>std::string debug_rep(T*);
template<typename T>std::string debug_rep(T, T);
template<typename T>std::string debug_rep(const std::vector<T>&);

#ifdef SPECIALIZED
//specialized versions to handle strings and character pointers
//declarations for specializations should follow declarations for all overloaded templates
template<>std::string debug_rep(const std::string&);
template<>std::string debug_rep(const char*);
template<>std::string debug_rep(char*);
#endif

//print any type we don't otherwise handle
template<typename T> std::string debug_rep(const T &t)
{
#ifdef DEBUG
	std::cout<<"const T&: "<<"\t";
#endif // DEBUG
	std::ostringstream ret;
	ret << t;	//uses T's output operator to print a representation of t
	return ret.str();	//return a copy of the string to which ret is bound
}

//print the pointer as their pointer value
//followed by the object to which the pointer points
template<typename T>std::string debug_rep(T *p)
{
#ifdef DEBUG
	std::cout<<"T*"<<"\t";
#endif // DEBUG
	std::ostringstream ret;
	ret << "pointer " << p;	//print the pointer's own value
	if (p)
		ret << " " << debug_rep(*p);	//print the value to which p points
	else
		ret << " null pointer! ";
	return ret.str();
}

#ifndef SPECIALIZED
std::string debug_rep(const std::string &s)
#else
//if SPECIALIZED is defined,then call the specialized version
template<>std::string debug_rep(const std::string &s)	
#endif
{
#ifdef DEBUG
	std::cout<<"const string&"<<"\t";
#endif // DEBUG
	return " " + s + " ";
}

#ifndef OVERCHAR
//convert the character pointers to string and call the string version of debug_rep
std::string debug_rep(const char *p)
{
	return debug_rep(std::string(p));
}
std::string debug_rep(char *p)
{
	return debug_rep(std::string(p));
}
#endif
#ifdef SPECIALIZED
template<>std::string debug_rep(const char *p)
{
	return debug_rep(std::string(p));
}
template<>std::string debug_rep(char *p)
{
	return debug_rep(std::string(p));
}
#endif

template<typename T>std::string debug_rep(T b, T e)
{
	std::ostringstream ret;
	for (T it = b; it != e; ++it)
	{
		if (it != b)
			ret << ",";	//put comma before but the first element
		ret << debug_rep(*it);	//peint the element
	}
	return ret.str();
}
template<typename T>std::string debug_rep(const std::vector<T> &v)
{
	std::ostringstream ret;
	ret << "vector:[";
	ret << debug_rep(v.begin(), v.end());
	ret << "]";
	return ret.str();
}
#endif