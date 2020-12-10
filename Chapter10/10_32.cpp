#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<iterator>
#include"Sales_item.h"
using namespace std;



int main(){
    istream_iterator<Sales_item> item_iter(cin), eof;
    vector<Sales_item> sale(item_iter, eof);
    sort(sale.begin(), sale.end(), compareIsbn);
    auto it = sale.begin();
    while(it!=sale.end()){
        auto item = *it;
        auto r = find_if(it, sale.end(), [item](const Sales_item& u){
            return u.isbn()!=item.isbn();
        });
        cout<< accumulate(it+1, r, item)<<endl;
        it = r;
    }

    return 0;
}