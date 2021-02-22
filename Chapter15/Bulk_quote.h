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
    Bulk_quote(){
        cout<<"Bulk_quote: default constructor"<<endl;
    }
    /* Bulk_quote(const string& book, double price, size_t qty, double disc):
        Disc_quote(book, price, qty, disc){
            cout<<"Bulk_quote: 4 parameters constructor"<<endl;
        } */
    using Disc_quote::Disc_quote;
    
    Bulk_quote(const Bulk_quote& bq):Disc_quote(bq){
        cout<<"Bulk_quote: copy constructor"<<endl;
    }

    Bulk_quote(Bulk_quote&& bq):Disc_quote(std::move(bq)){
        cout<<"Bulk_quote: move constructor"<<endl;
    }

    Bulk_quote& operator=(const Bulk_quote& rhs){
        Disc_quote::operator=(rhs);
        cout<<"Bulk_quote: copy-assignment operator"<<endl;
        return *this;
    }

    Bulk_quote& operator=(Bulk_quote&& rhs) noexcept{
        Disc_quote::operator=(std::move(rhs));
        cout<<"Bulk_quate: move-assignment operator"<<endl;
        return *this;
    }
    double net_price(size_t cnt) const override{
        if(cnt > quantity){
            return cnt*(1-discount)*price;
        }
        else{
            return cnt*price;
        }
    }
    void  debug() const override{
        cout<<"Bulk_quate"<<endl;
    }

    ~Bulk_quote() override{
        cout<<"Bulk_quate: deconstructor"<<endl;
    }
    
};
#endif