#include<iostream>
#include<vector>
using namespace std;

vector<int>::iterator find(vector<int>:: iterator b, vector<int>:: iterator e, int x){
        while(b!=e){
            if(*b == x) return b;
            b++;
        }
        return e;
}

int main(){
    vector<int> v = {1,2,3};
    cout<<find(v.begin(), v.end(), 5)-v.begin()<<endl;
    return 0;
}