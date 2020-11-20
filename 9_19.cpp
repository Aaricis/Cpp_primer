#include<iostream>
#include<list>
#include<string>
using namespace std;

int main(){
    list<string> l;
    string word;
    while(cin>>word){
        l.push_back(word);
    }
    list<string> :: iterator it;
    for(it=l.begin(); it!=l.end(); it++){
        cout<<*it<<endl;
    }
    return 0;
}