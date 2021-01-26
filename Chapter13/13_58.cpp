#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Foo{
public:
    Foo sorted() &&;
    Foo sorted() const &;

private:
    vector<int> data;
};

Foo Foo::sorted() &&{
    sort(data.begin(), data.end());
    return *this;
}

/* Foo Foo::sorted() const &{
    Foo ret(*this);
    sort(ret.begin(), ret.end());
    return ret;
} */

/* Foo Foo::sorted() const &{
    Foo ret(*this);
    cout<<"13.56"<<endl;
    return ret.sorted();
} */

Foo Foo::sorted() const &{
    cout<<"13.57"<<endl;
    return Foo(*this).sorted();
} 

int main(){
    Foo f;
    f.sorted();
    return 0;
}