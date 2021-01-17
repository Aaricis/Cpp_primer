#include<iostream>
#include<string>
#include<memory>
#include<initializer_list>
using namespace std;

class StrVec{
public:
    StrVec():elements(nullptr), first_free(nullptr), cap(nullptr){}
    StrVec(const StrVec&);
    StrVec(initializer_list<string>&);

    StrVec &operator=(const StrVec&);
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
        for_each(elements, first_free, [this](string &rhs){alloca.destory(&rhs);})
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