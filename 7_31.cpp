#include<iostream>
using namespace std;

class X;
class Y;
class X{
    Y* y;
};
class Y{
    X x;
};
int main(){
    return 0;
}