#include<iostream>
using namespace std;

bool hasUpper(const string &s){
    for(auto c : s){
        if(isupper(c)) return true;
    }
    return false;
}

string lower(string &s){
    for(auto &c:s){
        if(isupper(c)) c = tolower(c);
    }
    return s;
}

int main(){
    string s = "Hello";
    cout<<hasUpper(s)<<endl;
    cout<<lower(s)<<endl;
    return 0;
}