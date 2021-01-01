#include<iostream>
#include<vector>
using namespace std;

struct X{
    X() {cout<<"X()"<<endl;}
    X(const X&){ cout<<"X(const X&)"<<endl;}
    X& operator=(const X&){
        cout<<"X& operator=(const X&)"<<endl;
        return *this;
    }
    ~X(){
        cout<<"~X()"<<endl;
    }
};

void f1(X x){

}

void f2(X &x){

}

int main(){
    X x;//X()
    f1(x);//X(const x&), ~X()
    f2(x);
    X *px = new X;//X()

    vector<X> v;
    v.push_back(x);//X(const X&)

    delete px;//~X()

    X y;//X()
    y=x;//X& operator=(const X&)

    return 0;
}