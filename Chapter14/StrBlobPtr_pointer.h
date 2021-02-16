#ifndef STRBLOBPTR_POINTER_H
#define STRBLOBPTR_POINTER_H

#include "StrBlobPtr.h"
using namespace std;

class StrBlobPtr_pointer{
public:
    StrBlobPtr_pointer()=default;
    StrBlobPtr_pointer(StrBlobPtr *p):pointer(p){}
    StrBlobPtr& operator*()const;
    StrBlobPtr* operator->()const;
private:
    StrBlobPtr *pointer;
};

StrBlobPtr& StrBlobPtr_pointer::operator*()const{
    return *pointer;
}

StrBlobPtr* StrBlobPtr_pointer::operator->()const{
    return pointer;
}

#endif