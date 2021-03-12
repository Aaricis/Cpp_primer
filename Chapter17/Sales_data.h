#ifndef SALES_DATA_H
#define SALES_DATA_H

#include<iostream>
#include<string>
using namespace std;

class Sales_data;
istream& read(istream &is, Sales_data &sd);
Sales_data operator+(const Sales_data & sa, const Sales_data & sb);

class Sales_data{
friend class std::hash<Sales_data>;
friend Sales_data add(const Sales_data &lhs, const Sales_data &rhs);
friend istream &read(istream &is, Sales_data &sd);
friend ostream &print(ostream &os, const Sales_data &sd);
friend istream & operator>>(std::istream & is, Sales_data & sa); 
friend ostream & operator<<(std::ostream & os, const Sales_data & sa);
friend bool operator==(const Sales_data &lhs, const Sales_data &rhs);
friend Sales_data operator+(const Sales_data & sa, const Sales_data & sb);


private:
    string bookNo = "";
    unsigned units_sold = {0};
    double revenue{0.0};

public:
    //Sales_data() = default;
    Sales_data():units_sold(0), revenue(0.0){}
    Sales_data(const string &s): bookNo(s) {}
    Sales_data(const string &s, unsigned n, double p): bookNo(s), units_sold(n), revenue(p*n){}
    Sales_data(istream &is){
        read(is, *this);
    }

    string isbn() const {return bookNo;}
    Sales_data& combine(const Sales_data&);
    double avg_price() const;

    Sales_data & operator+=(const Sales_data & sa);
};
namespace std
{
    template<>
struct hash<Sales_data>{
    typedef size_t result_type;
    typedef Sales_data argument_type;
    size_t operator() (const Sales_data& s) const;
};

size_t hash<Sales_data>::operator()(const Sales_data& s) const{
    return hash<string>()(s.bookNo)^
            hash<unsigned>()(s.units_sold)^
            hash<double>()(s.revenue);

}    
} // namespace std



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

istream & operator>>(istream & is, Sales_data & sa)
{
	double price = 0;
	is >> sa.bookNo >> sa.revenue >> price;
	if(is)
		sa.revenue = price * sa.units_sold;
	else
		sa = Sales_data();
	return is;
}

ostream & operator<<(ostream & os, const Sales_data & sa)
{
	os << sa.isbn() << " " << sa.units_sold << " " << sa.revenue << " " << sa.avg_price();
	return os;
}

bool operator==(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.isbn() == rhs.isbn() && lhs.revenue == rhs.revenue && lhs.units_sold == rhs.units_sold;
}

Sales_data & Sales_data::operator+=(const Sales_data & sa){
	revenue += sa.revenue;
	units_sold += sa.units_sold;
	return *this;
}

Sales_data operator+(const Sales_data & sa, const Sales_data & sb){
	Sales_data sum = sa;
	sum += sb;
	return sum;
}


#endif
