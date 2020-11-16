#include<iostream>
#include<vector>
#include<list>
using namespace std;

int main(){
    list<int> l={1,2,3};
    vector<double> v(l.begin(), l.end());
    vector<int> vi={4,5,6};
    vector<double> v1(vi.begin(), vi.end());

    for(double x : v){
        cout<<x<<' ';
    }
    cout<<endl;

    for(double x:v1){
        cout<<x<<' ';
    }
    return 0;
}