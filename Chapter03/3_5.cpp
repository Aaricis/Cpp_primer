#include<iostream>
using namespace std;

int main(){
    string s, t;
    while(cin>>t){
        s += (t + ' ');
    }
    cout<<s<<endl;
    return 0;
}