#include<iostream>
#include<vector>
#include<list>
using namespace std;

template <typename T, typename U>
T find(T first, T last, const U &x){
    while(first!=last){
        if(*first==x) return first;
        else ++first;
    }
    return last;
}

int main(){
    vector<int> v1{1,2,34,5,66,77,56457,436,2,523,6,235};
	list<int> l1{1,2,34,5,66,77,56457,436,2,523,6,235};
    cout << *find(v1.begin(), v1.end(), 6) << endl;
	cout << *find(l1.cbegin(), l1.cend(), 6) << endl;
    return 0;
}