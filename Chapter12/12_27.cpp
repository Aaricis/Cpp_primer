#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<fstream>
#include<memory>
#include<sstream>
using namespace std;

class QueryResult;
class TextQuery{
    public:
        typedef vector<string>::size_type size_type;
        TextQuery(ifstream& infile);
        QueryResult query(const string&); 

    private:
        shared_ptr<vector<string>> text;
        map<string, shared_ptr<set<size_type>>> mp;
};

class QueryResult{
    friend ostream& print(ostream&, const QueryResult&);
    private:
        string word;
        shared_ptr<set<TextQuery::size_type>> LineNo;
        shared_ptr<vector<string>> text;
    
    public:
        QueryResult(const string &str, shared_ptr<set<TextQuery::size_type>> no, shared_ptr<vector<string>> input) : word(str), LineNo(no), text(input){}
};

TextQuery::TextQuery(ifstream& infile):text(make_shared<vector<string>>()){
    string line;
    size_type count=0;
    while(getline(infile, line)){
        text->push_back(line);
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
            os<<"\t(line " << i+1 << ") "<<(*q.text)[i]<<endl;
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

int main(){
    ifstream file("text.txt");
    runQueries(file);
    return 0;
}