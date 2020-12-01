#include<iostream>
using namespace std;

void reset(int &x){
    x=0;
}

int main(){
    int i=1;
    reset(i);
    cout<<i<<endl;
    return 0;
}