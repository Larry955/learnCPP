#ifndef DEBUGDELETE_H
#define DEBUGDELETE_H

#include<string>
using std::string;

#include<iostream>
using std::ostream;
using std::cerr;

//function-object class that calls delete on a given pointer
class DebugDelete{
public:
	DebugDelete(const string &s = "unique_string",
		ostream &strm = cerr) :type(s), os(strm){}
	template<typename T>
	void operator()(T *p)const{
		os << "deleting " << type << endl;
		delete p;
	}
private:
	string type;		//what type of smart pointer we're deleting
	ostream &os;	//where to print debuging info
};

#endif // !DEBUGDELETE_H
