#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<fstream>
#include<sstream>
#include<algorithm>   

using std::ifstream;
using std::vector;
using std::string;
using std::map;
using std::set;
using std::istringstream;

int main(){
    ifstream file("text.txt");
    vector<string> input;
    map<string, set<int>> mp;
    int lineNo = 0;
    for(string line; getline(file, line); ++lineNo){
        input.push_back(line);
        istringstream is(line);
        for(string text, word; is>>text; word.clear()){
            std::remove_copy_if(text.begin(), text.end(), std::back_inserter(word), ispunct);
            mp[word].insert(lineNo);
        }
    }

    do{
        std::cout<<"enter word to look for, or q to quit: ";
        string s;
        if(!(std::cin>>s) || s=="q") break;
        auto found = mp.find(s);
        if(found!=mp.end()){
            std::cout<<s<<" occurs "<<found->second.size()<<(found->second.size()>1? " times":"time")<<std::endl;
            for(auto i : found->second){
                std::cout<<"\t(line " << i+1 << ") "<<input[i]<<std::endl;
            }
        }
        else{
            std::cout << s << " occurs 0 time" <<std::endl;
        }  
    }while(true);
    
    return 0;
}