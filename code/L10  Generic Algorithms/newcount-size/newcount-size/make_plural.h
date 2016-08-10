#include<string>
using std::string;

#include<iostream>
using std::cout; using std::endl;

string make_plural(size_t ctr, const string &word,
	const string &ending)
{
	return (ctr > 1) ? word + ending : word;
}	