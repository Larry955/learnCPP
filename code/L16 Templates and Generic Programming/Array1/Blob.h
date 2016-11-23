#ifndef BLOB_H
#define BLOB_H

#include<iostream>
#include<initializer_list>
#include<vector>
#include<string>
#include<memory>
#include<iterator>
#include<cstddef>
#include<stdexcept>
#include<utility>
#include<algorithm>
#include<cstdlib>
using namespace std;

//forward declarations needed for friend declarations in Blob
template<typename T> class BlobPtr;
template<typename T> class Blob;	//needed for parameters in operator==
template<typename T> bool operator==(const Blob<T>&, const Blob<T>&);

template<typename T>
class Blob{
	friend class BlobPtr < T > ;
	friend bool operator==<T>(const Blob<T>&, const Blob<T>&);
	//friend ostream& operator<<<T>(ostream&, const Blob<T>);
public:
	typedef T value_type;
	typedef typename vector<T>::size_type size_type;
	//constructors
	Blob() :data(make_shared<vector<T>>()){}
	Blob(initializer_list<T>il) :data(make_shared<vector<T>>(il)){} 
	template<typename It>Blob(It b, It e) : data(make_shared<vector<T>>(b, e)){}
	Blob(T *p, size_t n) :data(make_shared<vector<T>>(p, p + n)){}

	//return BlobPtr to the first and one past the last elements
	BlobPtr<T> begin(){ return BlobPtr<T>(*this); }
	BlobPtr<T> end(){ return BlobPtr<T>(*this, data->size();) }

	//number of elements in the Blob
	size_type size()const{ return data->size(); }
	bool empty()const{ return data->empty(); }

	//add and remove elements
	void push_back(const T &t){ return data->push_back(t); }
	void push_back(T &&t){ return data->push_back(std::move(t)); }
	void pop_back();
	
	//element access
	T& front();
	T& back();
	T& at(size_type);
	const T& front()const;
	const T& back()const;
	const T& at(size_type)const;
	T& operator[](size_type);
	const T& operator[](size_type)const;

	void swap(Blob &b){ data.swap(b.data); }
private:
	shared_ptr<vector<T>> data;
	void check(size_type, const string&)const;
};

template<typename T>
T& Blob<T>::operator[](size_type i)
{
	check(i, "subscript out of range");
	return (*data)[i];
}

template<typename T>
const T& Blob<T>::operator[](size_type i)const
{
	check(i, "subscript out of range");
	return (*data)[i];
}
template<typename T>
bool operator==(const Blob<T> &lhs, const Blob<T> &rhs)
{
	if (lhs.size() != rhs.size())
		return false;
	for (size_t i = 0; i != lhs.size(); ++i){
		if (lhs[i] != rhs[i])
			return false;
	}
	return true;
}
// operators
template <typename T>
std::ostream&
operator<<(std::ostream &os, const Blob<T> a)
{
	os << "< ";
	for (size_t i = 0; i < a.size(); ++i)
		os << a[i] << " ";
	os << " >";
	return os;
}

template<typename T>
void Blob<T>::check(size_type i, const string &msg)const
{
	if (i >= data->size())
		throw out_of_range(msg);
}

template<typename T>
void Blob<T>::pop_back()
{
	check(0, "pop back on empty Blob");
	data->pop_back();
}

template<typename T>
T& Blob<T>::front()
{
	check(0, "front on empty Blob");
	return data->front();
}

template<typename T>
const T& Blob<T>::front()const
{
	check(0, "front on empty Blob");
	return data->front();
}

template<typename T>
T& Blob<T>::back()
{
	check(0, "back on empty Blob");
	return data->back();
}

template<typename T>
const T& Blob<T>::back()const
{
	check(0, "back on empty Blob");
	return data->back();
}

template<typename T>
T& Blob<T>::at(size_type i)
{
	check(i, "subscript out of range");
	return (*data)[i];
}

template<typename T>
const T& Blob<T>::at(size_type i)const
{
	check(i, "subscript out of range");
	return (*data)[i];
}

template<typename T>
bool operator==(const BlobPtr<T>&, const BlobPtr<T>&);
template<typename T>
class BlobPtr :public iterator < bidirectional_iterator_tag, T > {
	friend bool operator==<T>(const BlobPtr<T>&, const BlobPtr<T>&);
public:
	BlobPtr() :curr(0){}
	BlobPtr(Blob<T> &a, size_t sz = 0) :
		wpt(a.data), curr(sz){}
	T& operator[](size_t i){
		auto p = check(i, "subscript out of range");
		return (*p)[i];	//*p is the vector to which this pointer points
	}
	const T& operator[](size_t i)const{
		auto p = check(i, "subscript out of range");
		return (*p)[i];
	}
	T& operator*(){
		auto p = check(curr, "deference past end");
		return (*p)[curr];
	}
	T* operator->()const{
		//delegate the real work to the deference operator
		return &this->operator*();
	}

	//increment and decrement
	BlobPtr& operator++();	//prefix operator
	BlobPtr& operator--();

	BlobPtr operator++(int); //postfix operator
	BlobPtr operator--(int);

private:
	//check returns a shared_ptr to the vector if the check succeeds
	shared_ptr<vector<T>> check(size_t, const string &)const;
	//store a weak_ptr,which means the underlying vector may be destroyed
	weak_ptr<vector<T>>wpt;
	size_t curr;	//current position within the array
};

//equailty operators
template<typename T>
bool operator==(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
	return lhs.wpt.lock().get() == rhs.wpt.lock().get()
		&& rhs.curr == rhs.curr;
}

template<typename T>
bool operator!=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
	return !(lhs == rhs);
}

template<typename T>
shared_ptr<vector<T>> BlobPtr<T>::check(size_t i, const string &msg)const
{
	auto ret = wpt.lock();	//is the vector is still around?
	if (!ret)
		throw runtime_error("unbound BlobPtr");
	if (i >= ret->size())
		throw out_of_range(msg);
	return ret;	//otherwise,returns a shared_ptr to the vector
}

template<typename T>
inline
BlobPtr<T>& BlobPtr<T>::operator++()
{
	//if curr already points past end of the container,can't increment it
	check(curr, "increment past end of BlobPtr");
	++curr;	//advanced the current state
	return *this;
}

template<typename T>
inline
BlobPtr<T>& BlobPtr<T>::operator--()
{
	--curr;
	//if curr is zero,decrement it will yield an invalid subscript
	check(-1, "decrement past begin of BlobPtr");
	return *this;
}

//no check here,the call to prefix operator will do the check
template<typename T>
inline
BlobPtr<T> BlobPtr<T>::operator++(int)
{
	BlobPtr ret = *this;	//save the current value
	++*this;	//move backward one element,prefix-- checks the decrement
	return ret;	//return the saved state
}
template<typename T>
BlobPtr<T> BlobPtr<T>::operator--(int)
{
	BlobPtr ret = *this;
	--*this;
	return ret;
}
#endif // !BLOB_H
