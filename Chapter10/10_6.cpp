#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    vector<int> nums={1,2,3};
    for(int x:nums){
        cout<<x<<' ';
    }
    cout<<endl;

    fill_n(nums.begin(), nums.size(), 0);
    for(int x:nums){
        cout<<x<<' ';
    }
    cout<<endl;

    return 0;
}