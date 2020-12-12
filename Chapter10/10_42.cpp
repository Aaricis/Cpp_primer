#include<iostream>
#include<list>
#include<algorithm>
using namespace std;

void elimDups(list<string>& words){
    for(string& s:words){
        cout<<s<<' ';
    }
    cout<<endl;
    
    words.sort();
    for(string& s:words){
        cout<<s<<' ';
    }
    cout<<endl;

    words.unique();
    for(string& s:words){
        cout<<s<<' ';
    }
    cout<<endl;

}

int main(){
    list<string> l = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    elimDups(l);
    return 0;
}