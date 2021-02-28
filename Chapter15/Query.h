#include<iostream>
#include<string>
#include<memory>
#include"Query_base.h"
#include"TextQuery.h"
#include"WordQuery.h"
using namespace std;

class Query{
    friend Query operator~(const Query &);
    friend Query operator|(const Query&, const Query&);
    friend Query operator&(const Query&, const Query&);
public:
    Query(const string& s):q(new WordQuery(s)){}
    QueryResult eval(const TextQuery &t) const{
        return q->eval(t);
    }
    string rep() const{
        return q->rep();
    }
private:
    Query(shared_ptr<Query_base> query):q(query){}
    shared_ptr<Query_base> q;
};

ostream &operator<<(ostream &os, const Query &query){
    return os<<query.rep();
}