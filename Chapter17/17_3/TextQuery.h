#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include<iostream>
#include<fstream>
#include<memory>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<tuple> 
#include<sstream>
using namespace std;

typedef tuple<string, shared_ptr<set<vector<string>::size_type>>, shared_ptr<vector<string>>> QueryResult;

class TextQuery{
public:
	using line_no = vector<string>::size_type;
	TextQuery(ifstream &);
	QueryResult query(const string &) const;
	TextQuery(const TextQuery & tq) = default;
	TextQuery & operator=(const TextQuery & tq) = default;
	~TextQuery() = default;
	
private: 
	shared_ptr<vector<string>> file;
	map<string, shared_ptr<set<line_no>>> wm;
}; 

ostream & print(ostream & os, const QueryResult &qr);


string make_plural(size_t ctr, const string &word, const string &ending){
	return (ctr > 1) ? word + ending : word;
}

TextQuery::TextQuery(ifstream & is) : file(new vector<string>){
	string text;
	while(getline(is, text))
	{
		file->push_back(text);
		int n = file->size()-1;
		istringstream line(text);
		string word;
		while(line >> word)
		{
			shared_ptr<set<line_no>> &lines = wm[word];
			if(!lines)
				lines.reset(new set<line_no>);
			lines->insert(n);
		}
	}
}

QueryResult TextQuery::query(const string & sought) const{
	static shared_ptr<set<line_no>> nodata(new set<line_no>);
	map<string, shared_ptr<set<line_no>>>::const_iterator loc = wm.find(sought);
	if(loc == wm.cend())
		return QueryResult(sought, nodata, file);
	else
		return QueryResult(sought, loc->second, file);
}


ostream & print(ostream & os, const QueryResult &qr){
	os << get<0>(qr) << " occurs " << get<1>(qr)->size() << " " << make_plural(get<1>(qr)->size(), "time", "s") << endl;
	for(TextQuery::line_no num : *(get<1>(qr)))
		os << "\t(line " << num+1 << ") " << *(get<2>(qr)->begin() + num) << endl;
	return os;
}



#endif