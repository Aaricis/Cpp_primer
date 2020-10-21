#include<iostream>
using namespace std;

int fact2(int x){
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
    cout<<fact2(val)<<endl;
    return 0;
}