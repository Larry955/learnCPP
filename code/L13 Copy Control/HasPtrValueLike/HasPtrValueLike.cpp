#include<string>
using std::string;

//value-like implements of HasPtr
class HasPtr{
	friend void swap(HasPtr&, HasPtr&);
public:
	HasPtr(const string& s = string()):
		ps(new string(s)), i(0){ }
	//each HasPtr has its own copy of the string to which ps points
	HasPtr(const HasPtr& p):
		ps(new string(*p.ps)), i(p.i){ }

	HasPtr& operator=(const HasPtr&);
	~HasPtr(){ delete ps; }
private:
	string *ps;
	int i;
};

inline
void swap(HasPtr& lhs, HasPtr& rhs)
{
	using std::swap;
	swap(lhs.ps, rhs.ps);	//swap the pointers,not the strings 
	swap(lhs.i, rhs.i);		//swap the int members
}

HasPtr& HasPtr::operator=(const HasPtr& rhs)
{
	auto newp = new string(*rhs.ps);		//copy the underlying string
	delete ps;		//free the old memeory
	ps = newp;		//copy data from rhs to this object
	i = rhs.i;		
	return *this;	//return this object
}

HasPtr f(HasPtr h)		//HasPtr passed by value,so it is copied
{
	HasPtr ret = h;		//copies the given HasPtr
	//process ret
	return ret;			//ret and h are destroyed
}

int main()
{	
	HasPtr h("Hi,Larry");	//allocate a new copy of "Hi,Larry"
	f(h);	//copy constructors copies h in the call to f
			//that copy is destroyed when f exits
	getchar();
}//h is destroyed on exit ,which destroys its allocated memory