#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cstddef>
#include <algorithm>
#include <iterator>
#include <memory>
#include <new>

using namespace std;

class TextQuery;
class QueryResult;
class Query_base;
class WordQuery;
class NotQuery;
class BinaryQuery;
class AndQuery;
class OrQuery;
class Query;

class TextQuery
{
public:
    using LineNo = vector<string>::size_type;

    TextQuery(ifstream& ifs);

    QueryResult query(const string& str) const;

private:
    shared_ptr<vector<string>> content;
    map<string, shared_ptr<set<LineNo>>> result;
};

class QueryResult
{
public:
    friend ostream& print_queryresult(ostream& os, const QueryResult& result);

    QueryResult(const string& str, shared_ptr<set<TextQuery::LineNo>> no, shared_ptr<vector<string>> content) :
        word(str), lineno(no), content(content) {}

    set<TextQuery::LineNo>::iterator begin() { return lineno->begin(); }
    set<TextQuery::LineNo>::iterator end() { return lineno->end(); }
    shared_ptr<vector<string>> get_file() { return content; }

private:
    string word;
    shared_ptr<vector<string>> content;
    shared_ptr<set<TextQuery::LineNo>> lineno;
};

class Query_base
{
    friend class Query;
public:
    using LineNo = TextQuery::LineNo;
    virtual ~Query_base() = default;

private:
    virtual QueryResult eval(const TextQuery&) const = 0;
    virtual string rep() const = 0;
};

class WordQuery : public Query_base
{
    friend class Query;

private:
    WordQuery(const string& str) : query_word(str) {}

    QueryResult eval(const TextQuery& tq) const { return tq.query(query_word); }
    string rep() const { return query_word; }

    string query_word;
};

class Query
{
    friend Query operator~ (const Query&);
    friend Query operator| (const Query&, const Query&);
    friend Query operator& (const Query&, const Query&);

public:
    Query(const string& str) : sptr_qb(new WordQuery(str)) {}
    QueryResult eval(const TextQuery& t) const { return sptr_qb->eval(t); }
    string rep() const { return sptr_qb->rep(); }

private:
    shared_ptr<Query_base> sptr_qb;
    Query(shared_ptr<Query_base> q) : sptr_qb(q) {}
};

class NotQuery : public Query_base
{
    friend Query operator~ (const Query& q);

private:
    NotQuery(const Query& q) : query(q) {}

    string rep() const { return "~(" + query.rep() + ")"; }
    QueryResult eval(const TextQuery&) const;

    Query query;
};

class BinaryQuery : public Query_base
{
protected:
    BinaryQuery(const Query& q_1, const Query& q_2, string str) : q1(q_1), q2(q_2), operator_(str) {}

    string rep() const { return "(" + q1.rep() + " " + operator_ + " " + q2.rep() + ")"; }

    Query q1, q2;
    string operator_;
};

class AndQuery : public BinaryQuery
{
    friend Query operator& (const Query& q1, const Query& q2);

private:
    AndQuery(const Query& q1, const Query& q2) : BinaryQuery(q1, q2, "&") {}

    QueryResult eval(const TextQuery&) const;
};

class OrQuery : public BinaryQuery
{
    friend Query operator| (const Query& q1, const Query& q2);

private:
    OrQuery(const Query& q1, const Query& q2) : BinaryQuery(q1, q2, "|") {}

    QueryResult eval(const TextQuery&) const;
};

string make_plural(size_t ctr, const string& word, const string& ending);
ostream& print_queryresult(ostream& os, const QueryResult& result);
Query operator~ (const Query& q);
Query operator| (const Query& q1, const Query& q2);
Query operator& (const Query& q1, const Query& q2);
ostream& operator<< (ostream& os, const Query& q);

int main()
{
    ifstream ifs("test.txt");

    TextQuery tq(ifs);

    Query q = Query("fiery") & Query("bird") | Query("wind");

    print_queryresult(cout, q.eval(tq));

    return 0;
}

string make_plural(size_t ctr, const string& word, const string& ending)
{
    return (ctr > 1) ? word + ending : word;
}

TextQuery::TextQuery(ifstream& ifs) : content(new vector<string>)
{
    LineNo lineno(0);
    string line;
    string word;

    while (getline(ifs, line))
    {
        content->push_back(line);
        lineno = content->size() - 1;
        istringstream iss(line);

        while (iss >> word)
        {
            auto& s_ptr_set_LineNo = result[word];
            if (!s_ptr_set_LineNo)
            {
                s_ptr_set_LineNo.reset(new set<LineNo>);
            }
            s_ptr_set_LineNo->insert(lineno);
        }
    }
}

QueryResult TextQuery::query(const string& str) const
{
    static shared_ptr<set<LineNo>> nofound(new set<LineNo>);
    auto m_iter = result.find(str);

    if (m_iter != result.end())
    {
        return QueryResult(str, m_iter->second, content);
    }
    else
    {
        return QueryResult(str, nofound, content);
    }
}

ostream& print_queryresult(ostream& os, const QueryResult& result)
{
    os << result.word << " occurs " << result.lineno->size() << " "
        << make_plural(result.lineno->size(), "time", "s") << endl;
    for (auto no : *result.lineno)
    {
        os << "\t(line " << no + 1 << ")" << *(result.content->begin() + no) << endl;
    }

    return os;
}

inline Query operator~ (const Query& q)
{
    return shared_ptr<Query_base>(new NotQuery(q));
}

inline Query operator| (const Query& q1, const Query& q2)
{
    return shared_ptr<Query_base>(new OrQuery(q1, q2));
}

inline Query operator& (const Query& q1, const Query& q2)
{
    return shared_ptr<Query_base>(new AndQuery(q1, q2));
}

ostream& operator<< (ostream& os, const Query& q)
{
    return os << q.rep();
}

QueryResult OrQuery::eval(const TextQuery& tq) const
{
    auto q1_eval = q1.eval(tq), q2_eval = q2.eval(tq);
    auto ret_lines = make_shared<set<LineNo>>(q1_eval.begin(), q1_eval.end());
    ret_lines->insert(q2_eval.begin(), q2_eval.end());

    return QueryResult(rep(), ret_lines, q1_eval.get_file());
}

QueryResult AndQuery::eval(const TextQuery& tq) const
{
    auto q1_eval = q1.eval(tq), q2_eval = q2.eval(tq);
    auto ret_lines = make_shared<set<LineNo>>();

    //对两个序列都包含的元素创建一个有序序列。结果序列保存在参数5中（P779）
    set_intersection(q1_eval.begin(), q1_eval.end(), q2_eval.begin(), q2_eval.end(), inserter(*ret_lines, ret_lines->begin()));

    return QueryResult(rep(), ret_lines, q1_eval.get_file());
}

QueryResult NotQuery::eval(const TextQuery& tq) const
{
    auto result = query.eval(tq);
    auto ret_lines = make_shared<set<LineNo>>();
    auto qr_begin = result.begin(), qr_end = result.end();
    auto content_size = result.get_file()->size();

    for (size_t i = 0; i != content_size; i++)
    {
        if (qr_begin == qr_end || *qr_begin != i)
        {
            ret_lines->insert(i);
        }
        else if (qr_begin != qr_end)
        {
            ++qr_begin;
        }
    }

    return QueryResult(rep(), ret_lines, result.get_file());
}