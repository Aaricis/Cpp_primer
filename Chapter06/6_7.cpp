#include<iostream>
using namespace std;

int fun(){
    static int x=0;
    return x++;
}
int main(){
    cout<<fun()<<endl;
    cout<<fun()<<endl;
    cout<<fun()<<endl;
    return 0;
}