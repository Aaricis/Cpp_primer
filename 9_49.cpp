#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(){
    ifstream in("./words.txt");
    if(!in) return -1;
    string longestWord, word;
    while(in>>word){
        if(word.find_first_not_of("aceimnorsuvwxz")==string::npos && word.size()>longestWord.size())
            longestWord=word;
    }
    cout<<longestWord<<endl;
    return 0;
}