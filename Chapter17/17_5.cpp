#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>
#include<numeric>
#include"Sales_data.h"
using namespace std;

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs){
    return lhs.isbn() < rhs.isbn();
}
typedef pair<vector<Sales_data>::size_type, pair<vector<Sales_data>::const_iterator, vector<Sales_data>::const_iterator>> matches;

vector<matches> findBook(const vector<vector<Sales_data>> &files, const string & book){
    vector<matches> ret;
    for(auto it = files.cbegin(); it!=files.cend(); ++it){
        pair<vector<Sales_data>::const_iterator, vector<Sales_data>::const_iterator> found = equal_range(it->cbegin(), it->cend(), book, compareIsbn);
		if(found.first != found.second)
			ret.push_back(make_pair(it - files.cbegin(), make_pair(found.first, found.second)));

    }
    return ret;
}

void reportResults(istream & in, ostream & os, const vector<vector<Sales_data>> &files){
    string s;
    while(in>>s){
        auto trans = findBook(files, s);
        if(trans.empty()){
            cout<<s<<" not found in any stores"<<endl;
            continue;
        }
        for(const auto &store : trans){
            os<<"store "<<get<0>(store)<<" sales: "<<accumulate(store.second.first, store.second.second, Sales_data(s))<<endl;
        }
    }

}

int main()
{
	vector<vector<Sales_data>> file { 
		{Sales_data("1023", 4, 2), Sales_data("123", 4, 5), Sales_data("234", 4, 6), Sales_data("234", 4, 7), Sales_data("235", 4, 6)}, 
		{Sales_data("1023", 4, 2), Sales_data("123", 4, 5), Sales_data("234", 4, 5), Sales_data("235", 4, 5), Sales_data("235", 4, 5)} 
	};
	reportResults(cin, cout, file);
	
	return 0;
} 