#include<iostream>
using namespace std;

int main(){
    string s("aaaaaa");
    /*for(decltype(s.size()) i=0; i!=s.size(); i++){
        s[i] = 'X';
    }*/
    decltype(s.size()) i=0;
    while(i!=s.size()){
        s[i++]='X';
    }


    cout<<s<<endl;
    return 0;
}