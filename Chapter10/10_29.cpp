#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<iterator>
using namespace std;

int main(){
    ifstream in("afile.txt");
    istream_iterator<string> str_it(in), eof;
    vector<string> v(str_it, eof);
    for(string s : v){
        cout<<s<<' ';
    }
    cout<<endl;
    return 0;
}