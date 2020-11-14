#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

int main(){
    vector<string> v;
    ifstream in("./infile.txt");
    string line;
    while(getline(in, line)){
        v.push_back(line);
    }
    in.close();
    for(string s:v){
        cout<<s<<endl;
    }
    return 0;
}