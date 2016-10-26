#ifndef MAKE_PLURAL_H
#define MAKE_PLURAL_H

#include<cstddef>
using std::size_t;

#include<iostream>
using std::endl; using std::cout;

#include<string>
using std::string;

//return the plural version of word if ctr is greater than one
inline
string make_plural(size_t ctr, const string &word,
				const string &ending)
{
	return (ctr > 1) ? word + ending : word;
}


#endif