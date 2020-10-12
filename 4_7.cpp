#include<iostream>
using namespace std;

int main(){
    short short_value = 32767;
    short_value += 1;
    cout<<short_value<<endl;

    char c_value = 127;
    c_value += 1;
    cout<<c_value<<endl;

    unsigned un_val = 0;
    un_val -= 1;
    cout<<un_val<<endl;
    
    return 0;
}