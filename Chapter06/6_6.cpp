#include<iostream>
using namespace std;

int fun(int n){
    static int x=1;
    x += n;
    return x;
}
int main(){
    int n=1;
    cout<<fun(n)<<endl;
    cout<<fun(n)<<endl;
    cout<<fun(n)<<endl;
    return 0;
}