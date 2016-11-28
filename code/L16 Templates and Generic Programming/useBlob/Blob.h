#ifndef BLOB_H
#define BLOB_H

#include<iostream>
#include<algorithm>
#include<stdexcept>
#include<cstddef>
#include<string>
#include<vector>
#include<memory>
#include<initializer_list>
#include<utility>
#include<iterator>
#include<cstdlib>
using namespace std;

template<typename>class BlobPtr;
template<typename>class Blob;
template<typename T>
bool operator==(const Blob<T>&, const Blob<T>&);

template<typename T>
class Blob{
	friend class BlobPtr < T > ;
	friend bool operator==<T>(const Blob<T>&, const Blob<T>&);
	//friend ostream& operator<<<T>(ostream&, const Blob<T>&);
public:
	typedef T value_type;
	typedef typename vector<T>::size_type size_type;

	//constructors
	Blob() :data(make_shared<vector<T>>()){}
	Blob(initializer_list<T>il) :data(make_shared<vector<T>>(il)){}
	template<typename IT>Blob(IT b, IT e) : data(make_shared<vector<T>>(b, e)){}
	Blob(T *p, size_t i) :data(make_shared<vector<T>>(p, p + i)){}

	//numbers of elements in the Blob
	size_type size()const{ return data->size(); }
	bool empty()const{ return data->empty(); }

	//return BlobPtr to the first and one past the last element
	BlobPtr<T> begin(){ return BlobPtr<T>(*this); }
	BlobPtr<T> end(){ return BlobPtr<T>(*this, data->size()); }

	//add and remove elements
	void push_back(const T& t){ return data->push_back(t); }
	void push_back(T &&t){ return data->push_back(std::move(t)); }
	void pop_back();
	
	//elment access
	T& front();
	T& back();
	T& at(size_type);
	const T& front()const;
	const T& back()const;
	const T& at(size_type)const;

	//subscript operator
	T& operator[](size_type);
	const T& operator[](size_type)const;

	void swap(Blob &b){ data.swap(b.data); }
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

template<typename T>
ostream& operator<<(ostream &os, const Blob<T> t)
{
	os << "<";
	for (size_t i = 0; i != t.size(); ++i){
		os << t[i] << " ";
	}
	os << ">";
	return os;
}

template<typename T>
bool operator==(const Blob<T>& lhs, const Blob<T>& rhs)
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
bool operator==(const BlobPtr<T>&, const BlobPtr<T>&);
template<typename T>
bool operator!=(const BlobPtr<T>&, const BlobPtr<T>&);

template<typename T>
class BlobPtr :public iterator < bidirectional_iterator_tag, T > {
	friend bool operator==<T>(const BlobPtr<T>&, const BlobPtr<T>&);
	friend bool operator!=<T>(const BlobPtr<T>&, const BlobPtr<T>&);
public:
	BlobPtr() :curr(0){}
	BlobPtr(Blob<T>&a, size_t sz = 0) :wpt(a.data), curr(sz){}

	//operators
	T& operator[](size_t i){
		auto p = check(i, "subscript out of range");
		return (*p)[i];
	}
	const T& operator[](size_t i)const{
		auto p = check(i, "subscript out of range");
		return (*p)[i];
	}
	T& operator*()const{
		auto p = check(curr, "deference past the end");
		return (*p)[curr];
	}
	T* operator->()const{
		return &this->operator*();
	}

	//increment and decrenment
	BlobPtr& operator++();	//prefix operators
	BlobPtr& operator--();
	BlobPtr& operator++(int);	//postfix operators
	BlobPtr& operator--(int);
private:
	shared_ptr<vector<T>> check(size_t, const string&)const;
	size_t curr;
	weak_ptr<vector<T>>wpt;
};

//check member
template<typename T>
shared_ptr<vector<T>> BlobPtr<T>::check(size_t i, const string &msg)const
{
	auto ret = wpt.lock();
	if (!ret)
		throw runtime_error("unbound vector");
	if (i >= ret->size())
		throw out_of_range(msg);
	return ret;
}

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

template<typename T>
BlobPtr<T>& BlobPtr<T>::operator++(int)
{
	auto ret = *this;
	++*this;
	return ret;
}

template<typename T>
BlobPtr<T>& BlobPtr<T>::operator--(int)
{
	auto ret = *this;
	--*this;
	return ret;
}

template<typename T>
bool operator==(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
	return lhs.wpt.lock().get() == rhs.wpt.lock().get() &&
		lhs.curr == rhs.curr;
}

template<typename T>
bool operator!=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
	return !(lhs == rhs);
}


#endif // !BLOB_H
