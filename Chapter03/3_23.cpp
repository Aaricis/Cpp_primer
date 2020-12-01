#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> v{0,1,2,3,4,5,6,7,8,9};
    for(auto i=v.begin(); i!=v.end(); i++){
        *i *= 2;
        cout<<*i<<endl;
    }
    return 0;
}