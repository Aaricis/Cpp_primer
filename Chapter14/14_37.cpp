#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class isEqual{
private:
    int val;

public:
    isEqual(int v):val(v){}

    bool operator()(int x){
        return x==val;
    }
};

int main(){
    vector<int> vec = { 3, 2, 1, 4, 3, 7, 8, 6 };
    replace_if(vec.begin(), vec.end(), isEqual(3), 5);
    for (int i : vec) cout << i << " ";
    return 0;
}