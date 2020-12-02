#include<iostream>
using namespace std;

class NoDefault{
private:
    int val;
public: 
    NoDefault(int x):val(x){}
};

class C{
private:
    NoDefault celement;
public:
    C():celement(0){
        cout<<"C default"<<endl;
    }
};

int main(){
    C c;
    return 0;
}