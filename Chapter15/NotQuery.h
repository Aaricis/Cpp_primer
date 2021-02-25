#ifndef NOTQUERY_H
#define NOTQUERY_H

#include<iostream>
#include"Query_base.h"
#include"Query.h"
using namespace std;

class NotQuery: public Query_base{
    friend Query operator~(const Query &);
    NotQuery(const Query &q):query(q){
        cout<<"NotQuery: Constructor"<<endl;
    }
    string rep() const {
        cout<<"NotQuery: rep()"<<endl;
        return "~(" + query.rep() + ")";
    }
    QueryResult eval(const TextQuery&) const;
    Query query;
};

inline Query operator~(const Query &operand){
    return shared_ptr<Query_base>(new NotQuery(operand));
}
#endif