#ifndef QUERYRESULT_H
#define QUERYRESULT_H

#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<memory>
using namespace std;

class QueryResult{
    friend ostream& print(ostream&, QueryResult&);
    public:
        using line_no = vector<string>::size_type;
        QueryResult(string s, shared_ptr<set<line_no>> p, shared_ptr<vector<string>> f): sought(s), lines(p), file(f){}
    private:
        string sought;
        shared_ptr<set<line_no>> lines;
        shared_ptr<vector<string>> file;
};

ostream &print(ostream& os, QueryResult &qr){
    os<<qr.sought<<" occurs "<<qr.lines->size()<<" "<<(qr.lines->size()>1? " times":"time")<<endl;
    for(auto num:*qr.lines){
        os<<"\t(lines "<<num+1<<")"<<*(qr.file->begin()+num)<<endl;
    }
    return os;
}
#endif