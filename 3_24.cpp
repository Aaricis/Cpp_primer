#include<iostream>
#include<vector>
using namespace std;

int main(){
    int x;
    vector<int> v;
    while(cin>>x){
        v.push_back(x);
    }

    /*for(auto it=v.begin(); it!=v.end()-1; it++){
        cout<<*it+*(it+1)<<endl;
    }*/

    auto beg = v.cbegin();
    auto end = v.cend()-1;
    while(beg<end){
        cout<<*beg+*end<<endl;
        beg++;
        end--;
    }
    return 0;
}