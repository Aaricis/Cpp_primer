#include<iostream>
using namespace std;

struct Person{
friend istream &read(istream &is, Person &item);
friend ostream &print(ostream &os, const Person &item);

private:
    string name;
    string address;
    string get_name() const{return name;}
    string get_address() const{return address;}

public:
    Person() = default;
    Person(const string &_name, const string &_addr):name(_name), address(_addr){}
    Person(istream& is);
};

istream &read(istream &is, Person &item);
ostream &print(ostream &os, const Person &item);

Person::Person(istream& is){
    read(is, *this);
}

istream &read(istream &is, Person &item){
    is>>item.name>>item.address;
    return is;
}

ostream &print(ostream &os, const Person &item){
    os<<item.name<<" "<<item.address;
    return os;
}

int main(){
    Person p1("Bob", "123");
    print(cout, p1)<<endl;

    Person p2(cin);
    print(cout, p2)<<endl;
    return 0;
}