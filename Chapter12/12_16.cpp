#include<iostream>
#include<memory>
#include<string>
#include<new>
using namespace std;

int main(){
    unique_ptr<string> p1(new string("Sgdfds"));
    unique_ptr<string> p2(p1);
    unique_ptr<string> p3;
    p3 = p2;
    return 0;
}