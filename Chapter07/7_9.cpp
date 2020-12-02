#include<iostream>
using namespace std;

struct Person{
    string name;
    string address;
    string get_name() const{return name;}
    string get_address() const{return address;}
};

istream &read(istream &is, Person &item){
    is>>item.name>>item.address;
    return is;
}

ostream &print(ostream &os, const Person &item){
    os<<item.name<<item.address;
    return os;
}

int main(){
    Person p;
    if(read(cin, p)){
        print(cout, p)<<endl;
    }
    return 0;
}