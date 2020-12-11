#include<iostream>
#include<algorithm>
#include<list>
using namespace std;

int main(){
    list<int> l = {0, 1, 2, 0, 0, 3};
    auto last = find(l.crbegin(), l.crend(), 0);
    cout<<*(--last.base())<<endl;
    return 0;
}