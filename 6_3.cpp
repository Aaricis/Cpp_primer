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
    cout<<fact(5)<<endl;
    return 0;
}