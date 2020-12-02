#include<iostream>
#include<algorithm>
#include<list>
#include<string>
using namespace std;

int main(){
    list<string> l;
    string s;
    while(cin>>s){
        l.push_back(s);
    }
    cout<<count(l.begin(), l.end(), "a")<<endl;
    return 0;
}