#include<iostream>
#include<random>
using namespace std;

unsigned int getRandom(unsigned int s, unsigned int min, unsigned int max){
    static default_random_engine e(s);
    static uniform_int_distribution<unsigned int> u(min,max);
    return u(e);
}

int main(){
    for(int i=0; i<10; ++i){
        cout<<getRandom(100, 0, 50)<<endl;
    }
    return 0;
}