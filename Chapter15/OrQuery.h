#ifndef ORQUERY_H
#define ORQUERY_H

#include<iostream>
#include<memory>
#include"BinaryQuery.h"
#include"Query.h"
#include"TextQuery.h"

class OrQuery: public BinaryQuery{
    friend Query operator| (const Query&, const Query&);
    OrQuery(const Query &left, const Query &right):
        BinaryQuery(left, right, "|"){
            cout<<"OrQuery: Constructor"<<endl;
        }
    QueryResult eval(const TextQuery&) const;
};

inline Query operator| (const Query &lhs, const Query &rhs){
    return shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

QueryResult OrQuery::eval(const TextQuery& text) const{
    auto right = rhs.eval(text), left = lhs.eval(text);
    auto ret_lines = make_shared<set<line_no>>(left.begin(), left.end());
    ret_lines->insert(right.begin(), right.end());
    return QueryResult(rep(), ret_lines, left.get_file());
}
#endif