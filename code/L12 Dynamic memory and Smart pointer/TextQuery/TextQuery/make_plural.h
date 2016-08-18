#include<string>
using std::string;

string make_plural(size_t cnt, const string &word, const string &ending)
{
	return (cnt > 1) ? word + ending : word;
}