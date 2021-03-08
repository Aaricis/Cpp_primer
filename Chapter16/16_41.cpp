#include<iostream>
using namespace std;

template <typename T, typename U>
auto sum(T a, U b)->decltype(a+b){
    return a+b;
}

int main(){
    cout<<sum(0.1, 1000)<<endl;
    return 0;
}