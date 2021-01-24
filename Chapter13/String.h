#ifndef STRING_H
#define STRING_H

#include<iostream>
#include<memory>
#include<initializer_list>
#include<cstring>
using namespace std;

class String{
    friend String operator+(const String&, const String&);
    friend String add(const String&, const String&);
    friend ostream &operator<<(ostream&, const String&);
    friend ostream &print(ostream&, const String&);

public:
    String():sz(0), p(nullptr){}
    String(const char *cp):sz(strlen(cp)), p(alloc.allocate(sz)){
        uninitialized_copy(cp, cp+sz, p);
    }
    String(const String& s):sz(s.sz), p(alloc.allocate(sz)){
        uninitialized_copy(s.p, s.p+sz, p);
    }
    String(size_t n, char c):sz(n), p(alloc.allocate(n)){
        uninitialized_fill_n(p, n, c);
    }

    ~String(){if(p) alloc.deallocate(p, sz);}
    String &operator=(const String &);
    String &operator=(const char *);
    String &operator=(char);
    String &operator=(initializer_list<char>);

    const char *begin(){return p;}
    const char *begin()const {return p;}
    const char *end(){return p+sz;}
    const char *end()const {return p+sz;}

    size_t size() const {return sz;}
    void swap(String &s){
        char* temp = p;
        p = s.p;
        s.p = temp;

        int cnt = sz;
        sz = s.sz;
        s.sz = cnt;
    }

private:
    
    size_t sz;
    char *p;
    static allocator<char> alloc;
};

String make_plural(size_t ctr, const String&, const String&);
inline void swap(String& s1, String& s2){
    s1.swap(s2);
}

allocator<char> String::alloc;

String& String::operator=(const String &rhs){
    auto newp = alloc.allocate(rhs.sz);
    uninitialized_copy(rhs.p, rhs.p+rhs.sz, newp);

    if(p)
        alloc.deallocate(p, sz);
    
    p = newp;
    sz = rhs.sz;

    return *this;
}

String& String::operator=(const char *cp){
    if(p) alloc.deallocate(p, sz);
    p = alloc.allocate(sz = strlen(cp));
    uninitialized_copy(cp, cp+sz, p);
    return *this;
}

String& String::operator=(char c){
    if(p) alloc.deallocate(p, sz);
    p = alloc.allocate(sz=1);
    *p = c;
    return *this;
}

String& String::operator=(initializer_list<char> il){
    if(p) alloc.deallocate(p, sz);
    p = alloc.allocate(il.size());
    uninitialized_copy(il.begin(), il.end(), p);
    return *this;
}

ostream& print(ostream &os, const String &s){
    auto p = s.begin();
    while(p != s.end()){
        os<<*p++;
    }
    return os;
}

String add(const String &lhs, const String &rhs){
    String ret;
    ret.sz = lhs.size()+rhs.size();
    ret.p = String::alloc.allocate(ret.sz);
    uninitialized_copy(lhs.begin(), lhs.end(), ret.p);
    uninitialized_copy(rhs.begin(), rhs.end(), ret.p+lhs.sz);
    return ret;
}

String make_plural(size_t ctr, const String& word, const String& ending){
    return ctr==1? word:add(word, ending);
}

ostream& operator<<(ostream& os, const String& s){
    return print(os, s);
}

String operator+(const String &lhs, const String &rhs){
    return add(lhs, rhs);
}

#endif