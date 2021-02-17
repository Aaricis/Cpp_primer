#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;

class isEqual{
public:
    isEqual(size_t _low, size_t _high):low(_low), high(_high){}
    bool operator()(const string &s){
        return (s.length()>=low) && (s.length()<=high);
    }
private:
    size_t low;
    size_t high;
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
    isEqual e1(1, 9);
    cout<<"1-9 "<<count_if(vec.begin(), vec.end(), e1)<<endl;
    isEqual e2(10, 100);
    cout<<">=10 "<<count_if(vec.begin(), vec.end(), e2)<<endl;
    return 0;
}