#ifndef WORDQUERY_H
#define WORDQUERY_H

#include<iostream>
#include"Query_base.h"
using namespace std;

class WordQuery: public Query_base{
    friend class Query;
    WordQuery(const string &s): query_word(s){
       cout<<"WordQuery: constructor"<<endl;
    }
    QueryResult eval(const TextQuery &t) const{
        return t.query(query_word);
    }
    string rep() const {
        cout<<"WordQuery: rep()"<<endl;
        return query_word;
    }
    string query_word;
};
#endif