#include<string>
using namespace std;

class HasPtr{
    public:
        HasPtr(const string &s = string()):ps(new string(s)), i(0){}
        HasPtr(const HasPtr& arg): ps(new string(*arg.ps)), i(arg.i){}
        HasPtr& operator=(const HasPtr& arg){
            string *temp = new string(*arg.ps);
            delete ps;
            ps = temp;
            i = arg.i;
            return *this;
        }
        ~HasPtr(){
            delete ps;
        }
    private:
        string *ps;
        int i;
};