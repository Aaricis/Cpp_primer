#include<iostream>
using namespace std;

struct Sales_data{
    std::string bookNo = "";
    unsigned units_sold = {0};
    double revenue{0.0};
    string isbn() const {return bookNo;}
    Sales_data& combine(const Sales_data&);
};

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


int main(){
    Sales_data total;
    if(read(cin, total)){
        Sales_data trans;
        while(read(cin, trans)){
            if(total.isbn()==trans.isbn()){
                total.combine(trans);
            }
            else{
                print(cout, total)<<endl;
                total = trans;
            }
        }
        print(cout, total)<<endl;
    }
    else{
        cerr<<"No data?!"<<endl;
    }
    return 0;
}