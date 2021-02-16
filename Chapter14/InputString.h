#ifndef INPUTSTRING_H
#define INPUTSTRING_H

#include<iostream>
#include<string>
using namespace std;

class InputString{
public:
    InputString(istream &in=cin) : is(in){}
    string operator()()const {
        string str;
        getline(is, str);
        return is? str:string();
    }
private:
    istream &is;
    char sep;
};
#endif