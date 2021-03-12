#ifndef QUERY_H
#define QUERY_H

#include<string>
#include<memory>
#include<tuple> 
#include<string>
#include<set>
#include<algorithm>
#include<iterator>
#include<tuple> 
#include "TextQuery.h"

class Query_base
{
	friend class Query;
protected:
	using line_no = TextQuery::line_no;
	virtual ~Query_base() = default;
private:
	virtual QueryResult eval(const TextQuery &) const = 0;
	virtual std::string rep() const = 0; 
};

class Query
{
	friend Query operator~(const Query &);
	friend Query operator|(const Query &, const Query &);
	friend Query operator&(const Query &, const Query &);
public:
	Query(const std::string &);
	QueryResult eval(const TextQuery &t) const { return q->eval(t); }
	std::string rep() const { return q->rep(); }
private:
	Query(std::shared_ptr<Query_base> query) : q(query) { }
	std::shared_ptr<Query_base> q;
};

class WordQuery : public Query_base
{
	friend class Query;
	WordQuery(const std::string &s) : query_word(s) { }
	QueryResult eval(const TextQuery &t) const { return t.query(query_word); }
	std::string rep() const { return query_word; }
	
	std::string query_word;
}; 

class NotQuery : public Query_base
{
	friend Query operator~(const Query &);
	NotQuery(const Query &q) : query(q) { }
	std::string rep() const { return "~(" + query.rep() + ")"; }
	QueryResult eval(const TextQuery &text) const;
	Query query;
};

class BinaryQuery : public Query_base
{
protected:
	BinaryQuery(const Query &l, const Query &r, std::string s) : lhs(l), rhs(r), opSym(s) { }
	std::string rep() const { return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")"; }
	Query lhs, rhs;
	std::string opSym;
}; 

class AndQuery : public BinaryQuery
{
	friend Query operator&(const Query &, const Query &);
	AndQuery(const Query &left, const Query &right) : BinaryQuery(left, right, "&") { }
	QueryResult eval(const TextQuery &text) const;
};

class OrQuery : public BinaryQuery
{
	friend Query operator|(const Query &, const Query &);
	OrQuery(const Query &left, const Query &right) : BinaryQuery(left, right, "|") { }
	QueryResult eval(const TextQuery &text) const;
};

Query operator~(const Query &);
Query operator|(const Query &, const Query &);
Query operator&(const Query &, const Query &);


Query::Query(const std::string &s) : q(new WordQuery(s)) { } 

Query operator~(const Query &operand)
{
	return std::shared_ptr<Query_base>(new NotQuery(operand));
}

Query operator&(const Query &lhs, const Query &rhs)
{
	return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs)); 
}

Query operator|(const Query &lhs, const Query &rhs)
{
	return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

QueryResult OrQuery::eval(const TextQuery &text) const
{
	QueryResult left = lhs.eval(text), right = rhs.eval(text);
	std::shared_ptr<std::set<line_no>> ret_lines = std::make_shared<std::set<line_no>>(std::get<1>(left)->begin(), std::get<1>(left)->end());
	ret_lines->insert(std::get<1>(right)->begin(), std::get<1>(right)->end());
	return QueryResult(rep(), ret_lines, std::get<2>(left));
}

QueryResult AndQuery::eval(const TextQuery &text) const
{
	QueryResult left = lhs.eval(text), right = rhs.eval(text);
	std::shared_ptr<std::set<line_no>> ret_lines = std::make_shared<std::set<line_no>>();
	std::set_intersection(std::get<1>(left)->begin(), std::get<1>(left)->end(), std::get<1>(right)->begin(), std::get<1>(right)->end(), std::inserter(*ret_lines, ret_lines->begin()));
	return QueryResult(rep(), ret_lines, std::get<2>(left));	
}

QueryResult NotQuery::eval(const TextQuery &text) const
{
	QueryResult result = query.eval(text);
	std::shared_ptr<std::set<line_no>> ret_lines = std::make_shared<std::set<line_no>>();
	
	std::set<line_no>::iterator beg = std::get<1>(result)->begin(), end = std::get<1>(result)->end();
	line_no sz = std::get<2>(result)->size();
	for(line_no n = 0; n != sz; ++n)
	{
		if(beg == end || *beg != n)
			ret_lines->insert(n);
		else if(beg != end)
			++beg;
	}
	return QueryResult(rep(), ret_lines, std::get<2>(result));	
}

#endif

