#include<iostream>
#include<algorithm>
#include<list>
#include<vector>
using namespace std;

int main(){
    vector<int> v = {1,2,3,4,5,6,7,8,9,10};
    list<int> l(v.rbegin()+3, v.rbegin()+8);
    for(int x : l){
        cout<<x<<' ';
    }
    cout<<endl;
    return 0;
}