#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> v;
    cout<<v.at(0)<<endl;
    cout<<v[0]<<endl;
    cout<<v.front()<<endl;
    cout<<*v.begin()<<endl;
    return 0;
}