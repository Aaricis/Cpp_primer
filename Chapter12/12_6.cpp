#include<iostream>
#include<vector>
#include<new>
using namespace std;

vector<int>* makeDynamic(){
    return new vector<int>;
}

void print(vector<int> *p){
    for(int &x : *p){
        cout<<x<<' ';
    }
    delete p;
    p = nullptr;
}

void input(istream& is, vector<int> *p){
    int x;
    while(is>>x){
        p->push_back(x);
    }
    print(p);
}

int main(){
    vector<int> *p = makeDynamic();
    input(cin, p);
    return 0;
}