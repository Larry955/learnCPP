#ifndef MAKE_PLURAL_H
#define MAKE_PLURAL_H

#include<string>
using std::string;

#include<cstddef>
using std::size_t;

string make_plural(size_t cnt, const string &word, const string &ending)
{
	return cnt > 1 ? word + ending : word;
}
#endif