#include<iostream>
int main(){
    std::cout<<"Input two numbers"<<std::endl;
    int v1, v2;
    std::cin>>v1>>v2;
    while(v1<=v2){
        std::cout<<v1<<std::endl;
        v1++;
    }
    return 0;
}