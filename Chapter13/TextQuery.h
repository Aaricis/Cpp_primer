#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include<string>
#include<fstream>
#include<map>
#include<set>
#include<memory>
#include<sstream>
#include<algorithm>
#include<iostream>
#include "StrVec.h"
using namespace std;

class QueryResult;

class TextQuery{
    public:
        TextQuery(ifstream&);
        QueryResult query(const string&) const;
    
    private:
        shared_ptr<StrVec> file;
        map<string, shared_ptr<set<size_t>>> wm;
};


class QueryResult {
public:
    friend ostream& print(ostream &, const QueryResult&);
public:
    QueryResult(const string &s, shared_ptr<set<size_t>> set, shared_ptr<StrVec> v) : word(s), nos(set), input(v) { }
private:
    string word;
    shared_ptr<std::set<size_t>> nos;
    shared_ptr<StrVec> input;
};

ostream& print(std::ostream &, const QueryResult&);

TextQuery :: TextQuery(ifstream &ifs):file(new StrVec){
    string text;
    while(getline(ifs, text)){
        file->push_back(text);
        int n = file->size()-1;
        istringstream line(text);
        string word;
        while(line>>word){
            auto &lines = wm[word];
            if(!lines)
                lines.reset(new set<size_t>);
            lines->insert(n);
        }
    }
}

QueryResult TextQuery::query(const string& str) const
{
    static shared_ptr<set<size_t>> nodate(new set<size_t>);
    auto found = wm.find(str);
    if (found == wm.end()) return QueryResult(str, nodate, file);
    else return QueryResult(str, found->second, file);
}

ostream& print(ostream &out, const QueryResult& qr)
{
    out << qr.word << " occurs " << qr.nos->size() << (qr.nos->size() > 1 ? " times" : " time") << endl;
    for (auto i : *qr.nos)
        out << "\t(line " << i+1 << ") " << qr.input->at(i) << endl;
    return out;
}

#endif