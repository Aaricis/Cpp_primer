#ifndef STRVEC_H
#define STRVEC_H

#include<iostream>
#include<string>
#include<memory>
#include<initializer_list>
using namespace std;

class StrVec{
    friend bool operator==(const StrVec&, const StrVec&);
    friend bool operator!=(const StrVec&, const StrVec&);
    friend bool operator<(const StrVec&, const StrVec&);
    friend bool operator>(const StrVec&, const StrVec&);
    friend bool operator<=(const StrVec&, const StrVec&);
    friend bool operator>=(const StrVec&, const StrVec&);
public:
    StrVec():elements(nullptr), first_free(nullptr), cap(nullptr){}
    StrVec(const StrVec&);
    StrVec(initializer_list<string>&);

    //move constructor
    StrVec(StrVec &&s) noexcept : elements(s.elements), first_free(s.first_free), cap(s.cap){
        s.elements = s.first_free = s.cap = nullptr;
    }

    StrVec &operator=(const StrVec&);

    //move-assignment operator
    StrVec &operator=(StrVec &&) noexcept;

    ~StrVec();
    void push_back(const string&);

    void reserve(size_t n);
    void resize(size_t n);
    void resize(size_t n, const string&);

    size_t size() const {return first_free-elements;}
    size_t capacity() const {return cap-elements;}
    string *begin() const {return elements;}
    string *end() const {return first_free;}
    string& at(size_t pos) { return *(elements + pos); }
private:
    allocator<string> alloc;

    void chk_n_alloc(){
        if(size()==capacity()){
            reallocate();
        }
    }

    pair<string*, string*> alloc_n_copy(const string*, const string*);
    void free();
    void reallocate();
    string *elements;
    string *first_free;
    string *cap;

};

bool operator==(const StrVec&, const StrVec&);
bool operator!=(const StrVec&, const StrVec&);
bool operator<(const StrVec&, const StrVec&);
bool operator>(const StrVec&, const StrVec&);
bool operator<=(const StrVec&, const StrVec&);
bool operator>=(const StrVec&, const StrVec&);

void StrVec::push_back(const string& s){
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

pair<string*, string*> StrVec::alloc_n_copy(const string* b, const string* e){
    auto data = alloc.allocate(e-b);
    return {data, uninitialized_copy(b, e, data)};
}

void StrVec::free(){
    if(elements){
        for(auto p=first_free; p!=elements; ){
            alloc.destroy(--p);
        }
        alloc.deallocate(elements, cap-elements);
    }
}

StrVec::StrVec(const StrVec &s){
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::StrVec(initializer_list<string>& il){
    auto newdata = alloc_n_copy(il.begin(), il.end());
    elements = newdata.first;
    first_free = cap = newdata.second;

}

StrVec::~StrVec(){
    free();
}

StrVec &StrVec::operator=(const StrVec &rhs){
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

StrVec &StrVec::operator=(StrVec &&rhs) noexcept{
    if(this != &rhs){
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;

        rhs.elements = rhs.first_free = rhs.cap;
    }
    return *this;
}

void StrVec::reallocate(){
    auto newcapacity = size()? 2*size() : 1;
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;
    auto elem = elements;
    for(size_t i=0; i!=size(); ++i){
        alloc.construct(dest++, std::move(*elem++));
    }
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

void StrVec::reserve(size_t n){
    if(n <= capacity()) return;
    auto newdata = alloc.allocate(n);
    auto dest = newdata;
    auto elem = elements;
    for(size_t i=0; i!=size(); ++i){
        alloc.construct(dest++, std::move(*elem++));
    }
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + n;
}

void StrVec::resize(size_t n){
    resize(n, string());    
}

void StrVec::resize(size_t n, const string& s){
    if(n == size()) return;
    else if(n > size()){
        if(n > capacity()) reserve(n*2);
        for(size_t i=size(); i<n; ++i){
            alloc.construct(first_free++, s);
        }
    }
    else{
        while(first_free != elements+n){
            alloc.destroy(--first_free);
        }
    }
}

bool operator==(const StrVec& lhs, const StrVec& rhs){
    if(lhs.size() != rhs.size()) return false;

    for(auto iter1 = lhs.begin(), iter2 = rhs.begin(); iter1 != lhs.end() && iter2 != rhs.end(); ++iter1, ++iter2){
        if(*iter1 != *iter2) return false;
    }

    return true;
}
bool operator!=(const StrVec& lhs, const StrVec& rhs){
    return !(lhs==rhs);
}

bool operator<(const StrVec& s1, const StrVec& s2){
    string *b1, *b2;
    for(b1 = s1.elements, b2 = s2.elements; b1 != s1.first_free && b2 != s2.first_free; ++b1, ++b2){
        if(*b1 < *b2) return true;
        else if(*b1 > *b2) return false;
    }    
    if(b1==s1.first_free && b2<s2.first_free)
        return true;
    
    return false;
}
bool operator>(const StrVec& s1, const StrVec& s2){
    return !(s1<s2);
}
bool operator<=(const StrVec& s1, const StrVec& s2){
    return !(s1>s2);
}
bool operator>=(const StrVec& s1, const StrVec& s2){
    return !(s1<s2);
}
#endif
