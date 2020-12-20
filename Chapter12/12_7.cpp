#include<iostream>
#include<vector>
#include<memory>
using namespace std;

shared_ptr<vector<int>> makeDynamic(){
    return make_shared<vector<int>>();
}

void print(shared_ptr<vector<int>> p){
    for(int &x : *p){
        cout<<x<<' ';
    }
}

void input(istream& is, shared_ptr<vector<int>> p){
    int x;
    while(is>>x){
        p->push_back(x);
    }
    print(p);
}

int main(){
    shared_ptr<vector<int>> p = makeDynamic();
    input(cin, p);
    return 0;
}