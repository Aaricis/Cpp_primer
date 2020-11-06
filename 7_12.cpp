#include<iostream>
using namespace std;

struct Sales_data;
istream& read(istream &is, Sales_data &sd);
struct Sales_data{
    std::string bookNo = "";
    unsigned units_sold = {0};
    double revenue{0.0};

    Sales_data() = default;
    Sales_data(const string &s): bookNo(s) {}
    Sales_data(const string &s, unsigned n, double p): bookNo(s), units_sold(n), revenue(p*n){}
    Sales_data(istream &is){
        read(is, *this);
    }

    string isbn() const {return bookNo;}
    Sales_data& combine(const Sales_data&);
    double avg_price() const;
};



ostream& print(ostream &os, const Sales_data &sd);
Sales_data add(const Sales_data &lhs, const Sales_data &rhs);



Sales_data& Sales_data::combine(const Sales_data &rhs){
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

double Sales_data::avg_price() const{
    if(units_sold) 
        return revenue/units_sold;
    else 
        return 0;
}

istream& read(istream &is, Sales_data &sd){
    double price = 0.0;
    is>>sd.bookNo>>sd.units_sold>>price;
    sd.revenue = sd.units_sold*price;
    return is;
}

ostream& print(ostream &os, const Sales_data &sd){
    os<<sd.bookNo<<' '<<sd.units_sold<<' '<<sd.revenue;
    return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs){
    Sales_data sum;
    sum = lhs;
    sum.combine(rhs);
    return sum;
}

int main(){
    Sales_data sd(cin);
    print(cout, sd)<<endl;
    return 0;
}