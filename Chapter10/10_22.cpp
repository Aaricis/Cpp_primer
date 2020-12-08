#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<functional>
using namespace std;
using namespace std::placeholders;

bool check_size(const string &s, int sz){
    return s.length()<sz;
}

int main(){
    vector<string> words = {"hello", "programmer", "project", "mom", "daddy"};
    int cnt = count_if(words.begin(), words.end(), bind(check_size, _1, 6));
    cout<<cnt<<endl;
    return 0;
}