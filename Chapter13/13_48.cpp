#include<iostream>
#include"13_44.h"
#include<vector>
using namespace std;

void foo(String x)
{
    cout<<x.c_str() <<endl;
}

void bar(const String& x)
{
    cout<<x.c_str()<<endl;
}

String baz()
{
    String ret("world");
    return ret;
}

int main(){
    char text[] = "world";

    String s0;
    String s1("hello");
    String s2(s0); //触发拷贝构造函数
    String s3 = s1; //初始化s3，所以触发拷贝构造函数
    String s4(text);
    s2 = s1; //触发拷贝赋值运算符，将s1赋值给s2

    foo(s1);
    bar(s1);
    foo("temporary");
    bar("temporary");
    String s5 = baz();


    vector<String> svec;
    svec.reserve(8);
    //push_back()触发拷贝构造函数
    svec.push_back(s0);
    svec.push_back(s1);
    svec.push_back(s2);
    svec.push_back(s3);
    svec.push_back(s4);
    svec.push_back(s5);
    svec.push_back(baz());
    svec.push_back("good job");

    for (const auto &s : svec) {
        cout<<s.c_str()<< endl;
    } 
    return 0;
}