#include<iostream>
#include<fstream>
#include"StrBlobPtr.h"
using namespace std;


int main(){
    ifstream in("input.txt");
    StrBlob b;
    string str;
    while(getline(in, str)){
        b.push_back(str);
    }
    for(auto iter=b.begin();;iter.incr()){
        cout<<iter.deref()<<endl;
    }
    return 0;
}