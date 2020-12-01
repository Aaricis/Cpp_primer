#include<iostream>
#include<vector>
using namespace std;

int main(){
    int cnt=0, maxcnt=INT_MIN;
    string str, prestr="", word;
    while(cin>>str){
        if(prestr!=""){
            if(prestr==str){
                cnt++;
            }
            else{
                cnt=1;
            }
        }
       prestr = str;
        if(maxcnt<cnt){
            maxcnt = cnt;
            word = str;
        }
    }
    if(maxcnt>1){
        cout<<word<<' '<<maxcnt<<endl;
    }
    else
    {
        cout<<"No word"<<endl;
    }
    
    return 0;
}