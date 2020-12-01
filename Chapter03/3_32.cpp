#include<iostream>
#include<vector>
using namespace std;

int main(){
    /*int a[10], b[10];
    for(int i=0; i<10; i++){
        a[i] = i;
    }
    for(int i=0; i<10; i++){
        b[i] = a[i];
    }
    for(auto i : b){
        cout<<i<<' ';
    }*/

    vector<int> a(10),b;
    for(int i=0; i<10; i++){
        a[i]=i;
    }
    b=a;
    for(auto i : b){
        cout<<i<<' ';
    }
    return 0;
}