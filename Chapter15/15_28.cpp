#include<iostream>
#include<vector>
#include "Quote.h"
#include "Bulk_quote.h"
using namespace std;

int main(){
    vector<Quote> v;
    v.push_back(Bulk_quote("aaaa", 1, 10, 0.1));
    v.push_back(Bulk_quote("bbbb", 1, 10, 0.1));
    double total;
    for(int i=0; i<v.size(); ++i){
        total += v[i].net_price(20);
    }    
    cout<<total<<endl;
    return 0;
}