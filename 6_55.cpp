#include<iostream>
#include<vector>
using namespace std;

using pf = int(*) (int, int);
int add(int a, int b){
    return a+b;
}

int subtract(int a, int b){
    return a-b;
}

int multiply(int a, int b){
    return a*b;
}

int divide(int a, int b){
    return a/b;
}

int main(){
    vector<pf> arr;
    arr.push_back(add);
    arr.push_back(subtract);
    arr.push_back(multiply);
    arr.push_back(divide);
    int a=4, b=2;
    for(auto f:arr){
        cout<<f(a,b)<<endl;
    }
    return 0;
}