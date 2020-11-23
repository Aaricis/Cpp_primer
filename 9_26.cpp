#include<iostream>
#include<vector>
#include<list>
using namespace std;

int main(){
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    vector<int> v(begin(ia), end(ia));
    list<int> l(begin(ia), end(ia));

    cout<<"v";
    for(int x : v){
        cout<<x<<' ';
    }
    cout<<endl;
    auto it = v.begin();
    while(it != v.end()){
        if(*it%2==0)
            it = v.erase(it);
        else
        {
            it++;
        }   
    }
    cout<<"v";
    for(int x : v){
        cout<<x<<' ';
    }
    cout<<endl;

    cout<<"l";
    for(int x : l){
        cout<<x<<' ';
    }
    cout<<endl;

    auto lt = l.begin();
    while(lt != l.end()){
        if(*lt%2==1)
            lt = l.erase(lt);
        else
        {
            lt++;
        } 
    }
    cout<<"l";
    for(int x : l){
        cout<<x<<' ';
    }
    cout<<endl;
    return 0;
}