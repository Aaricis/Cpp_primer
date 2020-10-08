#include<iostream>
using namespace std;

int main(){
    string s("a,b!c~srf/");
    for(auto c:s){
        if(!ispunct(c))
            cout<<c;
    }
    cout<<endl;
    return 0;
}