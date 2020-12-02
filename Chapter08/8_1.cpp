#include<iostream>
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
    input(cin);
    return 0;
}