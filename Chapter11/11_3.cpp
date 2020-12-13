#include<iostream>
#include<map>
#include<string>
using namespace std;

int main(){
    map<string, size_t> wordCount;
    string word;
    while(cin>>word){
        ++wordCount[word];
    }

    for(const auto &w : wordCount){
        cout<<w.first<<" occurs "<<w.second<<((w.second>1)? " times":" time")<<endl;
    }
    return 0;
}