#include<iostream>
using namespace std;

int main(){
    int nums[] = {1,2,3};
    /*int *p = nums;
    for(int i=0; i<3; i++){
        *(p+i) = 0;
    }*/
    int *b=begin(nums), *e=end(nums);
    while(b<e){
        *b = 0;
        b++;
    }
    for(auto i : nums){
        cout<<i<<' ';
    }
    return 0;
}