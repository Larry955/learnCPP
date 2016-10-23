#include<memory>
using std::uninitialized_copy;

#include<iostream>
using std::ostream;

#include"String.h"

//delete the static allocator member
std::allocator<char> String::a;

//copy-assignment operator
String & String::operator=(const String &rhs)
{
	//copying the right-hand operand before deleting the left-hand handles self-assignment
	auto newp = a.allocate(rhs.sz);		//copy the underlying string from rhs
	uninitialized_copy(rhs.p, rhs.p + sz, newp);

	if (p)
		a.deallocate(p, sz);	//free the memory used by the left-hand operand
	p = newp;		//p now points to the newly allocated memory
	sz = rhs.sz;	//update the sz

	return *this;
}

//move assignment operator
String & String::operator=(String &&rhs)
{
	//explicit check for self-assignment 
	if (&rhs != this){
		if (p)
			a.deallocate(p, sz);		//do the work for destructor
		p = rhs.p;		//take over the old memory
		sz = rhs.sz;
		rhs.p = 0;	//deleting rhs.p is safe
		rhs.sz = 0;
	}
	return *this;
}

String& String::operator=(const char*cp)
{
	if (p)
		a.deallocate(p, sz);
	p = a.allocate(sz = strlen(cp));
	uninitialized_copy(p, p + sz, p);
	return *this;
}

String& String::operator=(char cp)
{
	if (p)
		a.deallocate(p, sz);
	p = a.allocate(sz = 1);
	*p = cp;
	return *this;
}

String& String::operator=(std::initializer_list<char>i1)
{
	if (p)
		a.deallocate(p, sz);
	p = a.allocate(sz = i1.size());
	uninitialized_copy(i1.begin(),i1.end(), p);

	return *this;
}

ostream& print(ostream &os, String s)
{
	auto p = s.begin();
	while (p != s.end())
		os << *p++;
	return os;
}

String add(const String &lhs, const String &rhs)
{
	String ret;
	ret.sz = lhs.sz + rhs.sz;
	ret.p = String::a.allocate(ret.sz);
	uninitialized_copy(lhs.begin(), rhs.end(), ret.p);
	uninitialized_copy(rhs.begin(), rhs.end(), lhs.sz + ret.p);
	return ret;
}

String make_plural(size_t ctr, const String &word,
	const String &ending)
{
	return (ctr != 1) ? (word + ending) : word;
}

ostream& operator<< (ostream &os, const String &s)
{
	return print(os, s);
}

String operator+(const String &lhs, const String &rhs)
{
	return add(lhs, rhs);
}
