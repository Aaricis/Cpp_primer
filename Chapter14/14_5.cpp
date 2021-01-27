#include<iostream>
#include"Book.h"
using namespace std;

int main(){
    Book book1("Tom", "xxx", "poetry", 2.0);
    Book book2("Tom", "xxx", "poetry", 2.0);
    Book book3("Jerry", "xxx", "history", 3.0);


    if (book1 == book2)
        cout<<book1<<endl;
    
    if(book1 != book3)
        cout<<book3<<endl;
    return 0;
}