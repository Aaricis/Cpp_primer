#ifndef ORQUERY_H
#define ORQUERY_H

#include<iostream>
#include<memory>
#include"BinaryQuery.h"
#include"Query.h"
#include"QueryResult.h"
#include"Query.h"

class OrQuery: public BinaryQuery{
    friend Query operator| (const Query&, const Query&);
    OrQuery(const Query &left, const Query &right):
        BinaryQuery(left, right, "|"){
            cout<<"OrQuery: Constructor"<<endl;
        }
    //QueryResult eval(const TextQuery&) const;
};

inline Query operator| (const Query &lhs, const Query &rhs){
    return shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}
#endif