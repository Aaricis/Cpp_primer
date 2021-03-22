#include<iostream>
#include<stdexcept>
using namespace std;

int main(){
    range_error r("error");
    throw r;

    /* exception *p = &r;
    throw *p; */

    exception *p = &r;
    throw p;
    return 0;
}