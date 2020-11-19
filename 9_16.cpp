#include<iostream>
#include<vector>
#include<list>
using namespace std;

int main(){
    vector<int> v={1,2,3};
    list<int> l={6,7,12};
    vector<int> temp(l.begin(), l.end());
    cout<<(v==temp)<<endl;
    return 0;
}