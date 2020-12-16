#include<iostream>
#include<map>
#include<list>
#include<fstream>
#include<sstream>
using namespace std;

int main(){
    map<string, list<int>> wordLine;
    ifstream input("words.txt");
    string line;
    int no=1;
    while(getline(input, line)){
        istringstream iss(line);
        string word;
        while(iss>>word){
            wordLine[word].push_back(no);
        }
        no++;
    }

    for(auto it=wordLine.begin(); it!=wordLine.end(); it++){
        cout<<it->first<<' ';
        for(int i:it->second){
            cout<<i<<",";
        }
        cout<<endl;
    }
    return 0;
}