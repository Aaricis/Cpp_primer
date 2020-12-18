#include<iostream>
#include<unordered_map>
#include<string>
#include<fstream>
#include<sstream>
using namespace std;

unordered_map<string, string> buildMap(ifstream &map_file){
    unordered_map<string, string> trans_map;
    string key;
    string value;
    while(map_file>>key && getline(map_file, value)){
        if(value.size()>1)
            trans_map[key] = value.substr(1);
        else
        {
            throw runtime_error("no rule for " + key);
        } 
    }
    return trans_map;
}

const string& transform(const string &s, const unordered_map<string, string> &m){
    auto map_it = m.find(s);
    if(map_it != m.cend())
        return map_it->second;
    else
    {
        return s;
    }
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
    unordered_map<string, size_t> wordCount;
    string word;
    while(cin>>word){
        ++wordCount[word];
    }

    for(const auto &w : wordCount){
        cout<<w.first<<" occurs "<<w.second<<((w.second>1)? " times":" time")<<endl;
    }

    ifstream rules("Rules.txt"), input("text.txt");
    word_transform(rules, input);
    return 0;
}