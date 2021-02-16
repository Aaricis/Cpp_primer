#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<sstream>
#include<algorithm>
using namespace std;

class isEqual{
public:
    isEqual(size_t n):sz(n){}
    bool operator()(const string &s){
        return s.length()==sz;
    }
private:
    size_t sz;
};
int main(){
    ifstream input("./infile.txt");
    vector<string> vec;
    string str, t;
    while(getline(input, str)){
        istringstream is(str);
        while(is>>t){
            vec.push_back(t);
        }
    }
    for(int i=1; i<=10; ++i){
        isEqual e(i);
        cout<<i<<' '<<count_if(vec.begin(), vec.end(), e)<<endl;
    }
    
    return 0;
}