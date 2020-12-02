#include<iostream>
#include<list>
#include<string>
#include<deque>
using namespace std;

int main(){
    list<int> l = {1,2,3,4};
    deque<int> d1, d2;
    for(int i:l){
        if(i%2==1) d1.push_back(i);
        else d2.push_back(i);
    }

    for(int i:d1){
        cout<<i;
    }

    for(int i:d2){
        cout<<i;
    }
    return 0;
}