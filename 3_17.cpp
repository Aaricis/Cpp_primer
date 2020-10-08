#include<iostream>
#include<vector>
using namespace std;

int main(){
    string word;
    vector<string> v;
    while(cin>>word){
        v.push_back(word);
    }
    for(auto &w : v){
        for(auto &c : w){
            c = toupper(c);
        }
    }

    for(auto w : v){
        cout<<w<<endl;
    }
    return 0;
}