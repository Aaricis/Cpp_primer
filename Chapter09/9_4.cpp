#include<iostream>
#include<vector>
using namespace std;

bool find(vector<int>:: iterator b, vector<int>:: iterator e, int x){
        while(b!=e){
            if(*b == x) return true;
            b++;
        }
        return false;
}

int main(){
    vector<int> v = {1,2,3};
    cout<<find(v.begin(), v.end(), 5)<<endl;
    return 0;
}