#include<iostream>
using namespace std;

template <typename T, unsigned N>
void print(const T (&arr)[N]){
    for(auto elem : arr){
        cout<<elem<<endl;
    }
}

int main(){
	int arr1[4] = {1,2,3,4};
	double arr2[5] = {1,2,3,45,6};
	print(arr1);
	print(arr2); 
	return 0;
}
