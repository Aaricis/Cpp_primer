#include<iostream>
using namespace std;

void swap(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}
int main(){
    int a=1, b=2;
    swap(a,b);
    cout<<a<<' '<<b<<endl;
    return 0;
}