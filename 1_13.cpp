#include<iostream>
int main(){

  /*  int sum=0;
    for(int val=50; val<=100; val++){
        sum += val;
    }
    std::cout<<"Sum of 50 to 100 inclusive is "<<sum<<std::endl;
  */

  /*  for(int val=10; val>=0; val--){
        std::cout<<val<<std::endl;
    }
  */
    std::cout<<"Input two numbers"<<std::endl;
    int v1, v2;
    std::cin>>v1>>v2;
    for(int i=v1; i<=v2; i++){
        std::cout<<i<<std::endl;
    }

    return 0;
}