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
    vector<int> v = {1,3,4,5};
    int cnt = count_if(v.begin(), v.end(), bind(check_size, "aaa", _1));
    cout<<cnt<<endl;
    return 0;
}