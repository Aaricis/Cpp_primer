#include<iostream>
#include<cstring>
using namespace std;

int main(){
    char s[] = "Hello";
    char t[] = "world!";
    //sizeof()计算的长度包含'\0'
    constexpr size_t sz = sizeof(s)+sizeof(t);
    char r[sz];
    strcpy(r,s);
    strcat(r," ");
    strcat(r,t);
    cout<<r;
    return 0;
}