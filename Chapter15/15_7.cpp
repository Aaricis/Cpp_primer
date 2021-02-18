#include<iostream>
#include"Quote.h"
#include"Bulk_quote.h"
#include"Limit_quote.h"
using namespace std;

double print_total(ostream &os, const Quote &item, size_t n){
    double ret = item.net_price(n);
    os<<"ISBN: "<<item.isbn()<<" # sold: "<<n<<" total due: "<<ret<<endl;
    return ret;
}

int main(){
    Quote q("textbook", 10.60);
    Bulk_quote bq("textbook", 10.60, 10, 0.3);
    Limit_quote lq("Bible", 10.60, 10 , 0.3);

    print_total(cout, q, 5);
    print_total(cout, bq, 5);
    print_total(cout , lq, 5);
    return 0;
}