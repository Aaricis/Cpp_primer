#include<iostream>
using namespace std;

template <typename T, unsigned U> constexpr
unsigned size(const T (&arr)[U]){
    return U;
}

int main()
{
	int arr1[4] = {1,2,3,4};
	double arr2[5] = {1,2,3,45,6};
	cout << size(arr1) << " " << size(arr2) << endl;
	return 0;
}
