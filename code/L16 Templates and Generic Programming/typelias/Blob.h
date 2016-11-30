#ifndef BLOB_H
#define BLOB_H
#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>
#include<memory>
#include<utility>
#include<iterator>
#include<cstddef>
#include<initializer_list>
using namespace std;

template<typename>class BlobPtr;
template<typename>class Blob;
template<typename T>
bool operator==(const Blob<T>&, const Blob<T>&);

template<typename T>
class Blob{
	friend class BlobPtr < T > ;
	friend bool operator==<T>(const Blob<T>&, const Blob<T>&);
	
public:
	typedef T value_type;
	typedef typename vector<string>::size_type size_type;

	Blob() :data(make_shared<vector<T>> ()){}
	Blob(initializer_list<T>il) :data(make_shared<vector<T>>(il)){}
	template<typename IT>Blob(IT b, IT e) : data(make_shared<vector<T>>(b, e)){}
	Blob(T *p, size_t n) :data(make_shared<vector<T>>(p, p + n)){}

	BlobPtr<T>& begin(){ return BlobPtr(*this); }
	BlobPtr<T>& end(){ return BlobPtr(*this, data->size();) }

	size_type size()const{ return data->size(); }
	bool empty()const{ return data->empty(); }

	void push_back(const T &t){ data->push_back(t); }
	void push_back(T &&t){ data->push_back(std::move(t)); }
	void pop_back();

	T& front();
	T& back();
	T& at(size_t);
	const T& front()const;
	const T& back()const;
	const T& at(size_type)const;

	T& operator[](size_type);
	const T& operator[](size_type)const;

	void swap(Blob<T> &b){ data.swap(b.data); }
private:
	shared_ptr<vector<T>>data;
	void check(size_type, const string&)const;
};

template<typename T>
void Blob<T>::check(size_type i, const string &msg)const
{
	if (i >= data->size())
		throw out_of_range(msg);
}

template<typename T>
void Blob<T>::pop_back()
{
	check(0, "pop_back on empty Blob");
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

//operators
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

template<typename T>
ostream& operator<<(ostream &os, const Blob<T> &t)
{
	os << "<";
	for (size_t i = 0; i != t.size(); ++i){
		os << t[i] << " ";
	}
	os << ">";
	return os;
}

template<typename T>
bool operator==(const BlobPtr<T>&, const BlobPtr<T>&);

template<typename T>
class BlobPtr :public iterator < bidirectional_iterator_tag, T > {
	friend bool operator==<T>(const BlobPtr<T>&, const BlobPtr<T>&);
public:
	BlobPtr() :curr(0){ }
	BlobPtr(Blob<T> &a, size_t sz = 0) :wpt(a.data), curr(sz){}

	T& operator[](size_t i){
		auto p = check(i, "subscript out of range");
		return (*p)[i];
	}
	const T& operator[](size_t i)const{
		auto p = check(i, "subscript out of range");
		return (*p)[i];
	}
	T& operator*()const{
		auto p = check(curr, "deference past end");
		return (*p)[curr];
	}
	T* operator->()const{
		return &this->operator*();
	}

	//increment and decrement
	BlobPtr& operator++();	//prefix operators
	BlobPtr& operator--();

	BlobPtr operator++(int);	//postfix operators
	BlobPtr operator--(int);
private:
	shared_ptr<vector<T>> check(size_t i, const string &msg)const;
	weak_ptr<vector<T>>wpt;
	size_t curr;
};

template<typename T>
bool operator==(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
	return lhs.lock().get() == rhs.lock().get() &&
		lhs.curr == rhs.curr;
}

template<typename T>
bool operator!=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
	return !(lhs == rhs);
}

template<typename T>
shared_ptr<vector<T>> BlobPtr<T>::check(size_t i, const string &msg)const
{
	if (!wpt.lock())
		return runtime_error("unbound vector");
	if (i >= wpt.lock()->size())
		throw out_of_range(msg);
	return wpt.lock();
}

//prefix
template<typename T>
BlobPtr<T>& BlobPtr<T>::operator++()
{
	check(curr, "increment past end of BlobPtr");
	++curr;
	return *this;
}

template<typename T>
BlobPtr<T>& BlobPtr<T>::operator--()
{
	check(0, "decrement past begin of BlobPtr");
	--curr;
	return *this;
}

//postfix
template<typename T>
BlobPtr<T> BlobPtr<T>::operator++(int)
{
	BlobPtr ret = *this;
	++*this;
	return ret;
}

template<typename T>
BlobPtr<T> BlobPtr<T>::operator--(int)
{
	BlobPtr ret = *this;
	--*this;
	return ret;
}
#endif // !BLOB_H
