#include<iostream>
using namespace std;

struct Sales_data{
    std::string bookNo = "";
    unsigned units_sold = {0};
    double revenue{0.0};

    Sales_data() = default;
    Sales_data(const string &s): bookNo(s) {}
    Sales_data(const string &s, unsigned n, double p): bookNo(s), units_sold(n), revenue(p*n){}
    Sales_data(istream &);

    string isbn() const {return bookNo;}
    Sales_data& combine(const Sales_data&);
};


istream& read(istream &is, Sales_data &sd);
ostream& print(ostream &os, const Sales_data &sd);
Sales_data add(const Sales_data &lhs, const Sales_data &rhs);

Sales_data :: Sales_data(istream &is){
    read(is, *this);
}

Sales_data& Sales_data::combine(const Sales_data &rhs){
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
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
    Sales_data sd1;
    print(cout, sd1)<<endl;;

    Sales_data sd2("sssfdf");
    print(cout, sd2)<<endl;;

    Sales_data sd3("fgfdgd", 1, 2);
    print(cout, sd3)<<endl;

    Sales_data sd4(cin);
    print(cout, sd4)<<endl;
    return 0;
}