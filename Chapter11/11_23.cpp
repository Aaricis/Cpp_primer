#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;

void add_child(multimap<string, string>& familes, const string& lastname, const string& firstname){
    familes.insert({lastname, firstname});
}
int main(){
    multimap<string, string> families;

    add_child(families, "Zhang", "a");
    add_child(families, "Zhang", "b");
    add_child(families, "Zhang", "c");

    for(auto f:families){
        cout<<f.first<<": ";
        for(auto str : f.second){
            cout<<str<<' ';
        }
        cout<<endl;
    }
    return 0;
}