#ifndef STRING_H
#define STRING_H

#include <memory>
#include <algorithm>
#include <iostream>

class String
{

    friend bool operator==(const String&, const String&);
    friend bool operator!=(const String&, const String&);

public:
    String() : String("") { }
    String(const char *);
    String(const String&);

    //move constructor
    String(String&&) noexcept;

    String& operator=(const String&);
    //move-assignment operator
    String& operator=(String&&) noexcept;
    ~String();

    const char *c_str() const { return elements; }
    size_t size() const { return end - elements; }
    size_t length() const { return end - elements - 1; }

private:
    std::pair<char*, char*> alloc_n_copy(const char*, const char*);
    void range_initializer(const char*, const char*);
    void free();

private:
    char *elements;
    char *end;
    std::allocator<char> alloc;
};

bool operator==(const String&, const String&);
bool operator!=(const String&, const String&);

std::pair<char*, char*>
String::alloc_n_copy(const char *b, const char *e)
{
    auto str = alloc.allocate(e - b);
    return{ str, std::uninitialized_copy(b, e, str) };
}

void String::range_initializer(const char *first, const char *last)
{
    auto newstr = alloc_n_copy(first, last);
    elements = newstr.first;
    end = newstr.second;
}

String::String(const char *s)
{
    char *sl = const_cast<char*>(s);
    while (*sl)
        ++sl;
    range_initializer(s, ++sl);
}

String::String(const String& rhs)
{
    range_initializer(rhs.elements, rhs.end);
    std::cout << "copy constructor" << std::endl;
}

String::String(String&& s) noexcept : elements(s.elements), end(s.end){
    s.elements = s.end = nullptr;
    std::cout<<"move constructor"<<std::endl;
}

void String::free()
{
    if (elements) {
        std::for_each(elements, end, [this](char &c){ alloc.destroy(&c); });
        alloc.deallocate(elements, end - elements);
    }
}

String::~String()
{
    free();
}

String& String::operator = (const String &rhs)
{
    auto newstr = alloc_n_copy(rhs.elements, rhs.end);
    free();
    elements = newstr.first;
    end = newstr.second;
    std::cout << "copy-assignment" << std::endl;
    return *this;
}

String& String::operator = (String &&rhs) noexcept{
    if(this != &rhs){
        free();
        elements = rhs.elements;
        end = rhs.end;
        rhs.elements = rhs.end = nullptr;
    }
    std::cout<<"move-assignment"<<std::endl;
    return *this;
}

bool operator==(const String& lhs, const String& rhs){
    if(lhs.size()!=rhs.size()) return false;
    for(auto iter1 = lhs.elements, iter2 = rhs.elements; iter1 != lhs.end && iter2 != rhs.end; ++iter1, ++iter2){
        if(*iter1 != *iter2) return false;
    }
    return true;
}
bool operator!=(const String& lhs, const String& rhs){
    return !(lhs==rhs);
}

#endif