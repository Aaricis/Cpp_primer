#include<iostream>
#include"Quote.h"
#include"Bulk_quote.h"
using namespace std;

int main(){
    Quote base("C++ primer", 128.0);
    Bulk_quote bulk("Python", 89, 5, 0.2);
    return 0;
}