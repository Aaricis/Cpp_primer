#include<iostream>
#include<vector>
#include<string>
#include<cstring>
using namespace std;

template <typename T>
size_t vectorFind(const vector<T>& v, const T &t){
    size_t x = 0;
    for(auto it = v.begin(); it!=v.end(); ++it){
        if(*it==t){
            ++x;
        }
    }
    return x;
}

template <>
size_t vectorFind(const vector<const char*>& v, const char* const &t){
    size_t x = 0;
	for(auto p = v.cbegin(); p != v.cend(); ++p)
		if(strcmp(*p, t) == 0)
			++x;
	return x;

} 

int main(){
    vector<double> vd{1.0, 2.3, 3.5, 2.3};
	cout << vectorFind(vd, 2.3) << endl;
	vector<int> vi{1, 2, 3, 2};
	cout << vectorFind(vi, 2) << endl;
	vector<string> vs{"1.0", "2.3", "3.5", "2.3"};
	cout << vectorFind(vs, string("2.3")) <<endl;


    const char * p = "2.3";
	vector<const char *> vc{"1.0", "2.3", "3.5", "2.3"};
	cout << vectorFind(vc, p) << endl;

    return 0;
}