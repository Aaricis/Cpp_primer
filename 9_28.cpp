#include<iostream>
#include<forward_list>
#include<string>
using namespace std;

forward_list<string> insertString(forward_list<string> flst, string s, string t){
    auto prev = flst.before_begin();
    forward_list<string>:: iterator it;
    for(it=flst.begin(); it!=flst.end(); it++){
        if(*it==s){
            flst.insert_after(it, t);
            return flst;
        }
        else{
            prev=it;
        }
    }
    flst.insert_after(prev, t);
    return flst;

}

int main(){
    forward_list<string> flst={"a", "b","d","e"};
    forward_list<string> f1=insertString(flst, "b", "c" );
    for(string str:f1){
        cout<<str<<' ';
    }
    cout<<endl;
    forward_list<string> f2=insertString(flst, "f", "x" );
    for(string str:f2){
        cout<<str<<' ';
    }
    return 0;
}