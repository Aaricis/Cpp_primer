#include<iostream>
#include<set>
#include"Sales_data.h"
using namespace std;

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs){
    return lhs.isbn()<rhs.isbn();
}


int main(){
    //typedef bool (*pf) (const Sales_data &, const Sales_data &);
    using pf = bool (*) (const Sales_data &, const Sales_data &);
    multiset<Sales_data, pf> bookstore(compareIsbn);
    return 0;
}