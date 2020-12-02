#include<iostream>
#include<list>
#include<forward_list>
#include<string>
using namespace std;

int main(){
    list<int> l={0,1,2,3,4,5,6,7,8,9};
    auto iter=l.begin();
    while(iter!=l.end()){
        if(*iter%2){
            iter = l.insert(iter, *iter);
            iter++;
            iter++;
        }
        else{
            iter = l.erase(iter);
        }
    }
    for(int x:l){
        cout<<x<<' ';
    }
    cout<<endl;

    forward_list<int> f={0,1,2,3,4,5,6,7,8,9};
    auto prev = f.before_begin();
    auto cur = f.begin();
    while(cur != f.end()){
        if(*cur%2){
            cur = f.insert_after(cur, *cur);
            prev = cur;
            cur++;
        }
        else{
            cur = f.erase_after(prev);

        }
    }
    for (cur = f.begin(); cur != f.end(); cur++){
		cout << *cur << " ";
	}
    return 0;
}