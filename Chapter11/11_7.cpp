#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;

void add_family(map<string, vector<string>>& families, const string& lastname){
    if(families.find(lastname)==families.end()){
        families[lastname] = vector<string>();
    }
}

void add_child(map<string, vector<string>>& familes, const string& lastname, const string& firstname){
    familes[lastname].push_back(firstname);
}
int main(){
    map<string, vector<string>> families;

    add_family(families, "Zhang");
    add_child(families, "Zhang", "a");
    add_child(families, "Zhang", "b");
    add_child(families, "Zhang", "c");
    add_family(families, "Wang");

    for(auto f:families){
        cout<<f.first<<": ";
        for(auto str : f.second){
            cout<<str<<' ';
        }
        cout<<endl;
    }
    return 0;
}