#include<iostream>
#include<regex>
#include<string>
using namespace std;

int main(){
    string pattern("[^c]ei");
    pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
    regex r(pattern);
    smatch result;
    string s;
    while(getline(cin, s)){
        for(sregex_iterator it(s.begin(), s.end(), r), end_it; it != end_it; ++it){
            if(it->str()=="albeit" || it->str()=="neighbor") continue;
            auto pos = it->prefix().length();
            pos = pos > 40? pos-40 : 0;
            cout<<it->prefix().str().substr(pos)
                <<"\n\t\t>>>"<<it->str()<<"<<<\n"
                <<it->suffix().str().substr(0, 40)
                <<endl;
        }
    }
    return 0;
}