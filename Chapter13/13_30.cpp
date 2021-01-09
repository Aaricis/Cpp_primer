#include<iostream>
#include<string>
using namespace std;

class HasPtr{
    friend void swap(HasPtr&, HasPtr&);
    public:
        HasPtr(const string &s = string()):ps(new string(s)),i(0){}
        HasPtr(const HasPtr& arg):ps(new string(*arg.ps)), i(arg.i){}
        HasPtr& operator=(const HasPtr& arg){
            string *temp = new string(*arg.ps);
            delete ps;
            ps = temp;
            i = arg.i;
            return *this;
        }
        ~HasPtr() { delete ps;}
    private:
        string *ps;
        int i;
};

inline
void swap(HasPtr &lhs, HasPtr &rhs){
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
    cout << "call swap(HasPtr& lhs, HasPtr& rhs)" <<endl;
}

int main(){
    HasPtr h1("Hello"), h2("World");
    swap(h1, h2);
    return 0;
}