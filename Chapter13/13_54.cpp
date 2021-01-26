#include<iostream>
#include<string>
#include<utility>
using namespace std;

class HasPtr{
    friend void swap(HasPtr&, HasPtr&);
    public:
        HasPtr(const string &s = string()):ps(new string(s)),i(0){}
        HasPtr(const HasPtr& arg):ps(new string(*arg.ps)), i(arg.i){}
        HasPtr(HasPtr &&p) noexcept : ps(p.ps), i(p.i){p.ps = 0;}

        HasPtr& operator=(HasPtr rhs){
            swap(*this, rhs);
            return *this;        
        }

        HasPtr& operator=(HasPtr&& args) noexcept{
            if(this != &args){
                delete ps;
                ps = args.ps;
                args.ps = nullptr;
                args.i = 0;
            }
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
    h1 = h2;

    /*找不到匹配的函数，调用具有二义性*/
    //h1 = std::move(h2);
    return 0;
}