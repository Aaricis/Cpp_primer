#include<iostream>
using namespace std;

void swap(int *p, int *q){
    int temp = *p;
    *p = *q;
    *q = temp;
}

int main(){
    int a=1, b=2;
    int *p, *q;
    p = &a;
    q = &b;
    cout<<*p<<' '<<*q<<endl;
    swap(p, q);
    cout<<*p<<' '<<*q<<endl;
}