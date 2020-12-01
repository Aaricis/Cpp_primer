#include<iostream>
using namespace std;


int compare(int a, const int *p){
    return a>*p? a:*p;
}
int main(){
    const int val = 4;
    cout<<compare(2, &val)<<endl;
    return 0;
}