#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;

int main(){
    ifstream input("infile.txt");
    string line;
    vector<string> str;
    while(getline(input, line)){
        str.push_back(line);
    }

    string word;
    for(string s : str){
        istringstream is(s);
        while(is>>word){
            cout<<word<<endl;
        }
    }
    return 0;
}