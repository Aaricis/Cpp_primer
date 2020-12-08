#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int main(){
    vector<string> words = {"hello", "programmer", "project", "mom", "daddy"};
    int cnt = count_if(words.begin(), words.end(), [](const string &s){
        return s.length()>6;
    });
    cout<<cnt<<endl;
    return 0;
}