#include<string>
using namespace std;

class HasPtr{
    public:
        HasPtr(const string &s = string()):ps(new string(s)), i(0){}
        HasPtr(const HasPtr& arg): ps(new string(*arg.ps)), i(arg.i){}
        HasPtr(HasPtr &&p) noexcept : ps(p.ps), i(p.i){p.ps = 0;}
        HasPtr& operator=(const HasPtr& arg){
            string *temp = new string(*arg.ps);
            delete ps;
            ps = temp;
            i = arg.i;
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

    private:
        string *ps;
        int i;
};