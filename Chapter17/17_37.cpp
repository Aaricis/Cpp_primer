#include<iostream>
#include<fstream>
using namespace std;

int main(){
    char cs[10];
    ifstream infile("test.txt");
    while(infile){
        infile.getline(cs, 9, '\n');
        cout<<"line length: "<<infile.gcount()<<endl;
    }
    return 0;
}