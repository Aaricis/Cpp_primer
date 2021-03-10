#include<iostream>
using namespace std;

template <typename T>
ostream &print(ostream &os, const T &t){
    return os<<t;
} 

template <typename T, typename... Args>
ostream &print(ostream &os, const T &t, const Args&... rest){
    os<<t<<", ";
    return print(os, rest...);
}

/* template <typename T>
ostream &print(ostream &os, const T &t){
    return os<<t;
} */

int main(){
    print(cout, 1) << endl;
	print(cout, 1, "123") << endl;
	print(cout, 1, "123", 3.123, string("qwert"), -5) <<endl;
	return 0;
}