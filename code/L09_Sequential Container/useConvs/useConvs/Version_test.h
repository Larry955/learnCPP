#ifndef VERSION_TEST_H
#define VERSION_TEST.H

#if __cplusplus == 201103L
#endif //ends compiler version check

#ifndef STRING_NUMBERIC_CONVS


#include<iostream>
#include<cstdlib>
#include<cstddef>
#include<string>
//we use sprintf from stdio to implement to_string
#include<cstdio>

inline
std::string to_string(int i)
{
	char buf[100];
	std::sprintf(buf, "%d", i);
	return buf;
}

inline
double stod(const std::string &s, std::size_t * = 0)
{
	char **buf = 0;
	return std::strtod(s.c_str(), buf);
}
#endif	//STRING_NUMERIC_CONVS

#include<iostream>

#ifdef HEX_MANIPS
inline
std::ostream &defaultfloat(std::ostream &os)
{
	os.unsetf(std::ios_base::floatfield);
	return os;
}
#endif	//HEX_MANIPS

#endif	//ends header guard
