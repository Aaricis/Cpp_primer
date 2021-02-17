#include<iostream>
#include<map>
#include<functional>
using namespace std;

int add(int i, int j){
    return i+j;
}

auto mod = [](int i, int j){return i+j;};

struct divide{
    int operator()(int denominator, int divisor){
        return denominator/divisor;
    }
};

int main(){
    map<string, function<int(int, int)>> binops = {
        {"+", add},
        {"-", minus<int>()},
        {"/", divide()},
        {"*", [](int i, int j){return i*j;}},
        {"%", mod}
    };
    string op;
    int lhs, rhs;
    cin>>lhs>>op>>rhs;
    cout<<binops[op](lhs, rhs)<<endl;
    return 0;
}