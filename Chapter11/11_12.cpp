#include<iostream>
#include<vector>
#include<string>
#include<utility>
using namespace std;

int main(){
    vector<pair<string, int>> v;
    string s;
    int i;
    while(cin>>s>>i){
        v.push_back({s, i});
    }
    for(auto p : v){
        cout<<p.first<<' '<<p.second<<endl;
    }
    return 0;
}