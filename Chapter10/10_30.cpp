#include<iostream>
#include<iterator>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    istream_iterator<int> in_iter(cin), eof;
    ostream_iterator<int> out_iter(cout, "\n");
    vector<int> v(in_iter, eof);
    sort(v.begin(), v.end());
    for(auto e : v){
        *out_iter++ = e;
    }
    return 0;
}