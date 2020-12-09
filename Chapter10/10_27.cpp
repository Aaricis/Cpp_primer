#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;

int main(){
    vector<int> v = {1,2,2,2,3,4,4,5,6};
    list<int> l;
    unique_copy(v.begin(), v.end(), back_inserter(l));
    for(int x : l){
        cout<<x<<' ';
    }
    cout<<endl;
    return 0;
}