#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
    vector<string> nums={"100", "1000", "10"};
    int res=0;
    for(string s : nums){
        res += stoi(s);
    }
    cout<<res<<endl;

    vector<string> dnums={"1.1", "1.2", "1.3"};
    double ans=0;
    for(string s : dnums){
        ans += stod(s);
    }
    cout<<ans<<endl;
    return 0;
}