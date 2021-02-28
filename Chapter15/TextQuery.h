#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<fstream>
#include<memory>
#include<sstream>
#include"ConstStrBlobPtr.h"
using namespace std;

class QueryResult;
class TextQuery{
    public:
        typedef vector<string>::size_type size_type;
        TextQuery(ifstream& infile);
        QueryResult query(const string&); 

    private:
        StrBlob text;
        map<string, shared_ptr<set<size_type>>> mp;
};

class QueryResult{
    using ResultIter = set<TextQuery::size_type> :: iterator;
    friend ostream& print(ostream&, const QueryResult&);
    private:
        string word;
        shared_ptr<set<TextQuery::size_type>> LineNo;
        StrBlob text;
    
    public:
        QueryResult(const string &str, shared_ptr<set<TextQuery::size_type>> no, StrBlob input) : word(str), LineNo(no), text(input){}
        ResultIter begin(){ return LineNo->begin();}
        ResultIter end(){ return LineNo->end();}
        shared_ptr<StrBlob> get_file(){ return make_shared<StrBlob>(text);}
};

TextQuery::TextQuery(ifstream& infile){
    string line;
    size_type count=0;
    while(getline(infile, line)){
        text.push_back(line);
        istringstream is(line);
        string str;
        while(is>>str){
            auto &t = mp[str];
            if(!t)
                t = make_shared<set<size_type>>();
            mp[str]->insert(count);
        }
        count++;
    }
}

QueryResult TextQuery::query(const string& str)
{
    auto found = mp.find(str);
    if (found == mp.end()) return QueryResult(str, make_shared<set<size_type>>(), text);
    else return QueryResult(str, found->second, text);
}

ostream& print(ostream& os, const QueryResult& q){
        os<<q.word<<" occurs "<<q.LineNo->size()<<(q.LineNo->size()>1? " times":"time")<<endl;
        for(auto i : *q.LineNo){
            ConstStrBlobPtr p(q.text, i);
            os<<"\t(line " << i+1 << ") "<<p.deref()<<endl;
        }
        return os;
}

void runQueries(ifstream &infile){
    TextQuery tq(infile);
    while(true){
        cout<<"enter word to look for, or q to quit: ";
        string s;
        if(!(cin>>s) || s=="q") break;
        print(cout, tq.query(s))<<endl;
    }
} 
