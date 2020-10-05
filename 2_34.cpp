#include<iostream>

int main(){
    int i=0, &r=i;
    auto a=r;
    const int ci = i, &cr = ci;
    auto b = ci;
    auto c = cr;
    auto d = &i;
    auto e = &ci;
    const auto f = ci;
    auto &g = ci;
    std::cout<<a<<std::endl;
    std::cout<<b<<std::endl;
    std::cout<<c<<std::endl;
    
    a = 42;
    std::cout<<a<<std::endl;
    b = 42;
    std::cout<<b<<std::endl;
    c = 42;
    std::cout<<c<<std::endl;

    return 0;
}