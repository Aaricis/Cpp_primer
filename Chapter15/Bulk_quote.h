#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H

#include<iostream>
//#include"Quote.h"
#include"Disc_quote.h"
using namespace std;

/* class Bulk_quote : public Quote{
public:
    Bulk_quote()=default;
    Bulk_quote(const string& book, double p, size_t qty, double disc):
                Quote(book, p), min_qty(qty), discount(disc){}
    double net_price(size_t cnt) const{
        if(cnt >= min_qty)
            return cnt*(1-discount)*price;
        else
        {
            return cnt*price;
        }
        
    }
private:
    size_t min_qty = 0;
    double discount = 0.0;
}; */

class Bulk_quote : public Disc_quote{
public:
    Bulk_quote() = default;
    Bulk_quote(const string& book, double price, size_t qty, double disc):
        Disc_quote(book, price, qty, disc){}
    double net_price(size_t) const override;
    void  debug() const override;
    
};
#endif