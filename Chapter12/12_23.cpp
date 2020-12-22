#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int main(){
    char *p = new char [strlen("hello " "world") + 1]();
    strcat(p, "hello "); //追加字符串
    strcat(p, "world");
    cout<<p<<endl;
    delete [] p;

    string s1 = "hello ", s2 = "world";
    cout<<s1+s2<<endl;
    
    return 0;
}