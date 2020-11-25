#include<iostream>
#include<string>
using namespace std;

string reName(string& s, const string& prefix, const string& suffix){
    s.insert(0, prefix);
    s.insert(s.length(), suffix);
    return s;
}

int main(){
    string s = "SSSS";
    s = reName(s, "Mr.", "Jr.");
    cout<<s<<endl;
    return 0;
}