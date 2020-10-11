#include<iostream>
#include<vector>
using namespace std;

int main(){
    int arr[]={1,2,3};
    vector<int> nums(begin(arr), end(arr));
    for(auto i : nums){
        cout<<i<<' ';
    }
    return 0;
}
