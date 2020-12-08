#include<iostream>
using namespace std;

void add(int a){
    auto sum = [a](int b)->int {return a+b;};
    cout<<sum(1);
}

int main(){
    add(1);
    return 0;
}