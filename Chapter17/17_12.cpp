#include<iostream>
#include<bitset>
using namespace std;

void fun(int index, bool value, bitset<10>& bit){
    bit.set(index, value);
}

int main(){
    bitset<10> bit;
    fun(0, true, bit);
    fun(1, true, bit);
    cout<<bit<<endl;
    return 0;
}