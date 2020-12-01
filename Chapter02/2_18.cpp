#include<iostream>

int main(){
    int val = 42;
    int *p = &val;
    val += 1;
    std::cout<<*p<<std::endl;
    p = nullptr;
    std::cout<<*p<<std::endl;
    return 0;
}