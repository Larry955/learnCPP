#ifndef VECTOR_H
#define VECTOR_H

#include<algorithm>
#include<memory>
#include<initializer_list>
#include<utility>
#include<stdexcept>
using namespace std;

template<typename T>
class Vector{
public:
	Vector() = default;
	Vector(const Vector&);	//copy constructor
	Vector& operator=(const Vector&);	//copy assignment
	Vector(Vector&&);		//move constructor
	Vector& operator=(Vector&&);	//move assignment
	~Vector();

	//list assignment
	Vector& operator=(initializer_list<T>);

	//add elements
	void push_back(const T&);
	void push_back(T&&);
	template<class...Args>void emplace_back(Args&&...);

	size_t size()const{ return first_free - elements; }
	size_t capacity()const{ return cap - elements; }

	//elements access
	T& operator[](size_t n){ return elements[n]; }
	const T& operator[](size_t n)const{ return elements[n]; }

	T* begin()const{ return elements; }
	T* end()const{ return first_free; }
private:
	static allocator<T>alloc;		//allocates the elements
	void check_n_copy(){ if (first_free == cap)reallocate(); }

	//used by copy constructor,assignment operator and destructor
	pair<T*, T*>
		alloc_n_copy(const T*, const T*);
	void free();
	void reallocate();
	T *elements = nullptr;	//pointer to first element in the array
	T *first_free = nullptr;	//pointer to first free element in the array
	T *cap = nullptr;		//pointer to one past end of the array
};

//definition of the static data member
template<typename T>
allocator<T> Vector<T>::alloc;

template<typename T>
inline
pair<T*,T*> Vector<T>::alloc_n_copy(const T *b, const T *e)
{
	auto data = alloc.allocate(e - b);
	return{ data, uninitialized_copy(b, e, data) };
}

template<typename T>
inline
void Vector<T>::free()
{
	for (auto p = first_free; p != elements; /*empty*/)
		alloc.destroy(--p);	//destroy elements in reverse order
	if (elements)
		alloc.deallocate(elements, cap - elements);
}

template<typename T>
inline
Vector<T>::Vector(const Vector &v)
{
	auto newdata = alloc_n_copy(v.begin(), v.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

template<typename T>
inline
Vector<T>& Vector<T>::operator=(const Vector &rhs)
{
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

template<typename T>
inline
Vector<T>::Vector(Vector &&v):
//take over resources from v
elements(v.elements), first_free(v.first_free), cap(v.cap)
{
	//leave v in a state in which it is safe to run a destructor
	v.elements = v.first_free = v.cap = nullptr;
}

template<typename T>
inline
Vector<T>& Vector<T>::operator=(Vector &&rhs)
{
	if (this != &rhs)
		free();
	elements = rhs.elements;
	first_free = rhs.first_free;
	cap = rhs.cap;
	rhs.elements = rhs.first_free = rhs.cap = nullptr;
	return *this;
}

template<typename T>
inline
Vector<T>::~Vector()
{
	free();
}
template<typename T>
inline
Vector<T>& Vector<T>::operator=(initializer_list<T>il)
{
	auto data = alloc.allocate(il.begin(), il.end());
	elements = data.first;
	first_free = cap = data.second = nullptr;
	return *this;
}

template<typename T>
inline
void Vector<T>::reallocate()
{
	//we'll allocate space for twice as many elements as current size
	auto newcapacity = size() ? size() * 2 : 2;

	auto first = alloc.allocate(newcapacity);
	auto dest = first;
	auto elem = elements;

	//move the elements
	for (size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));
	free();		//free the old space once we've move the elements
	
	elements = first;
	first_free = dest;
	cap = elements + newcapacity;
}

template<typename T>
inline
void Vector<T>::push_back(const T &s)
{
	check_n_copy();	//reallocate the Vector if neccessary
	alloc.construct(first_free++,s);
}

template<typename T>
inline
void Vector<T>::push_back(T &&s)
{
	check_n_copy();
	alloc.construct(first_free++,std::move(s));
}

template<typename T>
template<class...Args>
inline
void Vector<T>::emplace_back(Args&&...args)
{
	check_n_copy();
	alloc.construct(first_free++, std::forward<Args>(args)...);
}

#endif // !VECTOR_H