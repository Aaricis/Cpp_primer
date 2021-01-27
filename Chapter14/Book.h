#ifndef BOOK_H
#define BOOK_H

#include<iostream>
#include<string>
using namespace std;

class Book{
    friend istream &operator>>(istream&, Book&);
    friend ostream &operator<<(ostream&, const Book&);
    friend bool operator==(const Book&, const Book&);
    friend bool operator!=(const Book&, const Book&);
public:
    Book()=default;
    Book(const string &_author, const string &_publisher, const string &_type, double _price): 
                        author(_author), publisher(_publisher), type(_type), price(_price){}
    Book(iostream& in){in>>*this;}
private:
    string author = "";
    string publisher = "";
    string type = "";
    double price = 0.0;
};

istream &operator>>(istream&, Book&);
ostream &operator<<(ostream&, const Book&);
bool operator==(const Book&, const Book&);
bool operator!=(const Book&, const Book&);

istream &operator>>(istream& is, Book& book){
    is>>book.author>>book.publisher>>book.type>>book.price;
    return is;
}

ostream &operator<<(ostream& os, const Book& book){
    os<<book.author<<' '<<book.publisher<<' '<<book.type<<' '<<book.price;
    return os;
}

bool operator==(const Book& s, const Book& t){
    return s.author==t.author;
}

bool operator!=(const Book& s, const Book& t){
    return !(s==t);
}
#endif