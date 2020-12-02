#include<iostream>
using namespace std;

class Book{
friend istream &read(istream&, Book &);
friend ostream &print(ostream&, const Book&);
private:
    string author = "";
    string publisher = "";
    string type = "";
    double price = 0.0;

public:
    Book()=default;
    Book(const string &_author, const string &_publisher, const string &_type, double _price): author(_author), publisher(_publisher), type(_type), price(_price){}
    Book(istream &is){
        read(is, *this);
    }
};

istream &read(istream&, Book &);
ostream &print(ostream&, const Book&);

istream &read(istream& is, Book &bk){
    is>>bk.author>>bk.publisher>>bk.type>>bk.price;
    return is;
}

ostream &print(ostream& os, const Book& bk){
    os<<bk.author<<' '<<bk.publisher<<' '<<bk.type<<' '<<bk.price;
    return os;
}

int main(){
    Book b1;
    print(cout, b1)<<endl;

    Book b2("a", "b", "c", 10.0);
    print(cout, b2)<<endl;

    Book b3(cin);
    print(cout, b3)<<endl;
    return 0;
}