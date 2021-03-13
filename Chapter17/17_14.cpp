#include<iostream>
#include<regex>
using namespace std;

int main(){
    try{
        //regex r("[[:alnum:]+\\.(cpp|cxx|cc)$", regex::icase);
        //regex r("[z-a]");
        regex r("**(a");
    }catch(regex_error e)
    {cout<<e.what()<<"\ncode: "<<e.code()<<endl;}
    return 0;
}