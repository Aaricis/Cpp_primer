#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int main(){
    /*string s="aaa", t="bbb";
    cout<<(s==t);*/
    //char s[]={'a','a','a','\0'};
    //char t[]={'b','b','b','\0'};
    const char s[] = "aaa";
    const char t[] = "bbb";
    cout<<strcmp(s,t);

    return 0;
}