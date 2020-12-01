#include<iostream>
using std::cout;
using std::endl;
using std::cin;
int main(){
    /*int sum=0, val=50;
    while(val<=100){
        sum += val;
        val++;
    }

    cout<<"Sum of 50 to 100 inclusive is "<<sum<<endl;*/

    /*int val = 10;
    while(val>=0){
        cout<<val<<endl;
        val--;
    }*/
    cout<<"Input two numbers"<<endl;
    int v1, v2;
    cin>>v1>>v2;
    while(v1<=v2){
        cout<<v1<<endl;
        v1++;
    }
    return 0;
}