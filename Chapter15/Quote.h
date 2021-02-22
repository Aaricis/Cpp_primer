#ifndef QUOTE_H
#define QUOTE_H

#include<iostream>
#include<string>
using namespace std;

class Quote{
    friend bool operator!=(const Quote& lhs, const Quote& rhs);
public:
    Quote(){
        cout<<"Quote: default constructor"<<endl;
    }

    Quote(const string &book, double sales_price):bookNo(book), price(sales_price){
        cout<<"Quote: 2 parameters constructor"<<endl;
    }

    Quote(const Quote& p): bookNo(p.bookNo), price(p.price){
        cout<<"Quote: copy constructor"<<endl;
    }

    Quote(Quote&& p):bookNo(std::move(p.bookNo)), price(std::move(p.price)){
        cout<<"Quote: move constructor"<<endl;
    }

    Quote& operator=(const Quote& rhs){
        if(*this != rhs){
            bookNo = rhs.bookNo;
            price = rhs.price;
        }
        cout<<"Quote: copy-assignment operator"<<endl;
        return *this;
    }

    Quote& operator=(const Quote&& rhs) noexcept{
        if(*this != rhs){
            bookNo = std::move(rhs.bookNo);
            price = std::move(rhs.price);
        }
        cout<<"Quote: move-assignment operator"<<endl;
        return *this;
    }
    string isbn() const {return bookNo;}
    virtual double net_price(size_t n) const{
        return n*price;
    }
    virtual void debug() const{
        cout << "data members of this class:\n"
            << "bookNo= " <<this->bookNo << " "
            << "price= " <<this->price<< " ";
    }
    virtual ~Quote(){
        cout<<"Quote: destructor"<<endl;
    }

    virtual Quote* clone() const &{
        return new Quote(*this);
    }

    virtual Quote* clone() const &&{
        return new Quote(std::move(*this));
    }
private:
    string bookNo;
protected:
    double price = 0.0;

};

bool inline
operator !=(const Quote& lhs, const Quote& rhs)
{
    return lhs.bookNo != rhs.bookNo
           &&
           lhs.price  != rhs.price;
}



#endif