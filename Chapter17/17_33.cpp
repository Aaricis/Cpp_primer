#include<iostream>
#include<map>
#include<fstream>
#include<sstream>
#include<string>
#include<random>
#include<vector>
using namespace std;

map<string, vector<string>> buildMap(ifstream &map_file){
    map<string, vector<string>> trans_map;
    string key;
    string value;
    while(map_file>>key && getline(map_file, value)){
        if(value.size()>1)
            trans_map[key].push_back(value.substr(1));
        else
        {
            throw runtime_error("no rule for " + key);
        } 
    }
    return trans_map;
}

const string& transform(const string &s, const map<string, vector<string>> &m){
    auto map_it = m.find(s);
    static default_random_engine e;
    if(map_it != m.cend()){
        if(map_it->second.size()==1)
            return map_it->second[0];
        else{
            uniform_int_distribution<unsigned> u(0, map_it->second.size()-1);
            return map_it->second[u(e)];
        }
    }
    else
        return s;   
}

void word_transform(ifstream &map_file, ifstream &input){
    auto trans_map = buildMap(map_file);
    string text;
    while(getline(input, text)){
        istringstream stream(text);
        string word;
        bool firstword = true;
        while(stream >> word){
            if(firstword)
                firstword = false;
            else cout<<" ";
            cout<<transform(word, trans_map);
        }
        cout<<endl;
    }
}

int main(){
    ifstream rules("Rules.txt"), input("text.txt");
    word_transform(rules, input);
    return 0;
}

