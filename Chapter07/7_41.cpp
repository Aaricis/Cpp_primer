#include<iostream>
#include<string>
using namespace std;

class Sales_data;
istream& read(istream &is, Sales_data &sd);
class Sales_data{
friend Sales_data add(const Sales_data &lhs, const Sales_data &rhs);
friend istream &read(istream &is, Sales_data &sd);
friend ostream &print(ostream &os, const Sales_data &sd);

private:
    string bookNo = "";
    unsigned units_sold = {0};
    double revenue{0.0};

public:
    
    Sales_data(const string &s, unsigned n, double p): bookNo(s), units_sold(n), revenue(p*n){
        cout<<"not delegating constructor"<<endl;
    }
   
    Sales_data():Sales_data("", 0 ,0){
        cout<<"delegating constructor 1"<<endl;
    };
    Sales_data(string s):Sales_data(s, 0, 0){
        cout<<"delegating constructor 2"<<endl;
    };
    Sales_data(istream &is):Sales_data(){
        cout<<"delegating constructor 3"<<endl;
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


inline double Sales_data::avg_price() const{
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
    Sales_data s1;
    Sales_data s2("a");
    Sales_data s3(cin);
    return 0;
}