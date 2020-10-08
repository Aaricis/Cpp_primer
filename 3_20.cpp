#include<iostream>
#include<vector>
using namespace std;

int main(){
    int x;
    vector<int> v;
    while(cin>>x){
        v.push_back(x);
    }
    /*for(decltype(v.size()) i=0; i<v.size()-1; i++){
        cout<<v[i]+v[i+1]<<endl;
    }*/
    for(decltype(v.size()) i=0; i<v.size()/2; i++){
        cout<<v[i]+v[v.size()-1-i]<<endl;
    }
    return 0;
}