#include<iostream>
using namespace std;

int main(){
     string str, word="";
    int cnt=0;
    while(cin>>str){
        if(islower(str[0]))
            continue;
        if(str==word){
            cnt++;
            if(cnt==2)
                break;
        }
        else{
            cnt=1;
        }
        word = str;
    }
    if(cnt==2) cout<<word<<endl;
    else cout<<"No"<<endl;
    return 0;
}