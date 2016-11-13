#ifndef MAKE_PLURAL_H
#define MAKE_PLURAL_H

#include<string>
using std::string;

#include<cstddef>
using std::size_t;

#include<iostream>
using std::cout; using std::endl;

inline
string make_plural(const size_t cnt, const string &word, const string &ending)
{
	return cnt > 1 ? word + ending : word;
}
#endif