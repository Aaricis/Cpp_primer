#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> v5{10,42};
    for(auto it=v5.cbegin(); it!=v5.cend(); it++){
        cout<<*it<<endl;
    }
    return 0;
}