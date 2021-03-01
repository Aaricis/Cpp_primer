#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include<iostream>
#include<fstream>
#include<memory>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<sstream>
using namespace std;

class QueryResult;

class TextQuery{
public:
    using line_no = vector<string>::size_type;
    TextQuery(ifstream&);
    QueryResult query(const string&) const;
    TextQuery(const TextQuery& tq) = default;
    TextQuery &operator=(const TextQuery& tq) = default;
    ~TextQuery() = default;
private:
    shared_ptr<vector<string>> file;
    map<string, shared_ptr<set<line_no>>> wm;
};

class QueryResult{
    friend ostream& print(ostream&, const QueryResult&);
public:
    QueryResult(string s, shared_ptr<set<TextQuery::line_no>> p, shared_ptr<vector<string>> f):sought(s), lines(p), file(f){}
    set<TextQuery::line_no>::iterator begin();
    set<TextQuery::line_no>::iterator end();
    shared_ptr<vector<string>> get_file();
private:
    string sought;
    shared_ptr<set<TextQuery::line_no>> lines;
    shared_ptr<vector<string>> file;
};

string make_plural(size_t ctr, const string &word, const string &ending){
    return (ctr > 1)? word + ending : word;
}

TextQuery::TextQuery(ifstream &is):file(new vector<string>){
    string text;
    while(getline(is, text)){
        file->push_back(text);
        int n = file->size()-1;
        istringstream line(text);
        string word;
        while(line >> word){
            shared_ptr<set<line_no>> &lines = wm[word];
            if(lines)
                lines.reset(new set<line_no>);
            lines->insert(n);
        }
    }
}

QueryResult TextQuery::query(const string& sought) const{
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    map<string, shared_ptr<set<line_no>>>::const_iterator loc = wm.find(sought);
    if(loc == wm.cend())
        return QueryResult(sought, nodata, file);
    else
    {
        return QueryResult(sought, loc->second, file);
    }
    
}

set<TextQuery::line_no>::iterator QueryResult::begin(){
    return lines->begin();
}

set<TextQuery::line_no>::iterator QueryResult::end(){
    return lines->end();
}

shared_ptr<vector<string>> QueryResult::get_file(){
    return file;
}

ostream& print(ostream& os, const QueryResult &qr){
    os<<qr.sought<<" occurs "<<qr.lines->size()<<" "<<make_plural(qr.lines->size(), "time", "s")<<endl;
    for(TextQuery::line_no num : *qr.lines){
        os<<"\t(line "<<num+1<<") "<< *(qr.file->begin()+num)<<endl;
    }
    return os;
}

#endif