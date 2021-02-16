#include<iostream>
#include "InputString.h"
#include<vector>
#include<string>
using namespace std;

int main(){
    InputString inputStr;
    vector<string> vec;
    while(1){
        string t = inputStr();
        if(t.empty()) break;
        vec.push_back(t);
    }
    for(string& s:vec){
        cout<<s<<endl;
    }
    return 0;
}