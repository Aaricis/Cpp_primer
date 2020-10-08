#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<string> text = {"Hello World!", "", "Hi There!"};
    for(auto it=text.begin(); it!=text.end()&& !it->empty(); it++){
        for(auto c=it->begin(); c!=it->end(); c++){
            *c = toupper(*c);
        }
        cout<<*it<<endl;
    }
    return 0;
}