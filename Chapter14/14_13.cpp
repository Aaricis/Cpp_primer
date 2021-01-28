#include<iostream>
#include<string>
using namespace std;

class Sales_data{
    friend istream& operator>>(istream&, Sales_data&);
    friend ostream& operator<<(ostream&, Sales_data&);
    friend Sales_data operator+(const Sales_data&, const Sales_data&);
    friend Sales_data operator-(const Sales_data&, const Sales_data&);
public:
    Sales_data():Sales_data("", 0, 0.0f){}
    Sales_data(const string &s, unsigned n, double p):bookNo(s), units_sold(n), revenue(n*p){}
    Sales_data(const string &s):Sales_data(s, 0, 0.0f){}
    Sales_data(istream &is);

    Sales_data& operator+=(const Sales_data&);
    Sales_data& operator-=(const Sales_data&);
    string isbn() const {return bookNo;}
private:
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
    inline double avg_price() const; 
};

inline double Sales_data:: avg_price() const{
    return units_sold? revenue/units_sold : 0;
}

istream& operator>>(istream&, Sales_data&);
ostream& operator<<(ostream&, Sales_data&);
Sales_data operator+(const Sales_data&, const Sales_data&);
Sales_data operator-(const Sales_data&, const Sales_data&);

Sales_data::Sales_data(istream &is):Sales_data(){
    is>>*this;
}

Sales_data& Sales_data::operator+=(const Sales_data& item){
    units_sold += item.units_sold;
    revenue += item.revenue;
    return *this;
}

Sales_data& Sales_data::operator-=(const Sales_data& item){
    units_sold -= item.units_sold;
    revenue -= item.revenue;
    return *this;
}

istream& operator>>(istream& is, Sales_data& item){
    double price;
    is>>item.bookNo>>item.units_sold>>price;
    if(is){
        item.revenue = item.units_sold*price;
    }
    else{
        item = Sales_data();
    }
    return is;
} 


ostream& operator<<(ostream& os, Sales_data& item){
    os<<item.isbn()<<' '<<item.units_sold<<' '<<item.revenue<<' '<<item.avg_price();
    return os;
}

Sales_data operator+(const Sales_data &u, const Sales_data &v){
    Sales_data sum = u;
    sum += v;
    return sum;
}

Sales_data operator-(const Sales_data &u, const Sales_data &v){
    Sales_data difference = u;
    difference -= v;
    return difference;
}

int main(){
    Sales_data s1("book1", 150, 10);
    Sales_data s2("book1", 200, 20);
    cout<<s1<<endl;
    cout<<s2<<endl;

    Sales_data s3 = s1+s2;
    cout<<s3<<endl;

    Sales_data s4 = s2-s1;
    cout<<s4<<endl;
    return 0;
}