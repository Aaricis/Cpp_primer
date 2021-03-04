#include<iostream>
#include<string>
#include<vector>
using namespace std;

template <typename T>
void print(T &t){
    for(typename T::iterator it = t.begin(); it != t.end(); ++it){
        cout<<*it<<' ';
    }
    cout<<endl;
}

int main()
{
	string s = "12345";
	vector<int> v{1,2,34,4,5,32};
	print(s);
	print(v);
	return 0;
}

