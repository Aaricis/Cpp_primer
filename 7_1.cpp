#include<iostream>
#include "Sales_data.h"
using namespace std;

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
            if(total.bookNo==trans.bookNo){
                total.units_sold += trans.units_sold;
                total.revenue += trans.revenue;
            }
            else{
                print(cout, total)<<endl;
                total= trans;
            }
        }
        print(cout, total)<<endl;
    }
    else{
        cerr<<"No data?!"<<endl;
        return -1;
    }
    return 0;
}