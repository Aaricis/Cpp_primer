#include<iostream>
using namespace std;

int main(){
    int x, y;
    while(cin>>x>>y){
        try{
            if(y==0){
            throw runtime_error("second number can not equal 0");
            }
            cout<<x/y<<endl;
        }catch(runtime_error err){
            cout<<err.what()<<"\nTry Again? Enter y or n"<<endl;
            char c;
            cin>>c;
            if(!cin || c=='n')
                break;
        }
        
    }
    return 0;
}