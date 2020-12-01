#include<iostream>
#include<vector>
using namespace std;

#define NDEBUG
void print(vector<int>& arr, int i, int n){
    if(i<n){
        cout<<arr[i]<<endl;
        #ifndef NDEBUG
        cout<<n-i<<endl;
        #endif
        print(arr, i+1, n);
    }
}

int main(){
    vector<int> arr={1,2,3};
    print(arr, 0, arr.size());
    return 0;
}