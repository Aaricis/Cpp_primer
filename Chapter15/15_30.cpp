#include<iostream>
#include"Basket.h"
#include"Bulk_quote.h"
using namespace std;

int main(){
    Basket basket;
    basket.add_item(Bulk_quote("Bible", 20.6, 20, 0.3));
    basket.add_item(Bulk_quote("C++", 30, 10, 0.4));
    basket.add_item(Quote("CLIA", 40));
    basket.total_receipt(cout);
    return 0;
}