#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    vector<int> nums;
    int x;
    while(cin>>x){
        nums.push_back(x);
    }
    cout<<count(nums.begin(), nums.end(), 1)<<endl;
    return 0;
}