#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

int main(){
    vector<string> v;
    ifstream in("./infile.txt");
    string word;
    while(in>>word){
        v.push_back(word);
    }
    in.close();
    for(string str:v){
        cout<<str<<endl;
    }
    return 0;
}