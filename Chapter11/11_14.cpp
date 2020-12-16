#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<utility>
using namespace std;

void add_family(map<string, vector<pair<string, string>>>& families, const string& lastname){
    if(families.find(lastname)==families.end()){
        families[lastname] = vector<pair<string, string>>();
    }
}

void add_child(map<string, vector<pair<string, string>>>& familes, const string& lastname, const pair<string, string>& firstname){
    familes[lastname].push_back(firstname);
}
int main(){
    map<string, vector<pair<string, string>>> families;

    add_family(families, "Zhang");
    add_child(families, "Zhang", {"a", "2001-1-2"});
    add_child(families, "Zhang", {"b", "2002-3-10"});
    add_child(families, "Zhang", {"c", "2003-5-12"});
    add_family(families, "Wang");

    for(auto f:families){
        cout<<f.first<<endl;
        for(auto p : f.second){
            cout<<p.first<<' '<<p.second<<endl;
        }
    }
    return 0;
}