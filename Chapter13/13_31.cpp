#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
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
        bool operator<(const HasPtr& t){
            return *ps<*t.ps;
        }

        void show(){
            cout<<*ps<<' ';
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
    /* when the number of elements more than 16, swap() will be called */
    HasPtr a("a"), b("b"), c("c"), h("h"), s("s"), d("d"), i("i"), e("e"), p("p"), o("o"), u("u"), k("k"), q("q"), z("z"), j("j"), g("g"), x("x");
    vector<HasPtr> v={c, b, a, h, s, d, i, e, p, o, u, x, k, q, z, j, g};
    sort(v.begin(), v.end());
    for(HasPtr& hp : v){
        hp.show();
    }
    return 0;
}