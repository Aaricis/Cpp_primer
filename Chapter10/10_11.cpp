#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void elimDups(vector<string>& words){
    for(string& s:words){
        cout<<s<<' ';
    }
    cout<<endl;
    
    sort(words.begin(), words.end());
    for(string& s:words){
        cout<<s<<' ';
    }
    cout<<endl;

    auto end_unique = unique(words.begin(), words.end());
    for(string& s:words){
        cout<<s<<' ';
    }
    cout<<endl;

    words.erase(end_unique, words.end());
    for(string& s:words){
        cout<<s<<' ';
    }
    cout<<endl;
}

bool isShort(const string& s1, const string& s2){
    return s1.size()<s2.size();
}

int main(){
    vector<string> words={"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    elimDups(words);
    stable_sort(words.begin(), words.end(), isShort);
    for(string& s:words){
        cout<<s<<' ';
    }
    cout<<endl;
    return 0;
}
