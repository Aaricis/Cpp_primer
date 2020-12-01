#include<iostream>
using namespace std;

int main(){
    int x, y;
    cin>>x>>y;
    if(y==0){
        throw runtime_error("second number can not equal 0");
    }
    cout<<x/y<<endl;
    return 0;
}