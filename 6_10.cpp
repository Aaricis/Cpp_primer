#include<iostream>
using namespace std;

void swap(int *p, int *q){
    int temp = *p;
    *p = *q;
    *q = temp;
}

int main(){
    int a=1, b=2;
    int *p=&a, *q=&b;
    swap(p, q);
    cout<<a<<' '<<b<<endl;
    return 0;
}