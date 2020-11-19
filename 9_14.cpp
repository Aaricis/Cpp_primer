#include<iostream>
#include<list>
#include<vector>
using namespace std;

int main(){
    list<const char*> strs={"fdf", "greg", "fewr"};
    vector<string> v;
    v.assign(strs.begin(), strs.end());
    for(string t:v){
        cout<<t<<endl;
    }
    return 0;
}