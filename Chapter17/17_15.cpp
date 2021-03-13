#include<iostream>
#include<regex>
#include<string>
using namespace std;

int main(){
    regex r("[[:alpha:]]*[^c]ei[[:alpha:]]*", regex::icase);
    smatch results;
    string s;
    while(cin>>s){
        if(regex_search(s, results, r)){
            cout<<results.str()<<endl;
        }
        else{
            cout<<"not found!"<<endl;
        }
    }
    return 0;
}