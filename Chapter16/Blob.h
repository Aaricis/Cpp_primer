#ifndef BLOB_H
#define BLOB_H

#include <iterator>
#include <string>
#include <vector>
#include <initializer_list>
#include <cstddef>
#include <stdexcept>
#include <utility>
#include <memory>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <stdexcept>
using namespace std;

template <typename> class BlobPtr;
template <typename> class Blob;
template <typename T> 
    bool operator==(const Blob<T>&, const Blob<T>&);

template <typename T> class Blob{
    friend class BlobPtr<T>;
    friend bool operator==<T>
            (const Blob<T>&, const Blob<T>&);
public:
    typedef T value_type;
    typedef typename vector<T>::size_type size_type;

    Blob();
    Blob(initializer_list<T> il);

    size_type size() const {return data->size();}
    bool empty() const {return data->empty();}

    void push_back(const T &t) {data->push_back(t);}
    void push_back(T &&t) {data->push_back(std::move(t));}
    void pop_back();

    T& back();
    T& operator[](size_type i);

    const T& back() const;
    const T& operator[](size_type i) const;

private:
    shared_ptr<vector<T>> data;
    void check(size_type i, const string &msg) const;
    
};

template <typename T>
Blob<T>::Blob():data(make_shared<vector<T>>()){}

template <typename T>
Blob<T>::Blob(initializer_list<T> il):data(il.begin(), il.end()){}

template <typename T>
void Blob<T>::check(size_type i, const string &msg) const{
    if(i>=data.size()){
        throw out_of_range(msg);
    }
}

template <typename T>
void Blob<T>::pop_back(){
    check(0, "pop_back on empty Blob");
    data->pop_back();
}

template <typename T>
T& Blob<T>::back(){
    check(0, "back on empty Blob");
	return data->back();
}

template <typename T>
T& Blob<T>::operator[](size_type i){
    check(i, "subscript out of range");
	return (*data)[i];
}

template <typename T>
const T& Blob<T>::back() const{
    check(0, "back on empty Blob");
	return data->back();    
}

template <typename T>
const T& Blob<T>::operator[](size_type i) const{
    check(i, "subscript out of range");
	return (*data)[i];
}

template <typename T>
bool operator==(const Blob<T> lhs, const Blob<T> rhs){
    if (rhs.size() != lhs.size())
		return false;
	for (size_t i = 0; i < lhs.size(); ++i) {
		if (lhs[i] != rhs[i])
			return false;
	}
	return true;
}


template <typename T>
bool operator==(const BlobPtr<T>&, const BlobPtr<T>&);

template <typename T> class BlobPtr{
    friend bool operator==<T>(const BlobPtr<T>&, const BlobPtr<T>&);

public:
    BlobPtr():curr(0){}
    BlobPtr(Blob<T> &a, size_t sz = 0):wptr(a.data), curr(sz){}

    T& operator*() const{
        auto p = check(curr, "dereference past end"); 
	    return (*p)[curr];
    }

    BlobPtr& operator++();
    BlobPtr& operator--();

    BlobPtr& operator++(int);
    BlobPtr& operator--(int);


private:
    shared_ptr<vector<T>> check(size_t, const string&) const;
    weak_ptr<vector<T>> wptr;
    size_t curr;
};

template <typename T>
shared_ptr<vector<T>> BlobPtr<T>::check(size_t i, const string &msg) const{
    auto ret = wptr.lock();   
	if (!ret)
		throw runtime_error("unbound BlobPtr");
	if (i >= ret->size()) 
		throw out_of_range(msg);
	return ret; 
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator++(){
    check(curr, "increment past end of BlobPtr");
    ++curr;
    return *this;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator--(){
    --curr;
    check(-1, "decrement past begin of BlobPtr");
    return *this;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator++(int){
    BlobPtr ret = *this;
    ++*this;
    return ret;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator--(int){
    BlobPtr ret = *this;
    --*this;
    return ret;
}

template <typename T>
bool operator==(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs){
    return lhs.wptr.lock().get() == rhs.wptr.lock().get() && lhs.curr == rhs.curr;
}

#endif