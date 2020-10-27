#include<iostream>
using namespace std;

int add(initializer_list<int> il){
    int sum = 0;
    for(auto beg=il.begin(); beg!=il.end(); beg++){
        sum += *beg;
    }
    return sum;
}

int main(){
    int val = add({1,2,3,4});
    cout<<val<<endl;
    return 0;
}