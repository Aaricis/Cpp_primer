#ifndef ANDQUERY_H
#define ANDQUERY_H

#include<iostream>
#include<memory>
#include"BinaryQuery.h"
#include"QueryResult.h"
#include"TextQuery.h"
using namespace std;

class AndQuery: public BinaryQuery{
    friend Query operator&(const Query&, const Query&);
    AndQuery(const Query &left, const Query &right):BinaryQuery(left, right, "&"){
        cout<<"AndQuery: Constructor"<<endl;
    }
    //QueryResult eval(const TextQuery&) const;
};

inline Query operator& (const Query &lhs, const Query &rhs){
    return shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}
#endif