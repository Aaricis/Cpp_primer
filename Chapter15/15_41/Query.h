#ifndef QUERY_H
#define QUERY_H

#include<string>
#include<memory>
#include<set>
#include<algorithm>
#include<iterator>
#include"TextQuery.h"
using namespace std;

class Query_base{
    friend class Query;
protected:
    using line_no = TextQuery::line_no;
    virtual ~Query_base() = default;
private:
    virtual QueryResult eval(const TextQuery&) const = 0;
    virtual string rep() const = 0;
    virtual Query_base* clone() const & = 0;
    virtual Query_base* clone() && = 0;
};

class Query{
    friend Query operator~(const Query&);
    friend Query operator|(const Query&, const Query&);
    friend Query operator&(const Query&, const Query&);

public:
    Query(const string&);
    QueryResult eval(const TextQuery &t) const {return q->eval(t);}
    string rep() const {return q->rep();}

    ~Query() {delete q;}
    Query(const Query &rhs):q(rhs.q->clone()) {}
    Query(Query &&rhs):q(rhs.q){rhs.q = nullptr;}
    Query& operator=(const Query &rhs);
    Query& operator=(Query &&rhs);

private:
    Query(Query_base* query):q(query){}
    Query_base* q;
};

ostream &operator<<(ostream &os, const Query &query){
    return os<<query.rep();
}

class WordQuery : public Query_base{
    friend class Query;
    WordQuery(const string &s):query_word(s){}
    QueryResult eval(const TextQuery &t) const{return t.query(query_word);}
    string rep() const {return query_word;}

    Query_base* clone() const & {return new WordQuery(*this);}
    Query_base* clone() && {return new WordQuery(std::move(*this));}

    string query_word;
};

class NotQuery : public Query_base{
    friend Query operator~(const Query &);
    NotQuery(const Query &q):query(q){}
    string rep() const {return "~("+query.rep()+")";}
    QueryResult eval(const TextQuery &text) const;

    Query_base* clone() const & {return new NotQuery(*this);}
    Query_base* clone() && {return new NotQuery(std::move(*this));}

    Query query;
};

class BinaryQuery : public Query_base{
protected:
    BinaryQuery(const Query &l, const Query &r, string s):lhs(l), rhs(r), opSym(s){}
    string rep() const {return "("+lhs.rep()+" "+opSym+" "+rhs.rep()+")";}
    Query lhs, rhs;
    string opSym;
};

class AndQuery : public BinaryQuery{
    friend Query operator&(const Query&, const Query&);
    AndQuery(const Query &left, const Query &right):BinaryQuery(left, right, "&"){}
    QueryResult eval(const TextQuery &text) const;

    Query_base* clone() const & {return new AndQuery(*this);}
    Query_base* clone() && {return new AndQuery(std::move(*this));}
};

class OrQuery : public BinaryQuery{
    friend Query operator|(const Query&, const Query&);
    OrQuery(const Query &left, const Query &right):BinaryQuery(left, right, "|"){}
    QueryResult eval(const TextQuery &text) const;

    Query_base* clone() const &{return new OrQuery(*this);}
    Query_base* clone() && {return new OrQuery(std::move(*this));}
};

Query operator~(const Query&);
Query operator|(const Query&, const Query&);
Query operator&(const Query&, const Query&);


Query::Query(const string &s):q(new WordQuery(s)){}

Query operator~(const Query &operand){
    return new NotQuery(operand);
}

Query operator&(const Query &lhs, const Query &rhs){
    return new AndQuery(lhs, rhs);
}

Query operator|(const Query &lhs, const Query &rhs){
    return new OrQuery(lhs, rhs);
}

QueryResult OrQuery::eval(const TextQuery &text) const{
    QueryResult left = lhs.eval(text), right = rhs.eval(text);
    shared_ptr<set<line_no>> ret_lines = make_shared<set<line_no>>(left.begin(), left.end());
    ret_lines->insert(right.begin(), right.end());
    return QueryResult(rep(), ret_lines, left.get_file());
}

QueryResult AndQuery::eval(const TextQuery &text) const{
    QueryResult left = lhs.eval(text), right = rhs.eval(text);
    shared_ptr<set<line_no>> ret_lines = make_shared<set<line_no>>();
    set_intersection(left.begin(), left.end(), right.begin(), right.end(), inserter(*ret_lines, ret_lines->begin()));
    return QueryResult(rep(), ret_lines, left.get_file());
}

QueryResult NotQuery::eval(const TextQuery &text) const{
    QueryResult result = query.eval(text);
    shared_ptr<set<line_no>> ret_lines = make_shared<set<line_no>>();
    set<line_no>::iterator beg = result.begin(), end = result.end();
    line_no sz = result.get_file()->size();
    for(line_no n = 0; n != sz; ++n){
        if(beg == end || *beg != n)
            ret_lines->insert(n);
        else if(beg != end)
            ++beg;
    }
    return QueryResult(rep(), ret_lines, result.get_file());
}

Query &Query::operator=(const Query &rhs){
    if(this != &rhs){
        Query_base *p = rhs.q->clone();
        delete q;
        q = p;
    }
    return *this;
}

Query &Query::operator=(Query && rhs){
    if(this != &rhs){
        delete q;
        q = rhs.q;
        rhs.q = nullptr;
    }
    return *this;
}
#endif
