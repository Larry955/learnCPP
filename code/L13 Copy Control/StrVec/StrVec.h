#ifndef	STRVEC_H
#define STRVEC_H

#include<iostream>
#include<string>
#include<initializer_list>
#include<memory>
#include<utility>


//simplified imlementation of the memeory allocation strategy foe a vector-like class
class StrVec{
public:
	//copy control memebers
	StrVec():
		elements(nullptr), first_free(nullptr), cap(nullptr){ }
	
	StrVec(const StrVec &);				//copy constructor
	StrVec& operator=(const StrVec&);	//copy assignment
	
	StrVec(StrVec&&);				//move constructor
	StrVec &operator=(StrVec&&);	//move assignment

	~StrVec();		//destructor

	//additional constructor
	StrVec(std::initializer_list<std::string>);	

	void push_back(const std::string&);		//copy the element
	void push_back(std::string&&);			//move the element

	size_t size() const { return first_free - elements; }	
	size_t capacity() const{ return cap - first_free; }

	//iterator interface
	std::string *beg()const { return elements; }
	std::string *end()const { return first_free; }


	StrVec &operator=(std::initializer_list<std::string>);
	
	std::string &operator[](std::size_t n)
	{
		return elements[n];
	}

	const std::string &operator[](std::size_t n) const{
		return elements[n];
	}

	template<class...Args> void emplace_back(Args&&...);
private:
	static std::allocator<std::string>alloc;	//allocates the elements

	//utility functions:
	//used by members that add elements to the StrVec
	void chk_n_alloc(){
		if (size() == capacity())	reallocate();
	}

	//used by the copy constructor,assignment operator,destructor
	std::pair<std::string*, std::string*> alloc_n_copy
		(const std::string*, const std::string*);
	
	void free();		//destroy the elements and free the space
	void reallocate();		//get more space and copy the existing elements
	std::string *elements;		//pointer to the first element in the array
	std::string *first_free;	//pointer to the first free element in the array
	std::string *cap;		//pointer to one past the end of the array
};

#include<algorithm>

inline
StrVec::~StrVec() 
{
	free();
}

inline
std::pair<std::string*, std::string*>  
StrVec::alloc_n_copy(const std::string *b, const std::string *e)
{
	//allocate sapce to hold as many elements as are in the range
	auto data = alloc.allocate(e - b);


	//initialize and return a pair constructed from data and
	//the value returned by the uninitialized_copy
	return{ data, uninitialized_copy(b, e, data) };
}

inline
StrVec::StrVec(StrVec &&s)
//member initializers take over the resources in s
: elements(s.elements), first_free(s.first_free), cap(s.cap)
{
	//leaves s in a state in which it is safe to run the destructor
	s.elements = s.first_free = s.cap = nullptr;
}

inline
StrVec::StrVec(const StrVec &s)
{
	//call alloc_n_copy to allocate exactly as many elements as in s
	auto newdata = alloc_n_copy(s.beg(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

inline
void StrVec::free()
{
	//if elements is nullptr,there is no work to do
	if (elements){
		//destroy the old elements in reverse order
		for (auto p = first_free; p != elements;){
			alloc.destroy(--p);
		}
		alloc.deallocate(elements, cap - elements);
	}
}

inline
StrVec &StrVec::operator=(std::initializer_list<std::string>i1)
{
	//alloc_n_copy allocates space and copies elements from given range
	auto data = alloc_n_copy(i1.begin(), i1.end());
	free();		//destroy the elements in this object and free the space
	elements = data.first;		//update data members to point to the new space
	first_free = cap = data.second;
	return *this;
}

inline
StrVec &StrVec::operator=(StrVec &&rhs)
{
	if (this != &rhs){
		free();
		elements = rhs.elements;
		first_free = rhs.first_free;
		cap = rhs.cap;
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}
	return *this;
}

inline
StrVec &StrVec::operator=(const StrVec &rhs)
{
	auto data = alloc_n_copy(rhs.beg(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

inline
void StrVec::reallocate()
{
	auto newcapacity = size() ? size() * 2 : 1;
	auto newdata = alloc.allocate(newcapacity);

	auto dest = newdata;
	auto elem = elements;
	for (size_t i = 0; i != size(); ++i){
		alloc.construct(dest++,std::move(*elem++));
	}
	free();

	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}

inline
StrVec::StrVec(std::initializer_list<std::string>i1)
{
	auto data = alloc_n_copy(i1.begin(), i1.end());
	elements = data.first;
	first_free = cap = data.second;
}

inline
void StrVec::push_back(const std::string &s)
{
	chk_n_alloc();

	alloc.construct(first_free++, s);
}

inline
void StrVec::push_back(std::string &&s)
{
	chk_n_alloc();

	alloc.construct(first_free++, std::move(s));
}

template<class...Args>
void StrVec::emplace_back(Args&&...args)
{
	chk_n_alloc();
	alloc.construct(first_free++, std::forward<Args>(args)...);
}
#endif