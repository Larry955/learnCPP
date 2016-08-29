#include<string>
using std::string;

#include<cstddef>
using std::size_t;

//reference counted version of HasPtr
class HasPtr{
public:
	HasPtr(const string& s = string()):
		ps(new string(s)), i(0), use(new size_t(1)){ }
	
	HasPtr(const HasPtr& p):
		ps(p.ps), i(p.i), use(p.use){
		++*use;
	}

	HasPtr& operator=(const HasPtr&);

	~HasPtr();

	HasPtr(HasPtr &&p) :
		ps(p.ps), i(p.i), use(p.use){
		p.ps = 0; p.use = 0;
	}

	HasPtr &operator=(HasPtr &&);

private:
	string *ps;
	int i;
	size_t *use;
};

HasPtr::~HasPtr()
{
	if (--*use == 0){
		delete ps;
		delete use;
	}
}

HasPtr&
HasPtr::operator=(HasPtr&& rhs)
{
	if (this != &rhs){
		if (--*use == 0){
			delete ps;
			delete use;
		}
		ps = rhs.ps;
		i = rhs.i;
		use = rhs.use;
		ps = 0; use = 0;

	}
	return *this;
}

HasPtr& HasPtr::operator=(const HasPtr& rhs)
{
	++*rhs.use;
	if (--*use == 0){
		delete ps;
		delete use;
	}
	ps = rhs.ps;
	i = rhs.i;
	use = rhs.use;
	return *this;
}

HasPtr f(HasPtr h)
{
	HasPtr ret;
	ret = h;
	return ret;
}

int main()
{
	HasPtr hs("Hi,Larry!");
	HasPtr h = hs;
	getchar();
}