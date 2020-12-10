#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> v = {1,2,3,4,5};
    for(auto r=v.crbegin(); r!=v.crend(); r++){
        cout<<*r<<' ';
    }
    cout<<endl;

    return 0;
}