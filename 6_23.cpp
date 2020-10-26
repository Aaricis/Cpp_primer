#include<iostream>
using namespace std;

void print(int i, int (&arr)[2]){
    cout<<i<<endl;
    for(auto x: arr){
        cout<<x;
    }
}
int main(){
    int i=0, j[2] = {0, 1};
    print(i, j);
}