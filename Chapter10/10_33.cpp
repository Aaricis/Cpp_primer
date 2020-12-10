#include<iostream>
#include<iterator>
#include<fstream>
using namespace std;

int main(int argc, char *argv[]){
    ifstream in(argv[1]); //"input.txt"
    ofstream outOdd(argv[2]), outEven(argv[3]); //"odd.txt", "even.txt"
    istream_iterator<int> int_it(in), eof;
    ostream_iterator<int> out_odd(outOdd, " "), out_even(outEven, "\n");
    while(int_it!=eof){
        if(*int_it % 2 == 1) out_odd = *int_it++;
        else out_even = *int_it++;
    }
    return 0;
}