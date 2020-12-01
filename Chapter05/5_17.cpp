#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> v1{0, 1, 1, 2};
    vector<int> v2{0, 1, 1, 2, 3, 5, 8};
    auto size = v1.size()<v2.size()? v1.size():v2.size();
    bool prefix = true;
    for(decltype(v1.size()) i=0; i<size; i++){
        if(v1[i]!=v2[i]){
            prefix = false;
            break;
        }
    }
    cout<<prefix<<endl;
    return 0;
}