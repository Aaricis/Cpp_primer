#include<iostream>
using namespace std;

int fact(int x){
    int res=1;
    while(x){
        res *= x;
        x--;
    }
    return res;
}
int main(){
    int val;
    cin>>val;
    cout<<fact(val)<<endl;
    return 0;
}