#include<iostream>
#include<string>
using namespace std;

class Book{
    friend istream &operator>>(istream&, Book&);
    friend ostream &operator<<(ostream&, const Book&);
    friend bool operator==(const Book&, const Book&);
    friend bool operator!=(const Book&, const Book&);
    friend bool operator<(const Book&, const Book&);
    friend bool operator>(const Book&, const Book&);
    friend Book operator+(const Book&, const Book&);

public:
    Book()=default;
    Book(const string &_author, const string &_publisher, const string &_type, double _price, unsigned _number): 
                        author(_author), publisher(_publisher), type(_type), price(_price), number(_number){}
    Book(iostream& in){in>>*this;}

    Book& operator+=(const Book&);
private:
    string author = "";
    string publisher = "";
    string type = "";
    double price = 0.0;
    unsigned number = 0;
};

istream &operator>>(istream&, Book&);
ostream &operator<<(ostream&, const Book&);
bool operator==(const Book&, const Book&);
bool operator!=(const Book&, const Book&);
bool operator<(const Book&, const Book&);
bool operator>(const Book&, const Book&);
Book operator+(const Book&, const Book&);

Book& Book::operator+=(const Book& book){
    if(*this == book){
        number += book.number;
    }
    return *this;
}

istream &operator>>(istream& is, Book& book){
    is>>book.author>>book.publisher>>book.type>>book.price>>book.number;
    if(!is)
        book = Book(); //输入失败，对象被赋予默认值
    return is;
}

ostream &operator<<(ostream& os, const Book& book){
    os<<book.author<<' '<<book.publisher<<' '<<book.type<<' '<<book.price<<' '<<book.number;
    return os;
}

bool operator==(const Book& s, const Book& t){
    return s.author==t.author;
}

bool operator!=(const Book& s, const Book& t){
    return !(s==t);
}

bool operator<(const Book& u, const Book& v){
    return u.price<v.price;
}

bool operator>(const Book& u, const Book& v){
    return u<v;
}

Book operator+(const Book& u, const Book& v){
    Book sum = u;
    sum += v;
    return sum;
}

int main(){
    Book b1("xxx", "sss", "ddd", 1, 1);
    Book b2("xxx", "sss", "ddd", 1, 1);
    Book b3("xxx", "sss", "ddd", 1, 2);

    cout<<b1+b3<<endl;
    return 0;
}