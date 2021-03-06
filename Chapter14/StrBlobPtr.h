#ifndef STRBLOBPTR_H
#define STRBLOBPTR_H

#include<memory>
#include<vector>
#include<string>
#include<stdexcept>

using namespace std;

class StrBlobPtr;

class StrBlob{
    friend class StrBlobPtr;
    public:
        typedef vector<string>::size_type size_type;
        StrBlob();
        StrBlob(initializer_list<string> il);
        size_type size() const {return data->size();}
        bool empty() const { return data->empty();}
        
        void push_back(const string &t) {data->push_back(t);}
        void pop_back();

        string& front();
        const string& front() const;
        string& back();
        const string& back() const;
        StrBlobPtr begin();
        StrBlobPtr end();     
    
    private:
        shared_ptr<vector<string>> data;
        void check(size_type i, const string &msg) const;

        
};

StrBlob::StrBlob() : data(make_shared<vector<string>>()){}
StrBlob::StrBlob(initializer_list<string> il) : data(make_shared<vector<string>> (il)) {}

void StrBlob::check(size_type i, const string &msg) const{
    if(i>=data->size()){
        throw out_of_range(msg);
    }
}

string& StrBlob::front(){
    check(0, "front on empty StrBlob");
    return data->front();
}

const string& StrBlob::front() const{
    check(0, "front on empty StrBlob");
    return data->front();
}

string& StrBlob::back(){
    check(0, "back on empty StrBlob");
    return data->back();
}

const string& StrBlob::back() const{
    check(0, "back on empty StrBlob");
    return data->back();
}

void StrBlob::pop_back(){
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

class StrBlobPtr{

    friend bool operator==(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator!=(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator<(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator>(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator<=(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator>=(const StrBlobPtr&, const StrBlobPtr&);

    public:
        StrBlobPtr():curr(0) { }
        StrBlobPtr(StrBlob &a, size_t sz = 0):wptr(a.data), curr(sz) {}
        string& deref() const;
        StrBlobPtr& incr();

        string& operator[](size_t n);
        const string& operator[](size_t n) const;

        StrBlobPtr& operator++();
        StrBlobPtr& operator--();
        StrBlobPtr operator++(int);
        StrBlobPtr operator--(int);

        StrBlobPtr& operator+=(size_t);
        StrBlobPtr& operator-=(size_t);
        StrBlobPtr operator+(size_t) const;
        StrBlobPtr operator-(size_t) const;
        
        string& operator*() const;
        string* operator->() const;

    private:
        shared_ptr<vector<string>> check(size_t, const string&) const;
        weak_ptr<vector<string>> wptr;
        size_t curr;
};

bool operator==(const StrBlobPtr&, const StrBlobPtr&);
bool operator!=(const StrBlobPtr&, const StrBlobPtr&);
bool operator<(const StrBlobPtr&, const StrBlobPtr&);
bool operator>(const StrBlobPtr&, const StrBlobPtr&);
bool operator<=(const StrBlobPtr&, const StrBlobPtr&);
bool operator>=(const StrBlobPtr&, const StrBlobPtr&);

StrBlobPtr StrBlob::begin()
{
    return StrBlobPtr(*this);
}
StrBlobPtr StrBlob::end()
{
    auto ret=StrBlobPtr(*this,data->size());
    return ret;
}


shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string &msg) const{
    auto ret = wptr.lock();
    if(!ret)
        throw runtime_error("unbound StrBlobPtr");
    if(i>=ret->size())
        throw out_of_range(msg);
    return ret;
}

string& StrBlobPtr::deref() const{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr(){
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

string& StrBlobPtr::operator[](size_t n){
    return (*wptr.lock())[n];
}

const string& StrBlobPtr::operator[](size_t n) const{
    return (*wptr.lock())[n];
}

StrBlobPtr& StrBlobPtr::operator++(){
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

StrBlobPtr& StrBlobPtr::operator--(){
    --curr;
    check(curr, "decrement past begin of StrBlobPtr");
    return *this;
}

StrBlobPtr StrBlobPtr::operator++(int){
    StrBlobPtr ret = *this;
    ++*this;
    return ret;
}

StrBlobPtr StrBlobPtr::operator--(int){
    StrBlobPtr ret = *this;
    --*this;
    return ret;
}

StrBlobPtr& StrBlobPtr::operator+=(size_t n){
    curr += n;
    check(curr, "increment past end of StrBlobPtr");
    return *this;
}

StrBlobPtr& StrBlobPtr::operator-=(size_t n){
    curr -= n;
    check(curr, "decrement past begin of StrBlobPtr");
    return *this;
}

StrBlobPtr StrBlobPtr::operator+(size_t n) const{
    StrBlobPtr ret = *this;
    ret += n; 
    return ret;
}

StrBlobPtr StrBlobPtr::operator-(size_t n) const{
    StrBlobPtr ret = *this;
    ret -= n;
    return ret;
}

string& StrBlobPtr::operator*() const{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

string* StrBlobPtr::operator->() const{
    return &this->operator*();
}

bool operator==(const StrBlobPtr& lhs, const StrBlobPtr& rhs){
    auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
    if(l==r)
        return (!r || lhs.curr==rhs.curr);
    else
        return false;
}

bool operator!=(const StrBlobPtr& u, const StrBlobPtr& v){
    return !(u==v);
}

bool operator<(const StrBlobPtr& lhs, const StrBlobPtr& rhs){
    auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
    if(l==r){
        if(!r) return false;
        return lhs.curr<rhs.curr;
    }
    return false;
}
bool operator>(const StrBlobPtr& lhs, const StrBlobPtr& rhs){
    auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
    if(l==r){
        if(!r) return false;
        return lhs.curr>rhs.curr;
    }
    return false;
}
bool operator<=(const StrBlobPtr& lhs, const StrBlobPtr& rhs){
    auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
    if(l==r){
        return (!r || lhs.curr<=rhs.curr);
    }
    return false;
}
bool operator>=(const StrBlobPtr& lhs, const StrBlobPtr& rhs){
    auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
    if(l==r){
        return (!r || lhs.curr>=rhs.curr);
    }
    return false;    
}
#endif