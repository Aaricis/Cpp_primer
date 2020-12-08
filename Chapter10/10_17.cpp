#include<iostream>
#include<algorithm>
#include<vector>
#include"Sales_data.h"
using namespace std;


int main(){
    vector<Sales_data> sale;
    Sales_data t;
    while(read(cin, t)){
        sale.push_back(t);
    }

    sort(sale.begin(), sale.end(), [](const Sales_data& u, const Sales_data& v){
        return u.isbn()<v.isbn();
    });

    for(auto &s : sale){
        print(cout, s)<<endl;
    }
    return 0;
}