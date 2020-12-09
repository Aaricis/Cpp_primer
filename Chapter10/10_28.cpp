#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
using namespace std;

int main(){
    vector<int> v={1,2,3,4,5,6,7,8,9};
    list<int> l1, l2, l3;
    copy(v.begin(), v.end(), back_inserter(l1));
     for(int x : l1){
        cout<<x<<' ';
    }
    cout<<endl;

    copy(v.begin(), v.end(), front_inserter(l2));
     for(int x : l2){
        cout<<x<<' ';
    }
    cout<<endl;

    copy(v.begin(), v.end(), inserter(l3, l3.begin()));
     for(int x : l3){
        cout<<x<<' ';
    }
    cout<<endl;
    return 0;
}