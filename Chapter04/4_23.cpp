#include<iostream>
using namespace std;

int main(){
    int grade = 91;
    string finalgrade = ((grade>90)? "high pass": (grade<60))? "fail" : "pass";
    return 0;
}