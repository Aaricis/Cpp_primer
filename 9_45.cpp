#include<iostream>
#include<string>
using namespace std;

string reName(string& s, const string& prefix, const string& suffix){
    s.insert(s.begin(), prefix.begin(), prefix.end());
    s.append(suffix);
    return s;
}

int main(){
    string s = "SSSS";
    s = reName(s, "Mr.", "Jr.");
    cout<<s<<endl;
    return 0;
}