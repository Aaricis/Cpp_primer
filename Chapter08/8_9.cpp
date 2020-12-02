#include<iostream>
#include<sstream>
#include<string>
using namespace std;

istream& input(istream& is){
    string word;
    while(is>>word){
        cout<<word<<endl;
    }
    is.clear();
    return is;
}

int main(){
    string s = "hello world";
	istringstream iss(s);
    input(iss);
    return 0;
}