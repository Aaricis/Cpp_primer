#include<iostream>
#include<map>
#include<string>
using namespace std;

int main(){
    multimap<string, string> mumap = { 
            {"ben","think in C++"},
            { "rock", "C++ Primer" }, 
            { "rock", "the C program" }, 
            { "li", "hackers" }, 
            { "li", "C++ primer plus" } 
    };
    for(auto it=mumap.begin(); it!=mumap.end(); it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
    return 0;
}