#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> v = {1,2,3,4,5,6};
    for(auto it=v.end()-1; it>=v.begin(); it--){
        cout<<*it<<' ';
    }
    cout<<endl;
    return 0;
}