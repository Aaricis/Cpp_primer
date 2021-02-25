#ifndef BINARYQUERY_H
#define BINARYQUERY_H

#include<iostream>
#include"Query_base.h"
using namespace std;

class BinaryQuery: public Query_base{
protected:
    BinaryQuery(const Query &l, const Query &r, string s): lhs(l), rhs(r), opSym(s) {
        cout<<"BinaryQuery: Constructor"<<endl;
    }
    string rep() const{
        cout<<"BinaryQuery: rep()"<<endl;
        return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
    }
    Query lhs, rhs;
    string opSym;
};
#endif