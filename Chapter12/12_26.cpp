#include<iostream>
#include<memory>
#include<string>
using namespace std;

int main(){
    allocator<string> alloc;
    auto const p = alloc.allocate(10);
    auto q = p;
    string s;
    while(q != (p+10) && cin>>s){
        alloc.construct(q++, s);
    }
    while(q!=p){
        cout<<*--q<<endl;
        alloc.destroy(q);
    }
    alloc.deallocate(p, 10);
    return 0;
}