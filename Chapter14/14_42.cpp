#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
using namespace std::placeholders;

int main(){
    vector<int> ivec { 1, 111, 1111, 11111};
    int count = count_if(ivec.begin(), ivec.end(), bind(greater<int>(), _1, 1024));
    cout<<count<<endl;

    vector<std::string> svec { "pooh", "pooh", "pezy", "pooh"};
    auto found = find_if(svec.begin(), svec.end(), bind(not_equal_to<string>(), _1, "pooh"));
    cout<<*found<<endl;

    transform(ivec.begin(), ivec.end(), ivec.begin(), bind(multiplies<int>(), _1, 2));
    for(int &x:ivec){
        cout<<x<<' ';
    }
    return 0;
}