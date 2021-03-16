#include<iostream>
#include<random>
using namespace std;

unsigned int getRandom(){
    static default_random_engine e;
    static uniform_int_distribution<unsigned int> u(0,20);
    return u(e);
}

int main(){
    for(int i=0; i<10; ++i){
        cout<<getRandom()<<endl;
    }
    return 0;
}