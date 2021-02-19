#ifndef LIMIT_QUOTE_H
#define LIMIT_QUOTE_H

#include<iostream>
//#include"Quote.h"
#include"Disc_quote.h"
using namespace std;

/* class Limit_quote : public Quote{
public:
    Limit_quote()=default;
    Limit_quote(const string& book, double p, size_t num, double disc):
                Quote(book, p), bound(num), discount(disc){}
    double net_price(size_t cnt) const{
        if(cnt <= bound)
            return cnt*(1-discount)*price;
        else
        {
            return bound*(1-discount)*price+(cnt-bound)*price;
        }
        
    }
private:
    size_t bound = 0;
    double discount = 0.0;
};
 */

class Limit_quote : public Disc_quote{
public:
    Limit_quote()=default;
    Limit_quote(const string& book, double price, size_t qty, double disc):
                Disc_quote(book, price, qty, disc){};
    double net_price(size_t cnt) const override{
        if(cnt <= quantity)
            return cnt*(1-discount)*price;
        else
        {
            return quantity*(1-discount)*price+(cnt-quantity)*price;
        }
        
    }

    void  debug() const override;
};
#endif