#include<iostream>
#include<vector>
using namespace std;

void print(vector<int>& arr, int i, int n){
    if(i<n) {
        cout<<arr[i]<<endl;
        print(arr, i+1, n);
    }
    return;
}

int main(){
    vector<int> arr={1,2,3};
    print(arr, 0, arr.size());
    return 0;
}