#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> iv={1, 2, 2, 2, 3, 4};
    for(int x:iv){
        cout<<x<<' ';
    }
    cout<<endl;

    vector<int>::iterator iter = iv.begin(), mid = iv.begin()+iv.size()/2;
    while(iter!=mid){
        if(*iter==2){
            iter = iv.insert(iter, 4);
            mid = iv.begin()+iv.size()/2 + 1;
            iter++;
        }
        iter++;
    }
    for(int x:iv){
        cout<<x<<' ';
    }  
    return 0;
}