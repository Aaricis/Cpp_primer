#include<iostream>
#include<random>
using namespace std;

unsigned int getRandom(unsigned int s){
    static default_random_engine e(s);
    static uniform_int_distribution<unsigned int> u(0,20);
    return u(e);
}

int main(){
    for(int i=0; i<10; ++i){
        cout<<getRandom(100)<<endl;
    }
    return 0;
}