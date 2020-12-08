#include<iostream>
using namespace std;

int main(){
    auto sum = [](int x, int y)-> int {return x+y; };
    cout<<sum(1,2)<<endl;
    return 0;
}