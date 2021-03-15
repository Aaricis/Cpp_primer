#include<iostream>
#include<string>
#include<regex>
using namespace std;

int main(){
    string phone = "(\\d{5})([-])?(\\d{4})?";
    regex r(phone);
    smatch m;
    string s;
    string fmt = "$1-$3";
    while(getline(cin, s)){
        cout<<regex_replace(s, r, fmt)<<endl;
    }
    return 0;
} 

