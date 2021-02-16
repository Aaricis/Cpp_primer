#ifndef STRBLOB_H
#define STRBLOB_H

#include<iostream>
#include<string>
#include<vector>
#include<memory>
#include<stdexcept>
using namespace std;

class StrBlob{
    friend bool operator==(const StrBlob&, const StrBlob&);
    friend bool operator!=(const StrBlob&, const StrBlob&);
    friend bool operator<(const StrBlob&, const StrBlob&);
    friend bool operator>(const StrBlob&, const StrBlob&);
    friend bool operator<=(const StrBlob&, const StrBlob&);
    friend bool operator>=(const StrBlob&, const StrBlob&);

public:
    typedef vector<string>::size_type size_type;
    StrBlob();
    StrBlob(initializer_list<string> il);
    size_type size() const {return data->size();}
    bool empty() const {return data->empty();}

    void push_back(const string &t) {data->push_back(t);}
    void pop_back();

    string& front();
    const string& front() const;

    string& back();
    const string& back() const;

    string& operator[](size_type n){
        return (*data)[n];
    }

    const string& operator[](size_type n) const{
        return (*data)[n];
    }


private:
    shared_ptr<vector<string>> data;
    void check(size_type i, const string &msg) const;    
};

bool operator==(const StrBlob&, const StrBlob&);
bool operator!=(const StrBlob&, const StrBlob&);
bool operator<(const StrBlob&, const StrBlob&);
bool operator>(const StrBlob&, const StrBlob&);
bool operator<=(const StrBlob&, const StrBlob&);
bool operator>=(const StrBlob&, const StrBlob&);

StrBlob::StrBlob(): data(make_shared<vector<string>>()) {}
StrBlob::StrBlob(initializer_list<string> il): data(make_shared<vector<string>>(il)) {}

void StrBlob::check(size_type i, const string &msg) const{
    if(i>=data->size())
        throw out_of_range(msg);
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

bool operator==(const StrBlob& u, const StrBlob& v){
    return *u.data == *v.data;
}

bool operator!=(const StrBlob& u, const StrBlob& v){
    return !(u==v);
}

bool operator<(const StrBlob& u, const StrBlob& v){
    return *(u.data)<*(v.data);      
}

bool operator>(const StrBlob& u, const StrBlob& v){
    return v<u;
}

bool operator<=(const StrBlob& u, const StrBlob& v){
    return !(u>v);
}

bool operator>=(const StrBlob& u, const StrBlob& v){
    return !(u<v);
}
#endif