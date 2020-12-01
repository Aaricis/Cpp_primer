#include<iostream>
using namespace std;

int fact1(int x){
    int res=1;
    while(x){
        res *= x;
        x--;
    }
    return res;
}
int main(){
    cout<<fact1(5)<<endl;
    return 0;
}