#include<iostream>
#include<string>
#include<vector>
using namespace std;

template <typename T>
void print(T &t){
    for(typename T::size_type i=0; i<t.size(); ++i){
        cout<<t[i]<<' ';
    }
    cout<<endl;
}

int main(){
    string s = "12345";
	vector<int> v{1,2,34,4,5,32};
	print(s);
	print(v);

    return 0;
}