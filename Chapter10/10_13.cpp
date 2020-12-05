#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

bool compare(const string& s){
    return s.size()<5;
}

int main(){
    vector<string> words = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    auto it = partition(words.begin(), words.end(), compare);
    while(it!=words.end()){
        cout<<*it<<' ';
        it++;
    }
    cout<<endl;
}