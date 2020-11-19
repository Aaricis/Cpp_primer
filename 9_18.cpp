#include<iostream>
#include<deque>
#include<string>
using namespace std;

int main(){
    deque<string> d;
    string word;
    while(cin>>word){
        d.push_back(word);
    }
    deque<string> :: iterator it;
    for(it=d.begin(); it!=d.end(); it++){
        cout<<*it<<endl;
    }
    return 0;
}