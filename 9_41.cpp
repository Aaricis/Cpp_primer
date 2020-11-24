#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<char> v = {'a', 's', 'y','u'};
    string s(v.begin(), v.end());
    cout<<s;
    return 0;
}