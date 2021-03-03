#include<iostream>
using namespace std;

template<typename T, unsigned N>
T *begin(const T (&arr)[N]){
    return &arr[0];
}

template<typename T, unsigned N>
T *end(const T (&arr)[N]){
    return &arr[N];
}

int main()
{
	int arr1[4] = {1,2,3,4};
	double arr2[5] = {1,2,3,45,6};
	for(int * p = begin(arr1); p != end(arr1); ++p)
		cout << *p << " ";
	cout << endl;
	for(double * p = begin(arr2); p != end(arr2); ++p)
	    cout << *p << " ";
	cout << endl;
	return 0;
}
