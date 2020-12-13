#include<iostream>
#include<map>
#include<string>
using namespace std;

int main(){
    map<string, size_t> wordCount;
    string word;
    while(cin>>word){
       string str;
       for(char& c : word){
           if(!ispunct(c)){
               str += tolower(c);
           }
       }
       ++wordCount[str];
    }

    for(const auto &w : wordCount){
        cout<<w.first<<" occurs "<<w.second<<((w.second>1)? " times":" time")<<endl;
    }
    return 0;
}