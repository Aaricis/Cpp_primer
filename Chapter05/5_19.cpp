#include<iostream>
using namespace std;

int main(){
    do{
        string s, t;
        cin>>s>>t;
        if(s.length()<t.length()) cout<<s<<endl;
        else cout<<t<<endl;
    }while(cin);
    return 0;
}