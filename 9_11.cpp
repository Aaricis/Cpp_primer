#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> v1; //空
    vector<int> v2 = {1,2,3,4,5};//列表初始化
    vector<int> v3(v2);//v3初始化为v2的拷贝
    vector<int> v4(v2.begin(), v2.end());//v4初始化为迭代器所指范围内的元素
    vector<int> v5(3);//{0, 0, 0}
    vector<int> v6(3,4);//{4, 4, 4}
    return 0;
}