#include <memory>
#include <algorithm>
#include <iostream>
using namespace std;

class String
{
    friend ostream &operator<<(ostream&, const String&);
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
    pair<char*, char*> alloc_n_copy(const char*, const char*);
    void range_initializer(const char*, const char*);
    void free();

private:
    char *elements;
    char *end;
    allocator<char> alloc;
};


ostream &operator<<(ostream&, const String&);

pair<char*, char*>
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
    cout<<"copy constructor"<<endl;
}

String::String(String&& s) noexcept : elements(s.elements), end(s.end){
    s.elements = s.end = nullptr;
    cout<<"move constructor"<<endl;
}

void String::free()
{
    if (elements) {
        for_each(elements, end, [this](char &c){ alloc.destroy(&c); });
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
    cout << "copy-assignment" <<endl;
    return *this;
}

String& String::operator = (String &&rhs) noexcept{
    if(this != &rhs){
        free();
        elements = rhs.elements;
        end = rhs.end;
        rhs.elements = rhs.end = nullptr;
    }
    cout<<"move-assignment"<<endl;
    return *this;
}

ostream &operator<<(ostream &os, const String& str){
    char *c = const_cast<char*>(str.c_str());
    while(*c){
        os<<*c++;
    }
    return os;
}