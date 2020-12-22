#include<iostream>
#include<cstring>
using namespace std;

int main(){
    string str;
    cin>>str;
    char *p = new char[str.size()+1];
    for(int i=0; i<str.size(); i++){
        *(p+i) = str[i];
    }
    *(p+str.size()+1) = '\0';
    cout<<p<<endl;
    return 0;
}