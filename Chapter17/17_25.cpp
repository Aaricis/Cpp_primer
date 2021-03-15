#include<iostream>
#include<string>
#include<regex>
using namespace std;

int main(){
    string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
    regex r(phone);
    smatch m;
    string s;
    string fmt = "$2.$5.$7";
    while(getline(cin, s)){
        smatch result;
        regex_search(s, result, r);
        if(!result.empty()){
            cout<<result.prefix()<<result.format(fmt)<<endl;
        }
        else{
            cout<<"No match!"<<endl;
        }
    }
    return 0;
}