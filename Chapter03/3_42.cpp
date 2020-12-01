#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> nums{1,2,3};
    size_t sz = nums.size();
    int arr[sz];
    for(int i=0; i<sz; i++){
        arr[i] = nums[i];
    }
    for(int i=0; i<sz; i++){
        cout<<arr[i]<<' ';
    }
    return 0;
}