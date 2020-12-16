#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    vector<string> words;
    string word;
    while(cin>>word){
        if(find(words.begin(), words.end(), word) == words.end()){
            words.push_back(word);
        }
    }

    for(string &str : words){
        cout<<str<<' ';
    }
    cout<<endl;
    return 0;
}