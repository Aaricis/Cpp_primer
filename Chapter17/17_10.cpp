#include<iostream>
#include<vector>
#include<bitset>
using namespace std;

int main(){
    vector<int> v{1,2,3,5,8,13,21};
    bitset<32> b;
    for(int i : v){
        b.set(i, 1);
    }
    cout<<b<<endl;

    bitset<32> bit;
    for(int i=0; i!=32; ++i){
        bit[i] = ~b[i];
    }
    cout<<bit<<endl;
    return 0;
}